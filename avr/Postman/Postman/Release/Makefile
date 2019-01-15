################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../i2c.c \
../lcd.c \
../main.c \
../rtc.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
i2c.o \
lcd.o \
main.o \
rtc.o

OBJS_AS_ARGS +=  \
i2c.o \
lcd.o \
main.o \
rtc.o

C_DEPS +=  \
i2c.d \
lcd.d \
main.d \
rtc.d

C_DEPS_AS_ARGS +=  \
i2c.d \
lcd.d \
main.d \
rtc.d

OUTPUT_FILE_PATH +=Postman.elf

OUTPUT_FILE_PATH_AS_ARGS +=Postman.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./i2c.o: .././i2c.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)J:\installation\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DNDEBUG  -I"J:\installation\7.0\Packs\atmel\ATmega_DFP\1.2.209\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=atmega16 -B "J:\installation\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega16" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./lcd.o: .././lcd.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)J:\installation\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DNDEBUG  -I"J:\installation\7.0\Packs\atmel\ATmega_DFP\1.2.209\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=atmega16 -B "J:\installation\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega16" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)J:\installation\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DNDEBUG  -I"J:\installation\7.0\Packs\atmel\ATmega_DFP\1.2.209\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=atmega16 -B "J:\installation\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega16" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./rtc.o: .././rtc.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)J:\installation\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DNDEBUG  -I"J:\installation\7.0\Packs\atmel\ATmega_DFP\1.2.209\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=atmega16 -B "J:\installation\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega16" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)J:\installation\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Postman.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega16 -B "J:\installation\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega16"  
	@echo Finished building target: $@
	"J:\installation\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Postman.elf" "Postman.hex"
	"J:\installation\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Postman.elf" "Postman.eep" || exit 0
	"J:\installation\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Postman.elf" > "Postman.lss"
	"J:\installation\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Postman.elf" "Postman.srec"
	"J:\installation\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Postman.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Postman.elf" "Postman.a" "Postman.hex" "Postman.lss" "Postman.eep" "Postman.map" "Postman.srec" "Postman.usersignatures"
	