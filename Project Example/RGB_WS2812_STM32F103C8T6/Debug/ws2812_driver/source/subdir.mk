################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ws2812_driver/source/ws2812b_driver.c \
../ws2812_driver/source/ws2812b_driver_basic.c \
../ws2812_driver/source/ws2812b_driver_interface.c 

OBJS += \
./ws2812_driver/source/ws2812b_driver.o \
./ws2812_driver/source/ws2812b_driver_basic.o \
./ws2812_driver/source/ws2812b_driver_interface.o 

C_DEPS += \
./ws2812_driver/source/ws2812b_driver.d \
./ws2812_driver/source/ws2812b_driver_basic.d \
./ws2812_driver/source/ws2812b_driver_interface.d 


# Each subdirectory must supply rules for building sources it contributes
ws2812_driver/source/%.o ws2812_driver/source/%.su: ../ws2812_driver/source/%.c ws2812_driver/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/Library Master/ws2812_neopixel_rgb/Project Example/RGB_WS2812_STM32F103C8T6/ws2812_driver/Inc" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-ws2812_driver-2f-source

clean-ws2812_driver-2f-source:
	-$(RM) ./ws2812_driver/source/ws2812b_driver.d ./ws2812_driver/source/ws2812b_driver.o ./ws2812_driver/source/ws2812b_driver.su ./ws2812_driver/source/ws2812b_driver_basic.d ./ws2812_driver/source/ws2812b_driver_basic.o ./ws2812_driver/source/ws2812b_driver_basic.su ./ws2812_driver/source/ws2812b_driver_interface.d ./ws2812_driver/source/ws2812b_driver_interface.o ./ws2812_driver/source/ws2812b_driver_interface.su

.PHONY: clean-ws2812_driver-2f-source

