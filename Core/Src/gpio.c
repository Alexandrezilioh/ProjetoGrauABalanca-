/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_CONFIG = {0}; //Variavel da bibliteca HAL para configurar os pinos e agrupamento

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LedProto_Pin|Led_Ama_Pin|Led_Verd_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Led_Laran_Pin|Led_Verm_Pin|SCK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_CONFIG.Pin = B1_Pin;
  GPIO_CONFIG.Mode = GPIO_MODE_IT_FALLING;
  GPIO_CONFIG.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_CONFIG);

  /*Configure GPIO pins : LedProto_Pin Led_Ama_Pin Led_Verd_Pin */
  GPIO_CONFIG.Pin = LedProto_Pin|Led_Ama_Pin|Led_Verd_Pin;
  GPIO_CONFIG.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_CONFIG.Pull = GPIO_NOPULL;
  GPIO_CONFIG.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_CONFIG);

  /*Configure GPIO pins : Led_Laran_Pin Led_Verm_Pin SCK_Pin */
  GPIO_CONFIG.Pin = Led_Laran_Pin|Led_Verm_Pin|SCK_Pin;
  GPIO_CONFIG.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_CONFIG.Pull = GPIO_NOPULL;
  GPIO_CONFIG.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_CONFIG);

  /*Configure GPIO pin : DT_Pin */
  GPIO_CONFIG.Pin = DT_Pin;
  GPIO_CONFIG.Mode = GPIO_MODE_INPUT;
  GPIO_CONFIG.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(DT_GPIO_Port, &GPIO_CONFIG);

  /*Configure GPIO pins : Reset_Pin Start_Pin */
  GPIO_CONFIG.Pin = Reset_Pin|Start_Pin;
  GPIO_CONFIG.Mode = GPIO_MODE_INPUT;
  GPIO_CONFIG.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_CONFIG);
}
/* USER CODE BEGIN 2 */

/* USER CODE END 2 */