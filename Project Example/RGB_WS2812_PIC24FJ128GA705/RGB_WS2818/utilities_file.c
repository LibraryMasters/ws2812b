
#include "utilies_file.h"
/**
 * @brief     tick count
 * @return    status code
 *            - system tick in milli seconds
 * @note      none
 */
uint32_t Tick_Count(void) {
    return systemTick;
}

/**
 * @brief     delay function in milli seconds
 * @param[in] msTime is time delay
 * @return    status code
 *            - 0 delay success
 *            - 1 delay failed
 * @note      none
 */
uint8_t delay_ms(uint32_t msTime) {

    volatile uint32_t delayCheck = Tick_Count();
    while ((Tick_Count() - delayCheck) < msTime - tickOffset);

    if (Tick_Count() - delayCheck < msTime - tickOffset) {
//        printf("delay failed to execute\n");
        return 1; //return error
    }
    return 0;
}

/**
 * @brief     led toggle  non blocking callback
 * @param[in] *toggle_function is the led toggle function
 * @param[in] timeout is time toggle time interval
 * @param[in] tickCheck is the time track for system tick expiry time
 * @return    status code
 *            - 0 success
 *            - 1 failed
 * @note      none
 */
uint8_t led_toggle_non_blocking(void (*toggle_function)(void), uint32_t timeout, uint32_t tickCheck) {

    volatile bool statusComplete = false;
    if ((Tick_Count() - tickCheck) > (timeout - tickOffset)) {
        (*toggle_function)();
        statusComplete = true;
    }

    return statusComplete;
}

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
uint8_t non_blocking_task(void (*task)(void), uint32_t timeout, uint32_t tickCheck) {
    volatile bool statusComplete = false;
    if ((Tick_Count() - tickCheck) > (timeout - tickOffset)) {
        (*task)();
        statusComplete = true;
    }
    return 0;
}

uint8_t non_blocking_task2(void (*task)(int), uint32_t timeout, uint32_t tickCheck, int Parameter) {
    volatile bool statusComplete = false;
    if ((Tick_Count() - tickCheck) > (timeout - tickOffset)) {
        (*task)(Parameter);
        statusComplete = true;
    }
    return 0;
}