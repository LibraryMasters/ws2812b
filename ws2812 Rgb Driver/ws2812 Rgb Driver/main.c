#include "ws2812B_driver_basic.h"
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

    ws2812b_info(&ws2812bInfo);
#ifdef WS2812B_DEBUG_MODE
    ws2812b_interface_debug_print("Chip name: \t%s\n\r", ws2812bInfo.chip_Name);
    ws2812b_interface_debug_print("Manufacturer: \t%s\n\r", ws2812bInfo.manufacturer_name);
    ws2812b_interface_debug_print("Interface: \t%s\n\r", ws2812bInfo.interface);
    ws2812b_interface_debug_print("Supply max voltage: \t%0.2fV\n\r", ws2812bInfo.supply_Voltage_max_V);
    ws2812b_interface_debug_print("Supply min voltage: \t%0.2fV\n\r", ws2812bInfo.supply_voltage_min_v);
    ws2812b_interface_debug_print("Temperature Max: \t%.1fC\n\r", ws2812bInfo.temperature_max);
    ws2812b_interface_debug_print("Driver version: \tV%.1f\n\r", (ws2812bInfo.driver_version / 1000));
#endif

//    rgb_toggle(1, 500, WS2812B_COLOUR_GREEN);

    ws2812b_basic_customized_colour(4, (uint8_t *)colourArray);

    for(colourIndex = 0; colourIndex < 7; colourIndex){

        for(ledIndex = 1; ledIndex < 5; ledIndex++)
        {
            ws2812b_basic_write(ledIndex, basic_colour_array[colourIndex]);
            ws2812b_interface_delay_ms(500);
        }
        ws2812b_basic_clear(4);
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
