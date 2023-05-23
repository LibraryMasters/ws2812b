#include <atmel_start.h>
#include "ws2812B_driver_basic.h"


#define NUMBER_LED      4

const uint8_t colourArray[3] = {0, 152, 152};  /*Red, Green, blue*/

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

	ws2812b_basic_color_t basic_color_array[7] = {WS2812B_COLOUR_GREEN, WS2812B_COLOUR_BLUE, WS2812B_COLOUR_RED, WS2812B_COLOUR_YELLOW, WS2812B_COLOUR_MAGENTA, WS2812B_COLOUR_CYAN, WS2812B_COLOUR_WHITE};

	/* Replace with your application code */
	while (1) {
          

		  //ws2812b_basic_write(2, WS2812b_COLOUR_BLUE);                /**< write blue colour to the first 2 leds */
	
		  ws2812b_basic_customized_color(1, (uint8_t*)colourArray);   	/**< write cutomised color to the first led */
		  ws2812b_interface_delay_ms(5000);                          	/**< wait 3 second */
	    for( int colorIndex = 0; colorIndex < 7; colorIndex++){      	/**< play around with all the basic colors */
				 
			for(int index = 0; index < (NUMBER_LED + 1); ++index){
				ws2812b_basic_write(index, basic_color_array[colorIndex]);
				_delay_ms(200); 
			 }
			 ws2812b_basic_clear(4);
		  }
	  
	}
	return 1; 
}

