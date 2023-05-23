/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  PIC24FJ128GA705
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
 */

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

/**
  Section: Included Files
 */
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "utilies_file.h"
#include "ws2812B_driver_basic.h"
#include "mcc_generated_files/clock.h"

/*
                         Main application
 */

void toggle_led_blue(void);
void rgb_toggle(int arg);
void led_fade(void);

uint32_t blinkCheck_blue, rgb_toggle_check, rgb_toggle_check2;
bool rgb_status, fullBrightness;

volatile uint8_t colors[] = {0, 255, 200};
uint8_t *ptr;
uint8_t count;
const uint8_t colorsArray[] = {     WS2812b_COLOR_RED,
                                    WS2812b_COLOR_GREEN,
                                    WS2812b_COLOR_BLUE,
                                    WS2812b_COLOR_YELLOW,
                                    WS2812b_COLOR_MAGENTA,
                                    WS2812b_COLOR_CYAN,
                                    WS2812b_COLOR_WHITE,
                                    WS2812b_COLOR_PURPLE};


#define NUMBER_LED      24

int main(void) {
    // initialize the device
    SYSTEM_Initialize();
    
    ws2812b_info_t ws2812bInfo;
    
    delay_ms(2000);

    ws2812b_basic_initialize(NUMBER_LED);
    ws2812b_info(&ws2812bInfo);
//#ifdef DEBUG_MODE
    ws2812b_interface_debug_print("chip name: \t%s\n\r", ws2812bInfo.chip_Name);
    ws2812b_interface_debug_print("Manufacturer: \t%s\n\r", ws2812bInfo.manufacturer_name);
    ws2812b_interface_debug_print("Interface: \t%s\n\r", ws2812bInfo.interface);
    ws2812b_interface_debug_print("Supply max voltage: \t%0.2fV\n\r", ws2812bInfo.supply_Voltage_max_V);
    ws2812b_interface_debug_print("Supply min voltage: \t%0.2fV\n\r", ws2812bInfo.supply_voltage_min_v);
    ws2812b_interface_debug_print("Temperature Max: \t%.1fC\n\r", ws2812bInfo.temperature_max);
    ws2812b_interface_debug_print("Driver version: \tV%.1f\n\r", (ws2812bInfo.driver_version / 1000));
//#endif

    while (1) {
        
        // Add your application code

        led_toggle_non_blocking(&toggle_led_blue, _500_MS_TIMEOUT, blinkCheck_blue);
//        non_blocking_task2(&rgb_toggle, _1000_MS_TIMEOUT, rgb_toggle_check, WS2812b_COLOR_GREEN);
//        ws2812b_basic_customized_color(5, colors);
        
        for(int colorIndex = 0; colorIndex < sizeof(colorsArray); colorIndex++){
           for(int index = 1; index < NUMBER_LED+1; index++){
                ws2812b_interface_delay_ms(50);
                ws2812b_basic_write(index, colorsArray[colorIndex]);
            }
           ws2812b_interface_delay_ms(50);
        }

    }

    return 1;
}

void toggle_led_blue(void) {
    led_blue_Toggle();
    blinkCheck_blue = Tick_Count();
}

void rgb_toggle(int arg) {

    if (rgb_status)
        ws2812b_basic_write(6, WS2812b_COLOR_CLEAR);
    else
        ws2812b_basic_write(6, arg);

    rgb_status = !rgb_status;
    rgb_toggle_check = Tick_Count();
}


/**
 End of File
 */

