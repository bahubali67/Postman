/*
 * main.c
 *
 * Created: 2/1/2019 9:35:19 PM
 *  Author: Bahubali
 */ 
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <avr/wdt.h> 
#include <avr/eeprom.h>
#include <avr/interrupt.h>

#define MOTORCOUNTADDRESS			0x10
#define TODAYSMOTORSTATUSADDRESS	0x20

#define RELAY1_ON		PORTB |= 0x01
#define RELAY1_OFF		PORTB &= ~0x01

#define BUZZER_ON		PORTB |= 0x02
#define BUZZER_OFF		PORTB &= ~0x02


/************************Make changes here for final release************************************************/
#define DELTA			 0x03 //make it 3 for final release
#define STARTSTOPMINUTE  55 //5 //motor turn on time(min)
#define STARTSTOPHOUR    13 //8 //motor turn on time(hr)
#define MOTORSCHEDULE	TURNONMOTORONCEIN2DAY//TURNONMOTOREVERYDAY// TURNONMOTORONCEIN2DAY
/**********************************************************************************************************/

#define TURNONMOTOREVERYDAY		((rtcDec.date % 1) == 0)
#define TURNONMOTORONCEIN2DAY	((rtcDec.date % 2) == 0)
#define TURNONMOTORONCEIN3DAY	((rtcDec.date % 3) == 0)



#define RESETDAY			1
#define RESETHOUR			1
#define RESETMINUTE			0
#define RESETSECOND			2

char intCount = 0;
rtc_t rtcDec;
//Interrupt Service Routine for INT0
ISR(INT0_vect)
{
	_delay_ms(500); // Software debouncing control
	PORTB ^= 0x04;//torn on/off each time button pressed(testing purpose)
	intCount++;
}
void gpioIntInit()
{
	GICR = 1<<INT0;					// Enable INT0
	MCUCR = 0<<ISC01 | 0<<ISC00;	// Trigger INT0 on rising edge
}
/*char bcdToDec(char val)
{
	return( (val/16*10) + (val%16) );
}
char decToBcd(char val)
{
	return( (val/10*16) + (val%10) );
}*/
int main()
{
	wdt_disable();
	DDRC = 0XC0;   //RS and EN
	DDRA = 0XFF;   //Whole port as LCD data lines
	DDRB = 0x07; // PB0 and PB1 as LED and Relay pins,PB2 as buzzer pin
	DDRD = 0x00;	//input for selecting ON time delay
	PORTD = 0xFF; //pull up the portd
	
	BUZZER_OFF;
	RELAY1_OFF;
		
	char time[15];
	char date[15];

	lcd_init(); 			//LCD Port Initializations.
	i2c_init();
	rtc_init();
	lcd_clr();
	gpioIntInit();
	sei();				//Enable Global Interrupt


	/*******use this only to set time and date**********/
	//rtc_set_time();
	//rtc_set_date();
	/***************************************************/
	//check_wdt();
	/*******testing purpose,comment it**********/
	//temp_func();
	//clear_ON_TIME();
	/***************************************************/

	
	unsigned char startHr  = STARTSTOPHOUR;
	unsigned char stopHr   = STARTSTOPHOUR;
	unsigned char startMin = STARTSTOPMINUTE;
	unsigned char stopMin  = STARTSTOPMINUTE + DELTA;
	unsigned char motorOnCount = 0;
	unsigned char relayON, IsMototTurnedOnToday=0;

	//comment these
	//eeprom_write_byte((uint8_t*)MOTORCOUNTADDRESS,0);
	//eeprom_write_byte((uint8_t*)TODAYSMOTORSTATUSADDRESS,0);

	motorOnCount= eeprom_read_byte((uint8_t *)MOTORCOUNTADDRESS);

	rtc_get_time(&time[0]);
	IsMototTurnedOnToday = eeprom_read_byte((uint8_t *)TODAYSMOTORSTATUSADDRESS);
	//If motor missed to turn on then restart motor between 7am(STARTSTOPHOUR) to 22pm
	if((rtcDec.hour >= STARTSTOPHOUR) && (rtcDec.hour < 22))
	{	
		char buff[16];
		if(IsMototTurnedOnToday == 0)
		{				
			startHr  = rtcDec.hour;
			stopHr   = rtcDec.hour;
			startMin = rtcDec.min + 0x2;
			stopMin  = startMin + DELTA;
			if(rtcDec.min > 57)
			{
				startHr = startHr + 1;
				stopHr  = startHr;
				startMin = (startMin % 60);
				stopMin  = startMin + DELTA;
			}						
			LCDGotoXY(0,0);
			lcd_clr();
			lcd_write_str("Setting On Time");
			LCDGotoXY(0,1);
			sprintf(&buff[0],"B:%d:%d E:%d:%d",startHr,startMin,stopHr,stopMin);
			lcd_write_str(buff);
			_delay_ms(5000);
		}
	}
	lcd_clr();
	wdt_enable(WDTO_2S);
	relayON = 0;
	char switchdisplay = 0; 
	while(1)
	{	
		if(switchdisplay++ < 10)
		{
			LCDGotoXY(0,0);
			rtc_get_time(&time[0]);
			lcd_write_str(time);
			lcd_write_str("   ");
			LCDGotoXY(11,0);
			lcd_write_str("C:");
			lcd_write_int(motorOnCount);
			//LCDGotoXY(12,0);
			//lcd_write_str("I:");
			//lcd_write_int(intCount);
			rtc_get_date(&date[0]);
			if(relayON == 0)
			{
				LCDGotoXY(0,1);
				lcd_write_str(date);	
				LCDGotoXY(11,1);
				lcd_write_str("T:");
				lcd_write_int(IsMototTurnedOnToday);
			}
		}
		else if((switchdisplay >= 10) && (switchdisplay < 20))
		{
			//lcd_clr();
			if(relayON == 0)
			{
				LCDGotoXY(0,0);
				lcd_write_str("Next ON:");
				lcd_write_int(startHr);
				LCDGotoXY(11,0);
				lcd_write_int(startMin);
				lcd_write_str("    ");
			}
		}
		else
		{
			switchdisplay = 0;
		}
		/* Reset IsMototTurnedOnToday flag everyday at 1AM*/
		if(((rtcDec.hour == RESETHOUR) && (rtcDec.min == RESETMINUTE)) && (rtcDec.sec < RESETSECOND) )
		{
			IsMototTurnedOnToday = 0;
			eeprom_write_byte((uint8_t*)TODAYSMOTORSTATUSADDRESS,IsMototTurnedOnToday);
			startHr = STARTSTOPHOUR; //start motor at 7am
			stopHr  = startHr;
			startMin = STARTSTOPMINUTE;
			stopMin  = startMin + DELTA;
		}
		//Reset motor on count once in a month i.e, on 1st of every month
		if(((rtcDec.date == RESETDAY ) && (rtcDec.hour == RESETHOUR) && (rtcDec.min == RESETMINUTE)) && (rtcDec.sec < RESETSECOND) )
		{
			motorOnCount = 0;
			eeprom_write_byte((uint8_t*)MOTORCOUNTADDRESS,motorOnCount);
		}
		if(!relayON)
		{
			if(MOTORSCHEDULE && (rtcDec.hour == startHr) && (rtcDec.min == startMin))
			{
				RELAY1_ON;
				relayON = 1;
				lcd_clr();
				LCDGotoXY(0,1);
				lcd_write_str("Motor Turned ON");
				BUZZER_ON;
				_delay_ms(300);
				BUZZER_OFF;
			}	
		}
		else
		{		
			if(MOTORSCHEDULE && (rtcDec.hour == stopHr) && (rtcDec.min == stopMin))
			{
				RELAY1_OFF;
				relayON = 0;
				++motorOnCount;
				//sprintf(buf,"C:%d\n",motorOnCount);
				LCDGotoXY(11,0);
				lcd_write_str("C:");
				lcd_write_int(motorOnCount);
				eeprom_write_byte((uint8_t*)MOTORCOUNTADDRESS,motorOnCount);
				startHr = STARTSTOPHOUR; //start motor at 7am
				stopHr  = startHr;
				startMin = STARTSTOPMINUTE;
				stopMin  = startMin + DELTA;
				IsMototTurnedOnToday = 1;
				eeprom_write_byte((uint8_t*)TODAYSMOTORSTATUSADDRESS,IsMototTurnedOnToday);
				lcd_clr();
				BUZZER_OFF;
			}
		}
		wdt_reset();
		_delay_ms(150);
	}	
	return 0;
}
