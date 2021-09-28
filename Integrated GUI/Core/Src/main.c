/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "st7789.h"
#include <string.h>
#include <stdlib.h>
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
SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int miny, maxy, tempy, county ;
int val1[120],val2[120];



void drawgraph(float prey0,float prey1,float prey2,float xvalue0,float xvalue1,float xvalue2,
		float yvalue0,float yvalue1,float yvalue2,uint16_t width ,uint16_t height,int delayofgraph)
{
                        float j,s1 ;
	                    HAL_Delay(delayofgraph);
		    	        ST7789_DrawFilledRectangle(xvalue0, prey0, width, height, WHITE);
						j = prey0;
						for(float i = xvalue0 ;i<xvalue1;i++)
						{
						ST7789_DrawFilledRectangle(i, j, width, height, WHITE);
						s1 = slope(prey1,prey0 , xvalue1, xvalue0);
						j = j + s1;
						}
						ST7789_DrawFilledRectangle(xvalue1, prey1,width, height, WHITE);
						j = prey1;
						for(int i = xvalue1 ;i<xvalue2;i++)
						{
						ST7789_DrawFilledRectangle(i, j,width, height, WHITE);
						s1 = slope(prey2,prey1 , xvalue2, xvalue1);
						j = j + s1;
						}
		    	  ///////////////////////////
		 	            ST7789_DrawFilledRectangle(xvalue0, yvalue0, width, height, BLACK);
		 	  			j = yvalue0;
		 	  			for(float i = xvalue0 ;i<xvalue1;i++)
		 	  			{
		 	  			ST7789_DrawFilledRectangle(i, j, width, height, BLACK);
		 	  			s1 = slope(yvalue1,yvalue0 ,xvalue1,xvalue0);
		 	  			j = j + s1;
		 	  			}
		 	  			ST7789_DrawFilledRectangle(xvalue1, yvalue1,width, height, BLACK);
		 	  			j = yvalue1;
		 	  			for(int i = xvalue1 ;i<xvalue2;i++)
		 	  			{
		 	  			ST7789_DrawFilledRectangle(i, j,width, height, BLACK);
		 	  			s1 = slope(yvalue2,yvalue1 , xvalue2, xvalue1);
		 	  			j = j + s1;
		 	  			}

}


void drawgraph2(float prey0,float prey1,float prey2,float prey3,float prey4,float xvalue0,float xvalue1,float xvalue2,float xvalue3,float xvalue4,
		float yvalue0,float yvalue1,float yvalue2,float yvalue3,float yvalue4,uint16_t width ,uint16_t height,int delayofgraph)
{
                        float j,s1 ;
	                    HAL_Delay(delayofgraph);
		    	        ST7789_DrawFilledRectangle(xvalue0, prey0, width, height, WHITE);
						j = prey0;
						for(float i = xvalue0 ;i<xvalue1;i++)
						{
						ST7789_DrawFilledRectangle(i, j, width, height, WHITE);
						s1 = slope(prey1,prey0 , xvalue1, xvalue0);
						j = j + s1;
						}
						ST7789_DrawFilledRectangle(xvalue1, prey1,width, height, WHITE);
						j = prey1;
						for(int i = xvalue1 ;i<xvalue2;i++)
						{
						ST7789_DrawFilledRectangle(i, j,width, height, WHITE);
						s1 = slope(prey2,prey1 , xvalue2, xvalue1);
						j = j + s1;
						}
						ST7789_DrawFilledRectangle(xvalue2, prey2,width, height, WHITE);
						j = prey2;
						for(int i = xvalue2 ;i<xvalue3;i++)
						{
						ST7789_DrawFilledRectangle(i, j,width, height, WHITE);
						s1 = slope(prey3,prey2 , xvalue3, xvalue2);
						j = j + s1;
						}
						ST7789_DrawFilledRectangle(xvalue3, prey3,width, height, WHITE);
						j = prey3;
						for(int i = xvalue3 ;i<xvalue4;i++)
						{
						ST7789_DrawFilledRectangle(i, j,width, height, WHITE);
						s1 = slope(prey4,prey3 , xvalue4, xvalue3);
						j = j + s1;
						}

		    	  ///////////////////////////
		 	            ST7789_DrawFilledRectangle(xvalue0, yvalue0, width, height, BLACK);
		 	  			j = yvalue0;
		 	  			for(float i = xvalue0 ;i<xvalue1;i++)
		 	  			{
		 	  			ST7789_DrawFilledRectangle(i, j, width, height, BLACK);
		 	  			s1 = slope(yvalue1,yvalue0 ,xvalue1,xvalue0);
		 	  			j = j + s1;
		 	  			}
		 	  			ST7789_DrawFilledRectangle(xvalue1, yvalue1,width, height, BLACK);
		 	  			j = yvalue1;
		 	  			for(int i = xvalue1 ;i<xvalue2;i++)
		 	  			{
		 	  			ST7789_DrawFilledRectangle(i, j,width, height, BLACK);
		 	  			s1 = slope(yvalue2,yvalue1 , xvalue2, xvalue1);
		 	  			j = j + s1;
		 	  			}
		 	  			ST7789_DrawFilledRectangle(xvalue2, yvalue2, width, height, BLACK);
						j = yvalue2;
						for(float i = xvalue2 ;i<xvalue3;i++)
						{
						ST7789_DrawFilledRectangle(i, j, width, height, BLACK);
						s1 = slope(yvalue3,yvalue2 ,xvalue3,xvalue2);
						j = j + s1;
						}
						ST7789_DrawFilledRectangle(xvalue3, yvalue3,width, height, BLACK);
						j = yvalue3;
						for(int i = xvalue3 ;i<xvalue4;i++)
						{
						ST7789_DrawFilledRectangle(i, j,width, height, BLACK);
						s1 = slope(yvalue4,yvalue3 , xvalue4, xvalue3);
						j = j + s1;
						}



}



void fillgraph(float x ,float y,uint16_t width ,uint16_t height )
				{
				ST7789_DrawFilledRectangle(x, y,width, height,BLACK);
						for(float i = y;i<=214;i++)
						{
						ST7789_DrawFilledRectangle(x, i,width, height,BLACK);
						}
				}


void cleargraph(float x ,float y,uint16_t width ,uint16_t height )
				{
				ST7789_DrawFilledRectangle(x, y,width, height,WHITE);
						for(float i = y;i<=214;i++)
						{
						ST7789_DrawFilledRectangle(x, i,width, height,WHITE);
						}
				}

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
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  ST7789_Init();
  ST7789_Fill_Color(WHITE);

  ST7789_WriteString(40,70, "CAPNOGRAPHY", Font_16x26, BLUE,WHITE);
  ST7789_WriteString(90,100, "AgVa", Font_16x26, RED,WHITE);
  ST7789_WriteString(40,130, "Healthcare", Font_16x26, BLACK,WHITE);
  HAL_Delay(4000);
  ST7789_Fill_Color(WHITE);




 // int i =0 , j = 0;
   char min[10];
   char etco2[10];
   //ST7789_WriteStringk(30, 60, "0", Font_32x60, BLACK, WHITE);


   ST7789_Fill_Color(WHITE);

   //battery
   ST7789_DrawImage(160, 10, 69, 34, (uint16_t *)unfillbattery);
  // ST7789_DrawFilledRectangle(160, 0,40,40, GREEN);
   ST7789_WriteString(10, 10, "ETCO2", Font_16x26, BLACK, WHITE);
   ST7789_WriteString(40, 40, "mmHg", Font_11x18, BLACK, WHITE);
 //  ST7789_DrawImage(170, 0, 69, 34, (uint16_t *)btfull_1);//battery full
   ST7789_WriteString(170, 70, "/min", Font_16x26, BLACK, WHITE);
 //  ST7789_DrawImage(90, 30, 75, 77, (uint16_t *)lungs_75);//lungs
//   ST7789_WriteStringk(30, 60, "36", Font_32x60, BLACK, WHITE);//eto2
   ST7789_WriteString(190, 100, "6", Font_16x26, BLACK, WHITE);//mins

 // ST7789_WriteString(5,70, "Capnography", Font_16x26, BLUE,WHITE);
    ST7789_WriteString(5,224, "0", Font_7x10, BLACK, WHITE);
    ST7789_DrawFilledRectangle(50, 223, 2, 8, BLACK);
	 // ST7789_WriteString(50,224, "2", Font_7x10, BLACK, WHITE);
	  //ST7789_WriteString(100,224, "4", Font_7x10, BLACK, WHITE);
	  ST7789_DrawFilledRectangle(100, 223, 2, 8, BLACK);
	 // ST7789_WriteString(150,224, "6", Font_7x10, BLACK, WHITE);
	  ST7789_DrawFilledRectangle(150, 223, 2, 8, BLACK);
	 // ST7789_WriteString(200,224, "8", Font_7x10, BLACK, WHITE);
	  ST7789_DrawFilledRectangle(200, 223, 2, 8, BLACK);
	  ST7789_WriteString(210,224, " Sec", Font_7x10, BLACK, WHITE);
	  ST7789_WriteString(0,185, "30", Font_7x10, BLACK, WHITE);
	  ST7789_DrawFilledRectangle(16, 187, 6, 2, BLACK);
	  ST7789_WriteString(0,150, "60", Font_7x10, BLACK, WHITE);
	  ST7789_DrawFilledRectangle(16, 155, 6, 2, BLACK);
	  ST7789_WriteString(0,140, "ETCO2", Font_7x10, BLACK, WHITE);


uint16_t i =10;
uint16_t c, n;
n = 10;
float s1;
float j = 190;

float x[150] ,temp =30;


     for(int i = 0  ;i <= 105 ;i++)
     {
    	 x[i]=temp;
    	 temp = temp+2;
     }


float ran[100];

for(int i = 150 ;i<240;i++)
{
ST7789_DrawFilledRectangle(20, i, 2, 2, BLACK);

}
for(int i = 0 ;i<230;i++)
{
ST7789_DrawFilledRectangle(i, 220, 2, 2, BLACK);
}

/*
x[0]=30;
x[1]=50;
x[2]=70;
x[3]=90;
x[4]=110;
x[5]=130;
x[6]=150;
x[7]=170,
x[8]=190,
x[9]=210,
x[10]=215;
x[11]=220;
*/
float m;

int cnt = 0;
float y[100], y1[100],y2[100],y3[100],y4[100];
uint32_t delaytest1 = 100;

for(int i = 0 ; i <=105;i++)
{
	  y2[i] = 170;
}

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
	  float c, n;
	 	  float k[103];
	 	  int a=0;
	 	   // printf("Ten random numbers in [1,100]\n");

	 	    for (c = 1; c <= 1000; c++) {
	 	      n = rand() % 200 + 1;
	 	     // printf("%f\n", n);
	 	      if(n >160)
	 	      {
	 	      k[a]= n;
	 	     //  printf("number %f\n", k[a]);
	 	      a = a +1;
	 	      }
	 	      if(a>103)
	 	      {
	 	          a=0;
	 	      }

	 	    }


/*
	 	    for(int i = 0 ; i<=100;i++)
	 	    {
	 	    	y[i]=k[i];
	 	    }

*/


//              0   1    2   3   4   5  6    7   8  9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25
float rand1[]={214,214,212,206,192,176,172,170,170,170,170,170,170,170,170,170,170,170,170,170,176,192,206,212,214,214,
//             26  27   28  29  30  31  32  33  34  35  36  37 38   39  40  41  42  43  44  45  46  47  48  49  50
               214,214,214,212,206,192,176,170,170,170,170,170,170,170,170,170,170,170,170,180,190,210,214,214,214,
//             51  52   53  54  55  56  57  58 59  60  61  62  63  64  65  66   67  68  69  70  71 72   73  74  75
               214,212,206,192,176,172,170,170,170,170,170,170,170,170,170,170,170,170,170,176,192,206,212,214,214,
//             76  77  78  79   80  81  82  83  84  85  86  87  88  89  90  91 92  93  94   95  96  97  98  99  100
               214,214,200,190,176,170,170,170,170,170,170,170,170,170,170,170,170,170,170,180,190,210,214,214,214};


for(i=0;i<=100;i++)
{
   y[i]=rand1[i];
}


	 	  uint16_t widthrt =1 , heightrt =1;










	 	 //	  ST7789_Fill_Color(WHITE);






	      while(cnt==0)
	      {
					for(int i =0 ;i <=100;i++)
					{
						if(i==20)
						{
							ST7789_WriteStringk(30, 60, "36", Font_32x60, BLACK, WHITE);//eto2
						}
						else if(i == 44)
						{
							ST7789_WriteStringk(30, 60, "34", Font_32x60, BLACK, WHITE);//eto2
						}
						else if(i == 69)
							{
								ST7789_WriteStringk(30, 60, "37", Font_32x60, BLACK, WHITE);//eto2
							}
						else if(i == 94)
							{
								ST7789_WriteStringk(30, 60, "35", Font_32x60, BLACK, WHITE);//eto2
							}

					cleargraph(x[i] ,y2[i],widthrt ,heightrt );
					fillgraph(x[i] ,y[i],widthrt ,heightrt );
					}



					for(int i = 0 ;i<=100;i++)
					{
						y1[i]=y[i];
					}
	 	  			cnt=cnt+1;
	       }


	      while(cnt==2)
				{

	    	  //              0   1    2   3   4   5  6    7   8  9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25
	    	  float rand2[]={214,214,212,206,192,176,172,160,160,160,160,160,160,160,160,160,160,160,160,160,176,192,206,212,214,214,
	    	  //             26  27   28  29  30  31  32  33  34  35  36  37 38   39  40  41  42  43  44  45  46  47  48  49  50
	    	                 214,214,214,212,206,192,176,160,160,160,160,160,160,160,160,160,160,160,160,180,190,210,214,214,214,
	    	  //             51  52   53  54  55  56  57  58 59  60  61  62  63  64  65  66   67  68  69  70  71 72   73  74  75
	    	                 214,212,206,192,176,172,160,160,160,160,160,160,160,160,160,160,160,160,160,176,192,206,212,214,214,
	    	  //             76  77  78  79   80  81  82  83  84  85  86  87  88  89  90  91 92  93  94   95  96  97  98  99  100
	    	                 214,214,200,190,176,160,160,160,160,160,160,160,160,160,160,160,160,160,160,180,190,210,214,214,214};


                                for(i=0;i<=100;i++)
                                {
                                	y[i]=rand2[i];
                                }

	    		                for(int i =0 ;i <=100;i++)
	    						{
	    						cleargraph(x[i] ,y1[i],widthrt ,heightrt );
	    						fillgraph(x[i] ,y[i],widthrt ,heightrt );
	    						}
	    		                ST7789_WriteStringk(30, 60, "54", Font_32x60, BLACK, WHITE);//eto2

	    		                for(int i = 0 ; i <=100;i++)
	    		                {
	    		                	y2[i]= y[i];
	    		                }

					  cnt = cnt =-1;

	      	  }


cnt = cnt+1;







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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
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
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV16;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA8 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
