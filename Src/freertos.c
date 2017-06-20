/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */     
#include "adc.h"
/* USER CODE END Includes */

/* Variables -----------------------------------------------------------------*/
osThreadId led1TaskHandle;
osThreadId led2TaskHandle;
osThreadId led3TaskHandle;
osThreadId led4TaskHandle;
osThreadId printfTaskHandle;
osThreadId sensor1TaskHandle;

/* USER CODE BEGIN Variables */
uint8_t  cPrint[1024];
volatile uint16_t uiADC[3];
/* USER CODE END Variables */

/* Function prototypes -------------------------------------------------------*/
void vLed1Task(void const * argument);
void vLed2Task(void const * argument);
void vLed3Task(void const * argument);
void vLed4Task(void const * argument);
void vPrintfTask(void const * argument);
void vSensor1Task(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/* Hook prototypes */

/* Init FreeRTOS */

void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of led1Task */
  osThreadDef(led1Task, vLed1Task, osPriorityNormal, 0, 128);
  led1TaskHandle = osThreadCreate(osThread(led1Task), NULL);

  /* definition and creation of led2Task */
  osThreadDef(led2Task, vLed2Task, osPriorityNormal, 0, 128);
  led2TaskHandle = osThreadCreate(osThread(led2Task), NULL);

  /* definition and creation of led3Task */
  osThreadDef(led3Task, vLed3Task, osPriorityNormal, 0, 128);
  led3TaskHandle = osThreadCreate(osThread(led3Task), NULL);

  /* definition and creation of led4Task */
  osThreadDef(led4Task, vLed4Task, osPriorityNormal, 0, 128);
  led4TaskHandle = osThreadCreate(osThread(led4Task), NULL);

  /* definition and creation of printfTask */
  osThreadDef(printfTask, vPrintfTask, osPriorityNormal, 0, 128);
  printfTaskHandle = osThreadCreate(osThread(printfTask), NULL);

  /* definition and creation of sensor1Task */
  osThreadDef(sensor1Task, vSensor1Task, osPriorityAboveNormal, 0, 128);
  sensor1TaskHandle = osThreadCreate(osThread(sensor1Task), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
}

/* vLed1Task function */
__weak void vLed1Task(void const * argument)
{

  /* USER CODE BEGIN vLed1Task */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
    osDelay(10);
  }
  /* USER CODE END vLed1Task */
}

/* vLed2Task function */
void vLed2Task(void const * argument)
{
  /* USER CODE BEGIN vLed2Task */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
    osDelay(100);
  }
  /* USER CODE END vLed2Task */
}

/* vLed3Task function */
void vLed3Task(void const * argument)
{
  /* USER CODE BEGIN vLed3Task */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(LED3_GPIO_Port,LED3_Pin);
    osDelay(100);
  }
  /* USER CODE END vLed3Task */
}

/* vLed4Task function */
void vLed4Task(void const * argument)
{
  /* USER CODE BEGIN vLed4Task */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(LED4_GPIO_Port,LED4_Pin);
    osDelay(100);
  }
  /* USER CODE END vLed4Task */
}

/* vPrintfTask function */
void vPrintfTask(void const * argument)
{
  /* USER CODE BEGIN vPrintfTask */
  /* Infinite loop */
  for(;;)
  {
   for(uint8_t i=0;i<3;i++)
    {
      printf("adc :%d \n",uiADC[i]);
    }
    osDelay(500);
  }
  /* USER CODE END vPrintfTask */
}

/* vSensor1Task function */
void vSensor1Task(void const * argument)
{
  /* USER CODE BEGIN vSensor1Task */
  /* Infinite loop */
     /* Start ADC conversion on regular group with transfer by DMA */
if (HAL_ADC_Start_DMA(&hadc1,
                        (uint32_t *)uiADC,
                        2
                       ) != HAL_OK)
  {
    /* Start Error */
    Error_Handler();
  }
  /* Infinite loop */
  for(;;)
  {
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1,0xff); 
    
//    uiADC = HAL_ADC_GetValue(&hadc1);
    osDelay(1);
  /* USER CODE END vSensor1Task */
}

/* USER CODE BEGIN Application */
     

}

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
