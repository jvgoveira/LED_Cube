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
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define T_ligado 100
#define T_desligado 1
#define Transissao 75

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
	int y=1,x=0;
	int vtec=0;
	
	void controle(void);
	void vartec(void);

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

	int matriz [9][3]= {{0,0,0},{0,1,0},{0,0,0},	//	coluna (de 1 a 9) x layer(de 3 a 1)
											{0,1,0},{1,1,1},{0,1,0},
											{0,0,0},{0,1,0},{0,0,0}};
	
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
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */
	
	HAL_TIM_Base_Start_IT(&htim6);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		switch(vtec)
		{
			case 1: //CIMA PARA BAIXO:
						  HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
							 
							HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_RESET);
							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_RESET);
							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_RESET);
							HAL_Delay(Transissao);
							
							//BAIXO PARA CIMA:
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
		
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_RESET);

							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_SET);
							
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_RESET);

							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_SET);
							
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_RESET);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
							
							HAL_Delay(Transissao);
		
						
						
							//ESQUERDA PARA DIREITA 
							HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_SET);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
							HAL_Delay(Transissao);
			
			
							//DIREIRA PARA ESQUERDA
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_RESET);
							HAL_Delay(Transissao);
			
			
							//FRENTE PARA TRÁS
							HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_SET);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);	
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
							HAL_Delay(Transissao);
			
			
							// TRÁS PARA FRENTE 
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
							HAL_Delay(T_desligado);
							
							HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_RESET);
							HAL_Delay(Transissao);
							break;
				
			case 2: //ESPIRAL
							HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_SET);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
							HAL_Delay(Transissao);
							
							
							HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_SET);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
							HAL_Delay(Transissao);
							
							
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_SET);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
							HAL_Delay(Transissao);
							
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_RESET);
							
							
							
							//ESPIRAL INVERSA 
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_SET);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
							HAL_Delay(Transissao);
							
							
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_SET);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
							HAL_Delay(Transissao);
							
							
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_SET);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
							HAL_Delay(T_ligado);
							
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
							HAL_Delay(Transissao);
							
							HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_RESET);
							break;
							
		case 3: //CUBINHOS
						HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_SET);
						
						HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
						HAL_Delay(T_ligado);
						
						HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
						HAL_Delay(Transissao);
						
						HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
						HAL_Delay(T_ligado);
						
						HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
						HAL_Delay(T_desligado);
						
						HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
						HAL_Delay(T_ligado);
						
						HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
						HAL_Delay(T_desligado);
						
						HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
						HAL_Delay(T_ligado);
						
						HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
						HAL_Delay(T_desligado);
						
						HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_RESET);
						
						
						
						HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_SET);
						
						HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
						HAL_Delay(T_ligado);
						
						HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
						HAL_Delay(Transissao);
						
						HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
						HAL_Delay(T_ligado);
						
						HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
						HAL_Delay(T_desligado);
						
						HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
						HAL_Delay(T_ligado);
						
						HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
						HAL_Delay(T_desligado);
						
						HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_SET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_SET);
						HAL_Delay(T_ligado);
						
						HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,GPIO_PIN_RESET);
						HAL_Delay(T_desligado);
						
						HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_RESET);
						HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_RESET);
						break;
			
		}
		
		
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_3;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void controle(void)
{
		switch(x)
		{
			case 0: HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,matriz[0][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,matriz[1][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,matriz[2][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,matriz[3][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,matriz[4][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,matriz[5][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,matriz[6][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,matriz[7][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,matriz[8][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							x=1;
				break;
			
			case 1: HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,matriz[0][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,matriz[1][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,matriz[2][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,matriz[3][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,matriz[4][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,matriz[5][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,matriz[6][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,matriz[7][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,matriz[8][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							x=2;
				break;
				
			case 2: HAL_GPIO_WritePin(L1_GPIO_Port,L1_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(L2_GPIO_Port,L2_Pin,GPIO_PIN_RESET);
							HAL_GPIO_WritePin(L3_GPIO_Port,L3_Pin,GPIO_PIN_SET);
							HAL_GPIO_WritePin(C1_GPIO_Port,C1_Pin,matriz[0][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C2_GPIO_Port,C2_Pin,matriz[1][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C3_GPIO_Port,C3_Pin,matriz[2][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C4_GPIO_Port,C4_Pin,matriz[3][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C5_GPIO_Port,C5_Pin,matriz[4][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C6_GPIO_Port,C6_Pin,matriz[5][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C7_GPIO_Port,C7_Pin,matriz[6][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C8_GPIO_Port,C8_Pin,matriz[7][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							HAL_GPIO_WritePin(C9_GPIO_Port,C9_Pin,matriz[8][x] == 1 ? GPIO_PIN_SET:GPIO_PIN_RESET);
							x=0;
				break;
		}	
	
}
void vartec(void)
{
	switch(y)
	{
		case 1: HAL_GPIO_WritePin(Coluna1_GPIO_Port,Coluna1_Pin,GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(Coluna2_GPIO_Port,Coluna2_Pin,GPIO_PIN_SET);
					  HAL_GPIO_WritePin(Coluna3_GPIO_Port,Coluna3_Pin,GPIO_PIN_SET);
						if (HAL_GPIO_ReadPin(Linha1_GPIO_Port,Linha1_Pin)==0)
						{
							vtec=1;
						}
						if (HAL_GPIO_ReadPin(Linha2_GPIO_Port,Linha2_Pin)==0)
						{
							vtec=4;
						}
						if (HAL_GPIO_ReadPin(Linha3_GPIO_Port,Linha3_Pin)==0)
						{
							vtec=7;
						}
						if (HAL_GPIO_ReadPin(Linha4_GPIO_Port,Linha4_Pin)==0)
						{
							vtec=0;
						}
						y=2;
				break;
					
		case 2: HAL_GPIO_WritePin(Coluna1_GPIO_Port,Coluna1_Pin,GPIO_PIN_SET);
					  HAL_GPIO_WritePin(Coluna2_GPIO_Port,Coluna2_Pin,GPIO_PIN_RESET);
					  HAL_GPIO_WritePin(Coluna3_GPIO_Port,Coluna3_Pin,GPIO_PIN_SET);
						if (HAL_GPIO_ReadPin(Linha1_GPIO_Port,Linha1_Pin)==0)
						{
							vtec=2;
						}
						if (HAL_GPIO_ReadPin(Linha2_GPIO_Port,Linha2_Pin)==0)
						{
							vtec=5;
						}
						if (HAL_GPIO_ReadPin(Linha3_GPIO_Port,Linha3_Pin)==0)
						{
							vtec=8;
						}
						if (HAL_GPIO_ReadPin(Linha4_GPIO_Port,Linha4_Pin)==0)
						{
							vtec=0;
						}
						y=3;
				break;
		
		case 3: HAL_GPIO_WritePin(Coluna1_GPIO_Port,Coluna1_Pin,GPIO_PIN_SET);
					  HAL_GPIO_WritePin(Coluna2_GPIO_Port,Coluna2_Pin,GPIO_PIN_SET);
					  HAL_GPIO_WritePin(Coluna3_GPIO_Port,Coluna3_Pin,GPIO_PIN_RESET);
						if (HAL_GPIO_ReadPin(Linha1_GPIO_Port,Linha1_Pin)==0)
						{
							vtec=3;
						}
						if (HAL_GPIO_ReadPin(Linha2_GPIO_Port,Linha2_Pin)==0)
						{
							vtec=6;
						}
						if (HAL_GPIO_ReadPin(Linha3_GPIO_Port,Linha3_Pin)==0)
						{
							vtec=9;
						}
						if (HAL_GPIO_ReadPin(Linha4_GPIO_Port,Linha4_Pin)==0)
						{
							vtec=0;
						}
						y=1;
				break;
		
	}
	
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	vartec();
	//controle();
	
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

