/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define L1_Pin GPIO_PIN_0
#define L1_GPIO_Port GPIOA
#define L2_Pin GPIO_PIN_1
#define L2_GPIO_Port GPIOA
#define L3_Pin GPIO_PIN_2
#define L3_GPIO_Port GPIOA
#define C1_Pin GPIO_PIN_3
#define C1_GPIO_Port GPIOA
#define C2_Pin GPIO_PIN_4
#define C2_GPIO_Port GPIOA
#define C3_Pin GPIO_PIN_5
#define C3_GPIO_Port GPIOA
#define C4_Pin GPIO_PIN_6
#define C4_GPIO_Port GPIOA
#define C5_Pin GPIO_PIN_7
#define C5_GPIO_Port GPIOA
#define Linha1_Pin GPIO_PIN_0
#define Linha1_GPIO_Port GPIOB
#define Linha2_Pin GPIO_PIN_1
#define Linha2_GPIO_Port GPIOB
#define C6_Pin GPIO_PIN_8
#define C6_GPIO_Port GPIOA
#define C7_Pin GPIO_PIN_9
#define C7_GPIO_Port GPIOA
#define C8_Pin GPIO_PIN_10
#define C8_GPIO_Port GPIOA
#define C9_Pin GPIO_PIN_15
#define C9_GPIO_Port GPIOA
#define Linha3_Pin GPIO_PIN_3
#define Linha3_GPIO_Port GPIOB
#define Linha4_Pin GPIO_PIN_4
#define Linha4_GPIO_Port GPIOB
#define Coluna1_Pin GPIO_PIN_5
#define Coluna1_GPIO_Port GPIOB
#define Coluna2_Pin GPIO_PIN_6
#define Coluna2_GPIO_Port GPIOB
#define Coluna3_Pin GPIO_PIN_7
#define Coluna3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
