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
 * File:   ws2812b_driver.h
 * Author: Cedric Akilimali
 *
 * Created on May 2, 2022, 4:43 PM
 */


#ifndef WS2812B_DRIVER_H
#define	WS2812B_DRIVER_H
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define WS2812B_DEBUG_MODE
#define WS2812b_RESET_TIMEOUT  1U /**< wait at least 1ms to reset*/

/**
 @brief ws2812b basic colour enumeration
 */
typedef enum {
    WS2812B_COLOUR_RED     = 0,
    WS2812B_COLOUR_GREEN   = 1,
    WS2812B_COLOUR_BLUE    = 2,
    WS2812B_COLOUR_YELLOW  = 3,
    WS2812B_COLOUR_MAGENTA = 4,
    WS2812B_COLOUR_CYAN    = 5,
    WS2812B_COLOUR_WHITE   = 6,
    WS2812B_COLOUR_PURPLE  = 7,
    WS2812B_COLOUR_CLEAR   = 8
} ws2812b_basic_colour_t;


/**
 @brief ws2812b handle structure definition
 */
typedef struct ws2812b_handle_s {
    void (*logic_high)(void);               /**< Set DIN pin high*/
    void (*logic_low)(void);                /**< Set DIN pin low*/
    void (*delay_ms)(uint32_t ms);          /**< point to a delay_ms function address */
    uint16_t(*debug_print)(char *fmt, ...); /**< point to a debug_print function address */
    uint16_t nLed_count;                    /**< number of led*/
    uint32_t cpu_clock;                     /**< cpu running clock, F_hz*/
    uint8_t inited;                         /**< inited flag */

} ws2812b_handle_t;

/**
 @brief ws2812b information structure definition
 */
typedef struct ws2812b_info_s {
    char chip_Name[25];                     /*< device/ sensor name*/
    char manufacturer_name[25];             /*< manufacturer name*/
    char interface[10];                     /*< communication protocol */
    float supply_voltage_min_v;             /*< minimum operating temperature*/
    float supply_Voltage_max_V;             /*< maximum operating voltage*/
    uint16_t current_max;                   /*< maximum current consumption*/
    uint8_t temperature_min;                /*< maximum operating temperature*/
    float temperature_max;                  /*< minimum operating temperature*/
    float driver_version;                   /*< driver version*/

} ws2812b_info_t;


/**
 * @defgroup ws2812b_link_driver ws2812b link driver function
 * @brief    ws2812b link driver modules
 * @ingroup  ws2812b_driver
 * @{
 */

/**
 * @brief     initialize  ws2812b_handle_t structure
 * @param[in] HANDLE points to a  ws2812b handle structure
 * @param[in] STRUCTURE is  ws2812_handle_t
 * @note      none
 */
#define DRIVER_WS2812b_LINK_INIT(HANDLE, STRUCTURE)            memset(HANDLE, NULL, sizeof(STRUCTURE))


/***
 * @brief     link logic_high
 * @param[in] HANDLE points to a  ws2812b handle structure
 * @param[in] FUC points to logic high instruction function
 * @note      none
 */
#define DRIVER_WS2812b_LINK_LOGIC_HIGH(HANDLE, FUC)    (HANDLE)->logic_high = FUC

/***
 * @brief     link logic_low
 * @param[in] HANDLE points to a ws2812b handle structure
 * @param[in] FUC points to logic low instruction function
 * @note      none
 */
#define DRIVER_WS2812b_LINK_LOGIC_LOW(HANDLE, FUC)    (HANDLE)->logic_low = FUC


/**
 * @brief     link delay_ms function
 * @param[in] HANDLE points to a ws2812b handle structure
 * @param[in] FUC points to a delay_ms function address
 * @note      none
 */
#define DRIVER_WS2812b_LINK_DELAY_MS(HANDLE, FUC)              (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE points to a ws2812b handle structure
 * @param[in] FUC points to a debug_print function address
 * @note      none
 */
#define DRIVER_WS2812b_LINK_DEBUG_PRINT(HANDLE, FUC)           (HANDLE)->debug_print = FUC


/**
 * @}
 */

/**
 * @defgroup ws2812b_base_driver ws2812b base driver function
 * @brief    ws2812b base driver modules
 * @ingroup  ws2812b_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info points to a ws2812b info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t ws2812b_info(ws2812b_info_t *info);

/**
 * @brief     initialize the chip
 * @param[in] *handle points to a ws2812b handle structure
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 *            - 3 handle initialization failed
 * @note      none
 */
uint8_t ws2812b_init(ws2812b_handle_t *handle);


/**
 * @brief     ws2812b write basic colour
 * @param[in] byte is the 8 bit colour value to be written
 * @return
 * @note     none
 */

uint8_t ws2812b_write_byte(ws2812b_handle_t *handle, uint8_t byte);

/**
 * @brief     ws2812b write basic colour
 * @param[in] *handle, point to ws2812b handle structure
 * @param[in] *colour point the desired colour to display
 * @return
 * @note     none
 */
uint8_t ws2812b_write_basic_colour(ws2812b_handle_t *handle, ws2812b_basic_colour_t colour);

/**
  @brief ws2812b write led array
 * @param[in] handle, point to ws2812b handle structure
 * @param[in] *pColour point to the desired colour array to display
 * @param[in] led count is the number of led's on the bus
 * @return   status code
 *           -0 success
 *           -1 failed
 *           -2 handle is null
 * @note   none
 */
uint8_t ws2812b_write_colour(ws2812b_handle_t *handle, uint8_t led_count, uint8_t *pColour);

/**
 * @brief ws2812b led clear
 * @param[in] *handle point to ws2812b handle structure
 * @return  status
 *          -0 success
 *          -1 failed to clear
 * @note    none
 */

uint8_t ws2812b_led_clear(ws2812b_handle_t *handle, uint8_t ledCount);

/**
 * @}
 */

#ifdef	__cplusplus
}
#endif

#endif	/* WS2812B_DRIVER_H */

