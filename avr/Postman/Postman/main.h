/*
 * main.h
 *
 * Created: 2/19/2016 9:32:07 PM
 *  Author: Bahubali
 */ 


#ifndef MAIN_H_
#define MAIN_H_
//#define F_CPU 1000000UL
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "i2c.h"
#include "rtc.h"

typedef struct
{
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	uint8_t weekDay;
	uint8_t date;
	uint8_t month;
	uint8_t year;
}rtc_t;

#endif /* MAIN_H_ */