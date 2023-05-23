/* 
 * File:   ws2812b_driver_interface.c
 * Author: Cedricm
 *
 * Created on 07 May 2022, 4:37 PM
 */
#include "ws2812b_drive_interface.h"
#include <stdarg.h>
#include "xc.h"

/*
 * @brief     interface zero instruction
 * @param[in] *handle, point to ws2812b handle structure
 * @return   none
 * @note     instruction to write 0 to the led: high time = 400ns and low time = 850ns with a tolerance of +/- 150ns
 */

void ws2812b_interface_write_zero_instruction(ws2812b_handle_t *handle) {

    LATBbits.LATB9 = 1;            /**< write logic high to the control pin*/
    {                              /**< delay by x number of instruction cycle*/
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
    }

    LATBbits.LATB9 = 0;          /**<write logic low to the control pin*/
    {                            /**< delay by x number of instruction cycle*/
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
    }

}

/*
   @brief     interface one instruction 
 * @param[in] *handle, point to ws2812b handle structure
 * @return   none
 * @note     instruction to write 1 to the led: high time = 800ns and low time = 450ns with a tolerance of +/- 150ns
 */

void ws2812b_interface_write_one_instruction(ws2812b_handle_t *handle) {
    
    LATBbits.LATB9 = 1;               /**< write logic high to the control pin*/
    {                                  /**< delay by x number of instruction cycle*/
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        
    }

    LATBbits.LATB9 = 0;              /**<write logic low to the control pin*/
    {

    }
}

/**
 * @brief     interface delay ms
 * @param[in] ms in the waiting period in milliseconds
 * @note      none
 */
void ws2812b_interface_delay_ms(uint32_t ms) {
    delay_ms(ms);
}

/**
 * @brief     interface print format data
 * @param[in] fmt is the format data
 * @return    length of the send data
 * @note      none
 */
uint16_t ws2812b_interface_debug_print(char *fmt, ...) {
    
#ifdef DEBUG_MODE
    volatile char str[256];
    volatile uint8_t len;
    va_list args;

    memset((char *) str, 0, sizeof (char)*256);
    va_start(args, fmt);
    vsnprintf((char *) str, 256, (char const *) fmt, args);
    va_end(args);

    len = strlen((char *) str);
    if (EUSART1_Write_Text((uint8_t *) str, len)) {
        return 0;
    } else {
        return len;
    }
#endif
    
}
