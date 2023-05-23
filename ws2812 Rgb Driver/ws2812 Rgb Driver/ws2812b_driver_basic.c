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
 * File:  ws2812b_driver_basic.c
 * Author: Cedric Akilimali
 *
 * Created on May 19, 2022, 2:56 PM
 */

#include "ws2812B_driver_basic.h"

/**
 * @brief     basic example initialize
 * @param[in] u8NumberLed is the number of rgb's on the strip
 * @return    status code
 *            - 0 success
 *            - 1 initialize failed
 * @note      none
 */

uint8_t ws2812b_basic_initialize(uint8_t u8NumberLed)
{

    volatile uint8_t res;

    /*link function*/
    DRIVER_WS2812b_LINK_INIT(&ws2812b_handle, ws2812b_handle_t);
    DRIVER_WS2812b_LINK_DELAY_MS(&ws2812b_handle, ws2812b_interface_delay_ms);
    DRIVER_WS2812b_LINK_DEBUG_PRINT(&ws2812b_handle, ws2812b_interface_debug_print);
    DRIVER_WS2812b_LINK_LOGIC_HIGH(&ws2812b_handle, ws2812b_interface_write_one_instruction);
    DRIVER_WS2812b_LINK_LOGIC_LOW(&ws2812b_handle, ws2812b_interface_write_zero_instruction);

    res = ws2812b_init(&ws2812b_handle);
    if (res)
    {
#ifdef WS2812B_DEBUG_MODE
        ws2812b_interface_debug_print("ws2812b: initialize failed\n");
#endif
        return 1;
    }

    res =  ws2812b_basic_clear(u8NumberLed);
    if (res)
    {
#ifdef WS2812B_DEBUG_MODE
        ws2812b_interface_debug_print("ws2812b: clear failed\n");
#endif
        return 1;
    }

    /*wait 10 ms*/
    ws2812b_interface_delay_ms(10);

    return 0;
}

/**
 * @brief     basic of write colour
 * @param[in] led_count is the number of rgb's on the strip
 * @param[in] colour is the desired colour to display (predefined)
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */

uint8_t ws2812b_basic_write(uint8_t led_count, ws2812b_basic_colour_t colour)
{

    volatile uint8_t res, index;
    for (index = 0; index < led_count; index++)
        res = ws2812b_write_basic_colour(&ws2812b_handle, colour);
    ws2812b_interface_delay_ms(WS2812b_RESET_TIMEOUT);
    if (res)
    {
#ifdef WS2812B_DEBUG_MODE
        ws2812b_interface_debug_print("ws2812b: basic write failed\n");
#endif
        return 1;
    }
    return 0;

}

/**
 * @brief     basic of clear colour
 * @param[in] nLedcountis the number leds on the strip
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t ws2812b_basic_clear(uint8_t nLedcount)
{
    volatile uint8_t res;

    res = ws2812b_led_clear(&ws2812b_handle, nLedcount);
    if (res)
    {
#ifdef WS2812B_DEBUG_MODE
        ws2812b_interface_debug_print("ws2812b: RGB failed to clear\n");
#endif
    }
    return 0;
}

/**
 * @brief     basic of customized colours
 * @param[in] nLedcountis the number leds on the strip
 * @param[in] *colour point to the red, green and blue colour values
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t ws2812b_basic_customized_colour(uint8_t nLedcount, uint8_t *colour)
{

    volatile uint8_t res;

    res = ws2812b_write_colour(&ws2812b_handle, nLedcount, (uint8_t*)colour);
    ws2812b_interface_delay_ms(WS2812b_RESET_TIMEOUT);

    if (res)
    {
#ifdef WS2812B_DEBUG_MODE
        ws2812b_interface_debug_print("ws2812: RGB failed to write colours\n");
#endif

    }

    return 0;
}

