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
 * File:  ws2812b_driver_interface.c
 * Author: Cedric Akilimali
 *
 * Created on 07 May 2022, 4:37 PM
 */

#include "ws2812b_drive_interface.h"
#include <stdarg.h>


/**
 * @brief     interface zero instruction
 * @param[in] *handle, point to ws2812b handle structure
 * @return   none
 * @note     instruction to write 0 to the led: high time = 400 ns and low time = 850ns with a tolerance of +/- 150ns
 */

void ws2812b_interface_write_zero_instruction(ws2812b_handle_t *handle)
{
    /*call your function here*/
    /*user code begin */

    /*user code end*/
}

/**
 * @brief     interface one instruction
 * @param[in] *handle, point to ws2812b handle structure
 * @return   none
 * @note     instruction to write 1 to the led: high time = 800ns and low time = 450ns with a tolerance of +/- 150ns
 */

void ws2812b_interface_write_one_instruction(ws2812b_handle_t *handle)
{
    /*call your function here*/
    /*user code begin */

    /*user code end*/
}

/**
 * @brief     interface delay ms
 * @param[in] ms in the waiting period in milliseconds
 * @note      none
 */
void ws2812b_interface_delay_ms(uint32_t ms)
{
    /*call your delay function here*/
    /*user code begin */

    /*user code end*/
}

/**
 * @brief     interface print format data
 * @param[in] fmt is the format data
 * @return    length of the send data
 * @note      none
 */
uint16_t ws2812b_interface_debug_print(char *fmt, ...)
{
    /*call your call print function here*/
    /*user code begin */
#ifdef WS2812B_DEBUG_MODE
    volatile char str[256];
    volatile uint8_t len;
    va_list args;

    memset((char *) str, 0, sizeof (char)*256);
    va_start(args, fmt);
    vsnprintf((char *) str, 256, (char const *) fmt, args);
    va_end(args);

    len = strlen((char *) str);
//    EUSART1_Write_Text((const char *) str, len);
    (void)printf((uint8_t *)str, len);

    /*user code end*/
#endif
}
