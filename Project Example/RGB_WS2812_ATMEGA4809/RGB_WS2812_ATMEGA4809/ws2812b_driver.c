/* 
 * File:   ws2812b_driver.c
 * Author: Cedricm
 *
 * Created on 07 May 2022, 2:45 PM
 */

#include "ws2812b_driver.h"

/**
 * @brief chip information definition
 */
#define CHIP_NAME                 "WS2812B"                  /**< chip name */
#define MANUFACTURER_NAME         "Worldsemi"                /**< manufacturer name */
#define SUPPLY_VOLTAGE_MIN        3.3f                       /**< chip min supply voltage */
#define SUPPLY_VOLTAGE_MAX        5.3f                       /**< chip max supply voltage */
#define MAX_CURRENT               60.0f                      /**< chip max current (mA)*/
#define TEMPERATURE_MIN           -25.0f                     /**< chip min operating temperature (°C) */
#define TEMPERATURE_MAX           80.0f                      /**< chip max operating temperature (°C) */
#define DRIVER_VERSION            1100                       /**< driver version */

/**
 * @brief     initialize the chip
 * @param[in] *handle points to a ws2812b handle structure
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 * @note      none
 */
uint8_t ws2812b_init(ws2812b_handle_t *handle) {
    if (handle == NULL)
        return 2;
    if (handle->debug_print == NULL)
        return 3;

    if (handle->delay_ms == NULL) { /* check delay_ms */
        handle->debug_print("ws2812b: delay_ms is null.\n"); /* delay_ms is null */

        return 3; /* return error */
    }

    if (handle->logic_high == NULL) { /*check logic write high */

        handle->debug_print("ws2812b: gpio digital write high is null, \n");
        return 3; /* return error */
    }

    if (handle->logic_low == NULL) { /*check  write low */

        handle->debug_print("ws2812b: gpio digital write low is null, \n");
        return 3; /* return error */
    }

    handle->inited = 1; /* flag finish initialization */


    return 0; /*return success*/
}

/*
   @brief     ws2812b write basic color
 * @param[in] *handle points to a ws2812b handle structure
 * @param[in] byte is the 8bit color value to be written 
 * @return 
 * @note     none
 */

void ws2812b_write_byte(ws2812b_handle_t *handle, uint8_t byte) {
	
		uint8_t index;
		uint8_t nBitMax = 8;   /**< Number of bit to be written*/

		for(index = 0; index < nBitMax; index++){
			if (byte & (0x80 >> index )) {
				handle->logic_high();
				} else {
				handle->logic_low();
			}
		}
}

/*
   @brief     ws2812b write basic color
 * @param[in] *handle, point to ws2812b handle structure
 * @param[in] *color point the desired color to display
 * @return 
 * @note     none
 */
uint8_t ws2812b_write_basic_color(ws2812b_handle_t *handle, ws2812b_basic_color_t color) {

    uint8_t green = 255, red = 255, blue = 255;  /**< maximum brightness for all three colors*/


    if (handle == NULL)      /**< check handle */
        return 2;            /**< return error */
    if (handle->inited != 1) /**< check handle initialization */
        return 3;            /**< return error */

    switch (color) {

        case WS2812b_COLOR_RED:
            ws2812b_write_byte(handle, NULL);
            ws2812b_write_byte(handle, red);
            ws2812b_write_byte(handle, NULL);
            break;

        case WS2812b_COLOR_BLUE:
            ws2812b_write_byte(handle, NULL);
            ws2812b_write_byte(handle, NULL);
            ws2812b_write_byte(handle, blue);
            break;

        case WS2812b_COLOR_GREEN:
            ws2812b_write_byte(handle, green);
            ws2812b_write_byte(handle, NULL);
            ws2812b_write_byte(handle, NULL);
            break;

        case WS2812b_COLOR_YELLOW:
            ws2812b_write_byte(handle, green);
            ws2812b_write_byte(handle, red);
            ws2812b_write_byte(handle, NULL);
            break;

        case WS2812b_COLOR_MAGENTA:
            ws2812b_write_byte(handle, NULL);
            ws2812b_write_byte(handle, red);
            ws2812b_write_byte(handle, blue);
            break;

        case WS2812b_COLOR_WHITE:
            ws2812b_write_byte(handle, green);
            ws2812b_write_byte(handle, red);
            ws2812b_write_byte(handle, blue);
            break;

        case WS2812b_COLOR_CYAN:
            ws2812b_write_byte(handle, green);
            ws2812b_write_byte(handle, NULL);
            ws2812b_write_byte(handle, blue);
            break;

        case WS2812b_COLOR_CLEAR:
            ws2812b_write_byte(handle, NULL);
            ws2812b_write_byte(handle, NULL);
            ws2812b_write_byte(handle, NULL);
            break;

        case WS2812b_COLOR_PURPLE:
            ws2812b_write_byte(handle, NULL);
            ws2812b_write_byte(handle, red >> 1);
            ws2812b_write_byte(handle, blue >> 1);
            break;

    }
    return 0;
}

/**
  @brief ws2812b write led array
 * @param[in] handle, point to ws2812b handle structure
 * @param[in] *colour is the desired color to display
 * @param[in] led count is the number of led's on the bus
 * @return   status code  
 *           -0 success 
 *           -1 failed  
 *           -2 handle is null
 * @note   none
 */
uint8_t ws2812b_write_color(ws2812b_handle_t *handle, uint8_t led_count, uint8_t *pColour) {
    
    volatile unsigned char index;
    
    for (index = 0; index < led_count; index++) {
        
        ws2812b_write_byte(handle, pColour[1]);
        ws2812b_write_byte(handle, pColour[0]);
        ws2812b_write_byte(handle, pColour[2]);
    }

    return 0;
}

/*
 * @brief ws2812b led clear
 * @param[in] *handle point to ws2812b handle structure
 * @param[in] ledCount is the number of led to cleared
 * @return  status
 *          -0 success
 *          -1 failed to clear
 *          -2 handle is null
 * @note    none
 */
uint8_t ws2812b_led_clear(ws2812b_handle_t *handle, uint8_t ledCount) {

    if (handle == NULL) /* check handle */
        return 2; /* return error */
    if (handle->inited != 1) /* check handle initialization */
        return 3; /* return error */

    handle->nLed_count = ledCount;

    unsigned char count; /*<< number of RGB on the array*/
    for (count = 0; count < handle->nLed_count; count++)
        ws2812b_write_basic_color(handle, WS2812b_COLOR_CLEAR);

    handle->delay_ms(WS2812b_RESET_TIMEOUT);

    return 0;
}

/**
 * @brief      get chip's information
 * @param[out] *info points to a ws2812b info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t ws2812b_info(ws2812b_info_t *info) {

    if (info == NULL) /* check handle */
        return 2; /* return error */

    memset(info, NULL, sizeof (ws2812b_info_t)); /* initialize ws2812b info structure */
    strncpy(info->chip_Name, CHIP_NAME, 25); /* copy chip name */
    strncpy(info->manufacturer_name, MANUFACTURER_NAME, 20); /* copy manufacturer name */
    strncpy(info->interface, "One Wire", 10); /* copy interface name */
    info->supply_voltage_min_v = SUPPLY_VOLTAGE_MIN; /* set minimal supply voltage */
    info->supply_Voltage_max_V = SUPPLY_VOLTAGE_MAX; /* set maximum supply voltage */
    info->current_max = MAX_CURRENT; /* set maximum current */
    info->temperature_max = TEMPERATURE_MAX; /* set minimal temperature */
    info->temperature_min = TEMPERATURE_MIN; /* set maximum temperature */
    info->driver_version = DRIVER_VERSION; /* set driver version */

    return 0; /*return success*/
}