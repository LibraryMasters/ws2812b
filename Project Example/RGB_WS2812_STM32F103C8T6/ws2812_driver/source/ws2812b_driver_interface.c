/* 
 * File:   ws2812b_driver_interface.c
 * Author: Cedricm
 *
 * Created on 07 May 2022, 4:37 PM
 */
#include "ws2812b_drive_interface.h"
#include <stdarg.h>


/*
 * @brief     interface zero instruction
 * @param[in] *handle, point to ws2812b handle structure
 * @return   none
 * @note     instruction to write 0 to the led: high time = 400ns and low time = 850ns with a tolerance of +/- 150ns
 */

void ws2812b_interface_write_zero_instruction(ws2812b_handle_t *handle) {
	  RGB_PIN_GPIO_Port->BSRR = RGB_PIN_Pin;
	{

		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");
		__asm__ __volatile__("nop");

	}
	RGB_PIN_GPIO_Port->BSRR = (uint32_t)RGB_PIN_Pin << 16u;
	RGB_PIN_GPIO_Port->BSRR = (uint32_t)RGB_PIN_Pin << 16u;
	RGB_PIN_GPIO_Port->BSRR = (uint32_t)RGB_PIN_Pin << 16u;
	RGB_PIN_GPIO_Port->BSRR = (uint32_t)RGB_PIN_Pin << 16u;
	RGB_PIN_GPIO_Port->BSRR = (uint32_t)RGB_PIN_Pin << 16u;
	{
			__asm__ __volatile__("nop");
			__asm__ __volatile__("nop");
			__asm__ __volatile__("nop");
			__asm__ __volatile__("nop");
			__asm__ __volatile__("nop");
			__asm__ __volatile__("nop");

	}

}

/*
   @brief     interface one instruction 
 * @param[in] *handle, point to ws2812b handle structure
 * @return   none
 * @note     instruction to write 1 to the led: high time = 800ns and low time = 450ns with a tolerance of +/- 150ns
 */

void ws2812b_interface_write_one_instruction(ws2812b_handle_t *handle) {
    
	 RGB_PIN_GPIO_Port->BSRR = RGB_PIN_Pin;
		  RGB_PIN_GPIO_Port->BSRR = RGB_PIN_Pin;
		  RGB_PIN_GPIO_Port->BSRR = RGB_PIN_Pin;
		  RGB_PIN_GPIO_Port->BSRR = RGB_PIN_Pin;
		  RGB_PIN_GPIO_Port->BSRR = RGB_PIN_Pin;
		{

				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");


		}
		RGB_PIN_GPIO_Port->BSRR = (uint32_t)RGB_PIN_Pin << 16u;
		{
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");
				__asm__ __volatile__("nop");

		}
}

/**
 * @brief     interface delay ms
 * @param[in] ms in the waiting period in milliseconds
 * @note      none
 */
void ws2812b_interface_delay_ms(uint32_t ms) {
	HAL_Delay(ms);
}

/*
 * @brief     interface print format data
 * @param[in] fmt is the format data
 * @return    length of the send data
 * @note      none
 */
uint16_t ws2812b_interface_debug_print(char *fmt, ...) {
	
   volatile char str[256];
    volatile uint8_t len;
    va_list args;

    memset((char *) str, 0, sizeof (char)*256);
    va_start(args, fmt);
    vsnprintf((char *) str, 256, (char const *) fmt, args);
    va_end(args);

    len = strlen((char *) str);
    if (CDC_Transmit_FS((uint8_t *) str, len)) {
	    return 0;
	    } else {
	    return len;
    }
}
