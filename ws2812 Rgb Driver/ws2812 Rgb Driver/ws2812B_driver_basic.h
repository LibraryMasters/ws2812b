/**
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sub-license, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * File:  ws2812B_driver_basic.h
 * Author: Cedric Akilimali
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
 * @param[in] u8NumberLed is the number of led on the array
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 * @note      none
 */

uint8_t ws2812b_basic_initialize(uint8_t u8NumberLed);

/**
 * @brief     basic of write colour
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */

uint8_t ws2812b_basic_write(uint8_t led_count, ws2812b_basic_colour_t colour);

/**
 * @brief     basic of clear colour
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t ws2812b_basic_clear(uint8_t nLedcount);


/**
 * @brief     basic of customized colours
 * @param[in] nLedcountis the number leds on the strip
 * @param[in] *colour point to the red, green and blue colour values
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t ws2812b_basic_customized_colour(uint8_t nLedcount, uint8_t *colour);




#ifdef	__cplusplus
}
#endif

#endif	/* WS2812B_DRIVER_BASIC_H */

