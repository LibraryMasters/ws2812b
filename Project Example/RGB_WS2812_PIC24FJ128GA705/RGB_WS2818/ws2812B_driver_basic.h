/* 
 * File:   ws2812B_driver_basic.h
 * Author: Cedricm
 *
 * Created on May 19, 2022, 2:36 PM
 */

#ifndef WS2812B_DRIVER_BASIC_H
#define	WS2812B_DRIVER_BASIC_H

#include "ws2812b_drive_interface.h"

#ifdef	__cplusplus
extern "C" {
#endif
    

/**
 * @brief     basic example initialize
 * @param[in] nLed is the number of led on the array
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 * @note      none
 */
    
uint8_t ws2812b_basic_initialize(uint16_t nLed);

/**
 * @brief     basic of write color
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */

uint8_t ws2812b_basic_write(uint16_t led_count, ws2812b_basic_color_t Color);

/**
 * @brief     basic of clear color
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t ws2812b_basic_clear(uint16_t nLedcount);


/**
 * @brief     basic of customized colors
 * @param[in] nLedcountis the number leds on the strip
 * @param[in] *color point to the red, green and blue color values
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t ws2812b_basic_customized_color(uint16_t nLedcount, uint8_t *color);




#ifdef	__cplusplus
}
#endif

#endif	/* WS2812B_DRIVER_BASIC_H */

