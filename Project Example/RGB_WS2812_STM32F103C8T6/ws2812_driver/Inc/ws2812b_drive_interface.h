/* 
 * File:   ws2812b_drive_interface.h
 * Author: Cedricm
 *
 * Created on 07 May 2022, 4:27 PM
 */

#ifndef WS2812B_DRIVE_INTERFACE_H
#define	WS2812B_DRIVE_INTERFACE_H
#include "ws2812b_driver.h"
#include "main.h"
#include "usbd_cdc_if.h"

#ifdef	__cplusplus
extern "C" {
#endif

    #define NUMBER_LED      4

    static ws2812b_handle_t ws2812b_handle;

    /**
     * @defgroup interface_driver mcp9808 interface driver function
     * @brief    ws2812b interface driver modules
     * @ingroup  ws2812b_driver
     * @{
     */
    
    /*
     * 
     * @brief     interface zero intruction
     * @param[in] *handle, point to ws2812b handle structure
     * @return   none
     * @note     none
     */

    void ws2812b_interface_write_zero_instruction(ws2812b_handle_t *handle);

    /*
       @brief     interface one intruction
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

