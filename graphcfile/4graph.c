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



/*
  ST7789_WriteString(5,70, "Capnography", Font_16x26, BLUE,WHITE);
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
	  */
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


/*
y1=214,
y2=214,
y3=214,
y4=200,
y5=170,
y6=170,
y7=170,
y8=179,
y9=188,
y10=200,
y11=200,
y12=214,
y13=200,
y14=170,
y15=170,
y16=170,
y17=170,
y18=200,
y19=214,
y20=214,
y21=214;
y22=214;
y23=214;
y24=200;
y25=210;
y26=210;
y27=210;
y28=210;
y29=210;
y30=210;
y31=210;
y32=210;
y33=210;
y34=210;
y35=210;
y36=210;
y37=210;
y38=210;
y39=210;
y40=210;
*/
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
	 	  float k[41];
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
	 	      if(a>83)
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
/*

				y[0]=k[0];
				y[1]=k[1];
				y[2]=k[2];
				y[3]=k[3];
				y[4]=k[4];
				y[5]=k[5];
				y[6]=k[6];
				y[7]=k[7];
				y[8]=k[8];
				y[9]=k[9];
				y[10]=k[10];
				y[11]=k[11];
				y[12]=k[12];
				y[13]=k[13];
				y[14]=k[14];
				y[15]=k[15];
				y[16]=k[16];
				y[17]=k[17];
				y[18]=k[18];
				y[19]=k[19];
				y[20]=k[20];
				y[21]=k[21];
				y[22]=k[22];
				y[23]=k[23];
				y[24]=k[24];
				y[25]=k[25];
				y[26]=k[26];
				y[27]=k[27];
				y[28]=k[28];
				y[29]=k[29];
				y[30]=k[30];
				y[31]=k[31];
				y[32]=k[32];
				y[33]=k[33];
				y[34]=k[34];
				y[35]=k[35];
				y[36]=k[36];
				y[37]=k[37];
				y[38]=k[38];
				y[39]=k[39];
				y[40]=k[40];
				y[41]=k[41];
				y[42]=k[42];
				y[43]=k[43];
				y[44]=k[44];
				y[45]=k[45];
				y[46]=k[46];
				y[47]=k[47];
				y[48]=k[48];
				y[49]=k[49];
				y[50]=k[50];
				y[51]=k[51];
				y[52]=k[52];
				y[53]=k[53];
				y[54]=k[54];
				y[55]=k[55];
				y[56]=k[56];
				y[57]=k[57];
				y[58]=k[58];
				y[59]=k[59];
				y[60]=k[60];
				y[61]=k[61];
				y[62]=k[62];
				y[63]=k[63];
				y[64]=k[64];
				y[65]=k[65];
				y[66]=k[66];
				y[67]=k[67];
				y[68]=k[68];
				y[69]=k[69];
				y[70]=k[70];
				y[71]=k[71];
				y[72]=k[72];
				y[73]=k[73];
				y[74]=k[74];
				y[75]=k[75];
				y[76]=k[76];
				y[77]=k[77];
				y[78]=k[78];
				y[79]=k[79];
				y[80]=k[80];

*/





				y[0]=214;
				y[1]=214;
				y[2]=212;
				y[3]=206;
				y[4]=192;
				y[5]=176;
				y[6]=172;
				y[7]=170;
				y[8]=170;
				y[9]=170;
				y[10]=170;
				y[11]=170;
				y[12]=170;
				y[13]=170;
				y[14]=170;
				y[15]=170;
				y[16]=170;
				y[17]=170;
				y[18]=170;
				y[19]=170;
				y[20]=176;
				y[21]=192;
				y[22]=206;
				y[23]=212;
				y[24]=214;
				y[25]=214;
				y[26]=214;
				y[27]=214;
				y[28]=214;
				y[29]=212;
				y[30]=206;
				y[31]=192;
				y[32]=176;
				y[33]=170;
				y[34]=170;
				y[35]=170;
				y[36]=170;
				y[37]=170;
				y[38]=170;
				y[39]=170;
				y[40]=170;
				y[41]=170;
				y[42]=170;
				y[43]=170;
				y[44]=170;
				y[45]=180;
				y[46]=190;
				y[47]=210;
				y[48]=214;
				y[49]=214;
				y[50]=214;
				y[51]=214;
				y[52]=212;
				y[53]=206;
				y[54]=192;
				y[55]=176;
				y[56]=172;
				y[57]=170;
				y[58]=170;
				y[59]=170;
				y[60]=170;
				y[61]=170;
				y[62]=170;
				y[63]=170;
				y[64]=170;
				y[65]=170;
				y[66]=170;
				y[67]=170;
				y[68]=170;
				y[69]=170;
				y[70]=176;
				y[71]=192;
				y[72]=206;
				y[73]=212;
				y[74]=214;
				y[75]=214;
				y[76]=214;
				y[77]=214;
				y[78]=200;
				y[79]=190;
				y[80]=176;
				y[81]=170;
				y[82]=170;
				y[83]=170;
				y[84]=170;
				y[85]=170;
				y[86]=170;
				y[87]=170;
				y[88]=170;
				y[89]=170;
				y[90]=170;
				y[91]=170;
				y[92]=170;
				y[93]=170;
				y[94]=170;
				y[95]=180;
				y[96]=190;
				y[97]=210;
				y[98]=214;
				y[99]=214;
				y[100]=214;





	 	  uint16_t widthrt =1 , heightrt =1;










	 	 //	  ST7789_Fill_Color(WHITE);






	      while(cnt==0)
	      {




					for(int i =0 ;i <=100;i++)
					{
					cleargraph(x[i] ,y2[i],widthrt ,heightrt );
					fillgraph(x[i] ,y[i],widthrt ,heightrt );
					}
/*
					for(int i =0 ;i <=70;i++)
					{
					fillgraph(x[i] ,y[i],widthrt ,heightrt );
					}
*/


					for(int i = 0 ;i<=100;i++)
					{
						y1[i]=y[i];

					}



	 	  			cnt=cnt+1;

	       }


	      while(cnt==2)
				{

	    		            y[0]=214;
	    					y[1]=214;
	    					y[2]=212;
	    					y[3]=202;
	    					y[4]=190;
	    					y[5]=172;
	    					y[6]=172;
	    					y[7]=160;
	    					y[8]=160;
	    					y[9]=160;
	    					y[10]=160;
	    					y[11]=160;
	    					y[12]=160;
	    					y[13]=160;
	    					y[14]=160;
	    					y[15]=160;
	    					y[16]=160;
	    					y[17]=160;
	    					y[18]=160;
	    					y[19]=160;
	    					y[20]=160;
	    					y[21]=160;
	    					y[22]=160;
	    					y[23]=160;
	    					y[24]=160;
	    					y[25]=160;
	    					y[26]=160;
	    					y[27]=160;
	    					y[28]=160;
	    					y[29]=160;
	    					y[30]=160;
	    					y[31]=160;
	    					y[32]=160;
	    					y[33]=160;
	    					y[34]=160;
	    					y[35]=170;
	    					y[36]=190;
	    					y[37]=210;
	    					y[38]=214;
	    					y[39]=214;
	    					y[40]=214;
	    					y[41]=214;
							y[42]=214;
							y[43]=214;
							y[44]=214;
							y[45]=214;
							y[46]=214;
							y[47]=214;
							y[48]=214;
							y[49]=214;
							y[50]=214;
							y[51]=214;
							y[52]=214;
							y[53]=214;
							y[54]=214;
							y[55]=214;
							y[56]=214;
							y[57]=214;
							y[58]=214;
							y[59]=214;
							y[60]=214;
	    					y[61]=214;
							y[62]=212;
							y[63]=202;
							y[64]=190;
							y[65]=172;
							y[66]=172;
							y[67]=160;
							y[68]=160;
							y[69]=160;
							y[70]=160;
							y[71]=160;
							y[72]=160;
							y[73]=160;
							y[74]=160;
							y[75]=160;
							y[76]=160;
							y[77]=160;
							y[78]=160;
							y[79]=160;
							y[80]=160;
							y[81]=160;
							y[82]=160;
							y[83]=160;
							y[84]=160;
							y[85]=160;
							y[86]=160;
							y[87]=160;
							y[88]=160;
							y[89]=160;
							y[90]=160;
							y[91]=160;
							y[92]=160;
							y[93]=160;
							y[94]=160;
							y[95]=170;
							y[96]=190;
							y[97]=210;
							y[98]=214;
							y[99]=214;
							y[100]=214;



	    		                for(int i =0 ;i <=100;i++)
	    						{
	    						cleargraph(x[i] ,y1[i],widthrt ,heightrt );
	    						fillgraph(x[i] ,y[i],widthrt ,heightrt );
	    						}
/*
	    						for(int i =0 ;i <=70;i++)
	    						{
	    						fillgraph(x[i] ,y[i],widthrt ,heightrt );
	    						}
*/

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
