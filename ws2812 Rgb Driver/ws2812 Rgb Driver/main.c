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

    ws2812b_basic_customized_colour(NUMBER_LED, (uint8_t *)colourArray);                  /**< write custom colour on 24 led */
    //rgb_toggle(2, 500,  WS2812B_COLOUR_GREEN);                                            /**< toggle 2 LEDs green*/

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
