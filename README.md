
<div align=center>
<img src="Document/Image/avento.png" width="400" height="200"/>
</div>

## Library Maters ws2812b 

 the WS2812B is an intelligent control LED light source, with the control circuit and RGB chip integrated directly into a 5050 RGB LED. 
 As a digital LED strip, each addressable LED has an integrated driver that allows the brightness and color of each LED to be controlled individually, 
 that is, an LED can be of both a different color and brightness to the one next to it. This enables us to create beautiful and complex lighting effects.

The Library masters ws2812b is the full function driver of the ws2812b neopixel GRB series. The driver is writte C language with Code Blocks, It provides the functions to control The RGB.

### Table of Cnntents

  - [Install](#Install)
  - [Examples](#Examples)
  - [Usage](#Usage)
    - [example basic](#example-basic)
    - [example interface](#example-interface)
  - [Document](#Document)
  - [How to contribute](#Contribute)
  - [License](#License)
  - [Contact Us](#Contact-Us)
  - [Acknowledgements](#Acknowledgements)

  ### Install
  
  - The interface .C file expect below functions to correctly link the driver
  ```
    - ws2812b_interface_write_zero_instruction (Mandatory)
    - ws2812b_interface_write_one_instruction (Mandatory)
    - delay function ( Mandatory )
    - print function (optional )
  ```
  - refer to video: "coming soon..."
  - Use example project 

  ### Examples
  - [ATMEGA4808 (Atmel studio 7)](https://github.com/LibraryMasters/ws2812b/tree/master/Project%20Example/RGB_WS2812_ATMEGA4809)
  - [PIC24FJ128GA705 (MPLAB X IDE)](https://github.com/LibraryMasters/ws2812b/tree/master/Project%20Example/RGB_WS2812_PIC24FJ128GA705/RGB_WS2818)
  - [STM32F103C8T6 (STM32CubeIDE)](https://github.com/LibraryMasters/ws2812b/tree/master/Project%20Example/RGB_WS2812_STM32F103C8T6)
  ### Usage
  #### example basic
  
  ```C
#include "ws2812B_driver_basic.h"
#define NUMBER_LED          24               /**< number of leds on the strip */
ws2812b_info_t ws2812bInfo;

int colourIndex, ledIndex;
void rgb_toggle(uint8_t u8LedCount, uint32_t u32Time, ws2812b_basic_colour_t colour);

uint8_t colourArray [3] = {211, 255, 125};  /**< Red, Green, Blue*/

ws2812b_basic_colour_t basic_colour_array[7] = {    WS2812B_COLOUR_RED,
                                                    WS2812B_COLOUR_GREEN,
                                                    WS2812B_COLOUR_BLUE,
                                                    WS2812B_COLOUR_YELLOW,
                                                    WS2812B_COLOUR_MAGENTA,
                                                    WS2812B_COLOUR_CYAN,
                                                    WS2812B_COLOUR_PURPLE
                                               };


int main()
{
    ws2812b_basic_initialize(NUMBER_LED);
    ws2812b_info(&ws2812bInfo);

    ws2812b_interface_debug_print("Chip name: \t%s\n\r", ws2812bInfo.chip_Name);
    ws2812b_interface_debug_print("Manufacturer: \t%s\n\r", ws2812bInfo.manufacturer_name);
    ws2812b_interface_debug_print("Interface: \t%s\n\r", ws2812bInfo.interface);
    ws2812b_interface_debug_print("Supply max voltage: \t%0.2fV\n\r", ws2812bInfo.supply_Voltage_max_V);
    ws2812b_interface_debug_print("Supply min voltage: \t%0.2fV\n\r", ws2812bInfo.supply_voltage_min_v);
    ws2812b_interface_debug_print("Temperature Max: \t%.1fC\n\r", ws2812bInfo.temperature_max);
    ws2812b_interface_debug_print("Diver Version: \t\tV%.1f.%.2d\r\n", (ws2812bInfo.driver_version / 1000), (uint8_t)(ws2812bInfo.driver_version - (uint8_t)(ws2812bInfo.driver_version / 100)*100));

    // ws2812b_basic_write(1, WS2812B_COLOUR_BLUE);
    // ws2812b_basic_customized_colour(NUMBER_LED, (uint8_t *)colourArray);                 /**< write custom colour on 24 led */
    // rgb_toggle(2, 500,  WS2812B_COLOUR_GREEN);                                          /**< toggle 2 LEDs green*/

        for(colourIndex = 0; colourIndex < sizeof(basic_colour_array); colourIndex++){
           for(ledIndex = 1; ledIndex < NUMBER_LED+1; ledIndex++){
                ws2812b_interface_delay_ms(50);
                ws2812b_basic_write(ledIndex, basic_colour_array[colourIndex]);              /**< loop through different colours */
            }
           ws2812b_interface_delay_ms(50);
        }
    return 0;
}

void rgb_toggle(uint8_t u8LedCount, uint32_t u32Time, ws2812b_basic_colour_t colour)
{
    ws2812b_basic_write(u8LedCount, colour);
    ws2812b_interface_delay_ms(u32Time);
    ws2812b_basic_clear(1);
    ws2812b_interface_delay_ms(u32Time);
}
  ```
  
 ### Document
  - [datasheet](https://github.com/LibraryMasters/ws2812b/blob/master/Document/Datasheet/WS2812B.pdf)
  - [timing diagram](https://github.com/LibraryMasters/ws2812b/blob/master/Document/ws2812%20neopixel%20RGB%20timing%20diagram.pdf)
  
  ### Contribute
   1. Clone repo and create a new branch: ```https://github.com/LibraryMasters/ws2812b_PR.git```
   2. Make changes and test
   3. Submit Pull Request with comprehensive description of changes
  ### License
  [MIT](https://choosealicense.com/licenses/mit/)
### Contact Us

Email address: cedricmalyam@gmail.com

### Acknowledgements 
- @PeterHenderson https://dribbble.com/peterhenderson for the logo

