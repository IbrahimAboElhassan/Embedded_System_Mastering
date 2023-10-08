################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32_f103c6_driver/LCD_Driver/lcd.c 

OBJS += \
./stm32_f103c6_driver/LCD_Driver/lcd.o 

C_DEPS += \
./stm32_f103c6_driver/LCD_Driver/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
stm32_f103c6_driver/LCD_Driver/lcd.o: ../stm32_f103c6_driver/LCD_Driver/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded System dip_KS/Unit_7_Projects/Drivers/Driver/stm32_f103c6_driver/KeyPad_Driver" -I"D:/Embedded System dip_KS/Unit_7_Projects/Drivers/Driver/stm32_f103c6_driver/LCD_Driver" -I"D:/Embedded System dip_KS/Unit_7_Projects/Drivers/Driver/stm32_f103c6_driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_f103c6_driver/LCD_Driver/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

