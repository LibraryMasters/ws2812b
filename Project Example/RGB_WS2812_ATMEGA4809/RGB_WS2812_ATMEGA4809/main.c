#include <atmel_start.h>
#include "ws2812B_driver_basic.h"


#define NUMBER_LED      24

const uint8_t color[3] = {0, 152, 152};  /*Red, Green, blue*/

int main(void)
{
	/* Initializes MCU, drivers and middle-ware */
	atmel_start_init();
	
	ws2812b_info_t ws2812bInfo;
	
	_delay_ms(2000); /*wait for drivers to initialize correctly*/

	ws2812b_basic_initialize(NUMBER_LED);
	
	#ifdef DEBUG_MODE
	
	ws2812b_info(&ws2812bInfo);
#ifdef DEBUG_MODE
	ws2812b_interface_debug_print("chip name: \t%s\n\r", ws2812bInfo.chip_Name);
	ws2812b_interface_debug_print("Manufacturer: \t%s\n\r", ws2812bInfo.manufacturer_name);
	ws2812b_interface_debug_print("Interface: \t%s\n\r", ws2812bInfo.interface);
	ws2812b_interface_debug_print("Supply max voltage: \t%0.2fV\n\r", ws2812bInfo.supply_Voltage_max_V);
	ws2812b_interface_debug_print("Supply min voltage: \t%0.2fV\n\r", ws2812bInfo.supply_voltage_min_v);
	ws2812b_interface_debug_print("Temperature Max: \t%.1fC\n\r", ws2812bInfo.temperature_max);
	ws2812b_interface_debug_print("Driver version: \tV%.1f\n\r", (ws2812bInfo.driver_version / 1000));
	#endif

	#endif

	const uint8_t colorsArray[] = {     WS2812b_COLOR_RED,
										WS2812b_COLOR_GREEN,
										WS2812b_COLOR_BLUE,
										WS2812b_COLOR_YELLOW,
										WS2812b_COLOR_MAGENTA,
										WS2812b_COLOR_CYAN,
										WS2812b_COLOR_WHITE,
									    WS2812b_COLOR_PURPLE};

	/* Replace with your application code */
	while (1) {
          
//        ws2812b_basic_customized_color(1, color);

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

