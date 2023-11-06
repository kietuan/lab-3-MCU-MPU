/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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
#define GREEN1_Pin GPIO_PIN_1
#define GREEN1_GPIO_Port GPIOA
#define YELLOW1_Pin GPIO_PIN_2
#define YELLOW1_GPIO_Port GPIOA
#define RED1_Pin GPIO_PIN_3
#define RED1_GPIO_Port GPIOA
#define a0_Pin GPIO_PIN_4
#define a0_GPIO_Port GPIOA
#define RED0_Pin GPIO_PIN_5
#define RED0_GPIO_Port GPIOA
#define YELLOW0_Pin GPIO_PIN_6
#define YELLOW0_GPIO_Port GPIOA
#define GREEN0_Pin GPIO_PIN_7
#define GREEN0_GPIO_Port GPIOA
#define a1_Pin GPIO_PIN_0
#define a1_GPIO_Port GPIOB
#define b1_Pin GPIO_PIN_1
#define b1_GPIO_Port GPIOB
#define c1_Pin GPIO_PIN_2
#define c1_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_10
#define EN3_GPIO_Port GPIOB
#define g0_Pin GPIO_PIN_14
#define g0_GPIO_Port GPIOB
#define b0_Pin GPIO_PIN_8
#define b0_GPIO_Port GPIOA
#define BUTTON_MODE_Pin GPIO_PIN_9
#define BUTTON_MODE_GPIO_Port GPIOA
#define BUTTON_MODIFY_Pin GPIO_PIN_10
#define BUTTON_MODIFY_GPIO_Port GPIOA
#define BUTTON_SAVE_Pin GPIO_PIN_11
#define BUTTON_SAVE_GPIO_Port GPIOA
#define c0_Pin GPIO_PIN_12
#define c0_GPIO_Port GPIOA
#define d0_Pin GPIO_PIN_13
#define d0_GPIO_Port GPIOA
#define e0_Pin GPIO_PIN_14
#define e0_GPIO_Port GPIOA
#define f0_Pin GPIO_PIN_15
#define f0_GPIO_Port GPIOA
#define d1_Pin GPIO_PIN_3
#define d1_GPIO_Port GPIOB
#define e1_Pin GPIO_PIN_4
#define e1_GPIO_Port GPIOB
#define f1_Pin GPIO_PIN_5
#define f1_GPIO_Port GPIOB
#define g1_Pin GPIO_PIN_6
#define g1_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_7
#define EN0_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_8
#define EN1_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_9
#define EN2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
