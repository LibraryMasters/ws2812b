/* 
 * File:   utilies_file.h
 * Author: Cedricm
 *
 * Created on July 5, 2022, 12:59 PM
 */

#ifndef UTILIES_FILE_H
#define	UTILIES_FILE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include "xc.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define tickOffset     5  

#define _1000_MS_TIMEOUT     1000
#define _500_MS_TIMEOUT      500
#define _300_MS_TIMEOUT      300
#define _200_MS_TIMEOUT      200    
#define _100_MS_TIMEOUT      100
#define _50_MS_TIMEOUT       50
#define _25_MS_TIMEOUT       25
#define _10_MS_TIMEOUT       10

    extern volatile uint32_t systemTick; /**< increment every ms (elapse time since power reset)*/

    /**
     * @brief     tick count
     * @return    status code
     *            - system tick in milli seconds
     * @note      none
     */
    uint32_t Tick_Count(void);

    /**
     * @brief     delay function in milli seconds
     * @param[in] msTime is time delay
     * @return    status code
     *            - 0 delay success
     *            - 1 delay failed
     * @note      none
     */
    uint8_t delay_ms(uint32_t msTime);

    /**
     * @brief     led toggle non blocking callback
     * @param[in] *toggle_function is the led toggle function
     * @param[in] timeout is time toggle time interval
     * @param[in] tickCheck is the time track for system tick expiry time
     * @return    status code
     *            - 0 delay success
     *            - 1 delay failed
     * @note      none
     */
    uint8_t led_toggle_non_blocking(void (*toggle_function)(void), uint32_t timeout, uint32_t tickCheck);

    /**
     * @brief     Non blocking task callback funct
     * @param[in] *task point to the task function callback
     * @param[in] timeout is time interval to run task routine
     * @param[in] tickCheck is the time track for system tick expiry time
     * @return    status code
     *            - 0 delay success
     *            - 1 delay failed
     * @note      none
     */
    uint8_t non_blocking_task(void (*task)(void), uint32_t timeout, uint32_t tickCheck);
    uint8_t non_blocking_task2(void (*task)(int), uint32_t timeout, uint32_t tickCheck, int Parameter);

#ifdef	__cplusplus
}
#endif

#endif	/* UTILIES_FILE_H */

