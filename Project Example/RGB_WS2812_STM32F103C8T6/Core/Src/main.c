/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ws2812B_driver_basic.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
uint8_t non_blocking_task2(void (*task)(int), uint32_t timeout, uint32_t tickCheck, int Parameter);
uint32_t millis(void);
void rgb_blink(int arg);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define  DEBUG_MODE
const uint8_t colorArray[3] = {128, 52, 128};  /*Red, Green, blue*/
uint32_t tickCount;
uint32_t blinkCheck_blue;
bool rgb_status;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);


  ws2812b_info_t ws2812bInfo;

  	HAL_Delay(2000); /*wait for drivers to initialize correctly*/

  	ws2812b_basic_initialize(NUMBER_LED);

  	#ifdef DEBUG_MODE

  	ws2812b_info(&ws2812bInfo);

  	ws2812b_interface_debug_print("chip name: \t%s\n\r", ws2812bInfo.chip_Name);
  	ws2812b_interface_debug_print("Manufacturer: \t%s\n\r", ws2812bInfo.manufacturer_name);
  	ws2812b_interface_debug_print("Interface: \t%s\n\r", ws2812bInfo.interface);
  	ws2812b_interface_debug_print("Supply max voltage: \t%0.2fV\n\r", ws2812bInfo.supply_Voltage_max_V);
  	ws2812b_interface_debug_print("Supply min voltage: \t%0.2fV\n\r", ws2812bInfo.supply_voltage_min_v);
  	ws2812b_interface_debug_print("Temperature Max: \t%.1fC\n\r", ws2812bInfo.temperature_max);
  	ws2812b_interface_debug_print("Driver version: \tV%.1f\n\r", (ws2812bInfo.driver_version / 1000));

  	#endif

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//	  ws2812b_basic_write(3, WS2812b_COLOR_RED);
//	  ws2812b_basic_customized_color(led_count, colorArray);
	  for(int index = 1; index < NUMBER_LED+1; index++){
		  ws2812b_interface_delay_ms(150);
		  ws2812b_basic_write(index, WS2812b_COLOR_BLUE);
	  }
	  ws2812b_basic_clear(4);
	  for(int index = 1; index < NUMBER_LED+1; index++){
		  ws2812b_interface_delay_ms(150);
		  ws2812b_basic_write(index, WS2812b_COLOR_GREEN);
	  }
	  ws2812b_basic_clear(4);

	  for(int index = 1; index < NUMBER_LED+1; index++){
		  ws2812b_interface_delay_ms(150);
		  ws2812b_basic_write(index, WS2812b_COLOR_RED);
	  }
	  ws2812b_basic_clear(4);
	  for(int index = 1; index < NUMBER_LED+1; index++){
		  ws2812b_interface_delay_ms(150);
		  ws2812b_basic_write(index, WS2812b_COLOR_YELLOW);
	  }
	  ws2812b_basic_clear(4);

	  for(int index = 1; index < NUMBER_LED+1; index++){
		  ws2812b_interface_delay_ms(150);
		  ws2812b_basic_write(index, WS2812b_COLOR_MAGENTA);
	  }
	  ws2812b_basic_clear(4);
	  for(int index = 1; index < NUMBER_LED+1; index++){
		  ws2812b_interface_delay_ms(150);
		  ws2812b_basic_write(index, WS2812b_COLOR_CYAN);
	  }
	  ws2812b_basic_clear(4);

	  for(int index = 1; index < NUMBER_LED+1; index++){
		  ws2812b_interface_delay_ms(150);
		  ws2812b_basic_write(index, WS2812b_COLOR_WHITE);
	  }
	  ws2812b_basic_clear(4);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7200-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 10000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, USER_LED_Pin|RGB_PIN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : USER_LED_Pin RGB_PIN_Pin */
  GPIO_InitStruct.Pin = USER_LED_Pin|RGB_PIN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

	if(htim->Instance == TIM2){
		tickCount++;
	}

}

uint32_t millis(void){
	return tickCount;
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
uint8_t non_blocking_task2(void (*task)(int), uint32_t timeout, uint32_t tickCheck, int Parameter) {
    volatile bool statusComplete = false;
    if ((millis() - tickCheck) > (timeout)) {
        (*task)(Parameter);
        statusComplete = true;
    }
    return 0;
}

void rgb_blink(int arg){

    if (rgb_status)
        ws2812b_basic_write(1, WS2812b_COLOR_CLEAR);
    else
        ws2812b_basic_write(1, arg);

    rgb_status = !rgb_status;
	blinkCheck_blue = millis();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
