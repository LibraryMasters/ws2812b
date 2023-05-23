/* 
 * File:   ws2812b_driver_basic.c
 * Author: Cedricm
 *
 * Created on May 19, 2022, 2:56 PM
 */

#include "ws2812B_driver_basic.h"

/**
 * @brief     basic example initialize
 * @param[in] nLed is the number of rgb's on the strip
 * @return    status code
 *            - 0 success
 *            - 1 initialize failed
 * @note      none
 */

uint8_t ws2812b_basic_initialize(uint8_t nLed) {

    volatile uint8_t res;

    /*link function*/
    DRIVER_WS2812b_LINK_INIT(&ws2812b_handle, ws2812b_handle_t);
    DRIVER_WS2812b_LINK_DELAY_MS(&ws2812b_handle, ws2812b_interface_delay_ms);
    DRIVER_WS2812b_LINK_DEBUG_PRINT(&ws2812b_handle, ws2812b_interface_debug_print);
    DRIVER_WS2812b_LINK_LOGIC_HIGH(&ws2812b_handle, ws2812b_interface_write_one_instruction);
    DRIVER_WS2812b_LINK_LOGIC_LOW(&ws2812b_handle, ws2812b_interface_write_zero_instruction);

    res = ws2812b_init(&ws2812b_handle);
    if (res) {
		#ifdef DEBUG_MODE
        ws2812b_interface_debug_print("ws2812b: initialize failed\n");
		#endif
        return 1;
    }
    
    res =  ws2812b_basic_clear(nLed);
    if (res) {
		#ifdef DEBUG_MODE
        ws2812b_interface_debug_print("ws2812b: clear failed\n");
		#endif
        return 1;
    }

    /*wait 10 ms*/
    ws2812b_interface_delay_ms(10);

    return 0;
}

/**
 * @brief     basic of write color
 * @param[in] led_count is the number of rgb's on the strip
 * @param[in] color is the desired color to display (predefined)
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */

uint8_t ws2812b_basic_write(uint8_t led_count, ws2812b_basic_color_t Color) {

    volatile uint8_t res, index;
    for (index = 0; index < led_count; index++)
        res = ws2812b_write_basic_color(&ws2812b_handle, Color);
    ws2812b_interface_delay_ms(WS2812b_RESET_TIMEOUT);
    if (res) {
		#ifdef DEBUG_MODE
        ws2812b_interface_debug_print("ws2812b: basic write failed\n");
		#endif
        return 1;
    }
    return 0;

}

/**
 * @brief     basic of clear color
 * @param[in] nLedcountis the number leds on the strip
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t ws2812b_basic_clear(uint8_t nLedcount) {
    volatile uint8_t res;

    res = ws2812b_led_clear(&ws2812b_handle, nLedcount);
    if (res) {
		#ifdef DEBUG_MODE
        ws2812b_interface_debug_print("ws2812: RGB failed to clear\n");
		#endif
    }
    return 0;
}

/**
 * @brief     basic of customized colorscolor
 * @param[in] nLedcountis the number leds on the strip
 * @param[in] *color point to the red, green and blue color values
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t ws2812b_basic_customized_color(uint8_t nLedcount, uint8_t *color){
    
    volatile uint8_t res;
    
    res = ws2812b_write_color(&ws2812b_handle, nLedcount, (uint8_t*)color);
    ws2812b_interface_delay_ms(WS2812b_RESET_TIMEOUT);
    
    if (res) {
		#ifdef DEBUG_MODE
        ws2812b_interface_debug_print("ws2812: RGB failed to write colors\n");
		#endif
		
    }
    
    return 0;
}

