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
 * File:  ws2812b_drive_interface.h
 * Author: Cedric Akilimali
 *
 * Created on 07 May 2022, 4:27 PM
 */

#ifndef WS2812B_DRIVE_INTERFACE_H
#define	WS2812B_DRIVE_INTERFACE_H
#include "ws2812b_driver.h"

#ifdef	__cplusplus
extern "C" {
#endif


static ws2812b_handle_t ws2812b_handle;

/**
 * @defgroup interface_driver ws2812b interface driver function
 * @brief    ws2812b interface driver modules
 * @ingroup  ws2812b_driver
 * @{
 */

/**
 * @brief     interface zero instruction
 * @param[in] *handle, point to ws2812b handle structure
 * @return   none
 * @note     none
 */

void ws2812b_interface_write_zero_instruction(ws2812b_handle_t *handle);

/**
 * @brief     interface one instruction
 * @param[in] *handle, point to ws2812b handle structure
 * @return   none
 * @note     none
 */

void ws2812b_interface_write_one_instruction(ws2812b_handle_t *handle);

/**
 * @brief     interface delay ms
 * @param[in] ms
 * @note      none
 */
void ws2812b_interface_delay_ms(uint32_t ms);

/**
 * @brief     interface delay cycle
 * @param[in] _nop is 1 instruction cycle time
 * @note      none
 */
uint16_t ws2812b_interface_debug_print(char *fmt, ...);




#ifdef	__cplusplus
}
#endif

#endif	/* WS2812B_DRIVE_INTERFACE_H */

