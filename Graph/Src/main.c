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


float slope(float y2 ,float y1  ,float x2 , float x1)

{   float m ;

 m = (y2-y1)/(x2-x1);
return m;

}
int bet2num2val1 (int i , int j)
{
int min, max, temp, count;
    int x = 0, val[150];
    printf("Enter 2 positive numbers\n");
    min = i ;
    max = j ;

    if(min > max)
    {
        temp = min;
        min  = max;
        max  = temp;
    }

    printf("Natural numbers from %d to %d are:\n", min, max);

    for(count = min; count <= max; count++)
    {
        printf("%d\n", count);
        val1[x]= count;

      printf("array valuex =  %d\n", val[x]);
      x = x +1;
    }
}

int bet2num2val2 (int i , int j)
{

    int y = 0;
    printf("Enter 2 positive numbers\n");
    miny = i ;
    maxy = j ;

    if(miny > maxy)
    {
        tempy = miny;
        miny  = maxy;
        maxy  = tempy;
    }

    printf("Natural numbers from %d to %d are:\n", miny, maxy);

    for(county = miny; county <= maxy; county++)
    {
        printf("%d\n", county);
        val2[y]= county;

      printf("array valuey =  %d\n", val2[y]);
      y = y +1;
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
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
/*
  int i =0 , j = 0;
  char min[10];
  char etco2[10];

  ST7789_Fill_Color(WHITE);
  ST7789_WriteString(10, 10, "ETCO2", Font_16x26, BLACK, WHITE);
  ST7789_WriteString(40, 40, "mmHg", Font_11x18, BLACK, WHITE);
  ST7789_DrawImage(170, 0, 69, 34, (uint16_t *)btfull_1);
  ST7789_WriteString(170, 70, "/min", Font_16x26, BLACK, WHITE);
  ST7789_DrawImage(90, 30, 75, 77, (uint16_t *)lungs_75);

  j = 96;
  i = 96;
  itoa(i, min, 10);
	  	  ST7789_WriteString(190, 100, min, Font_16x26, BLACK, WHITE);
	  	 ST7789_WriteString(20, 60, etco2, Font_16x26, BLACK, WHITE);
	  	ST7789_WriteStringk(30, 60, etco2, Font_32x60, BLACK, WHITE);

	  	*/
      ST7789_WriteString(5,70, "Capnography", Font_16x26, BLUE,WHITE);
      ST7789_WriteString(5,224, "0", Font_7x10, BLACK, WHITE);
	  ST7789_WriteString(50,224, "2", Font_7x10, BLACK, WHITE);
	  ST7789_WriteString(100,224, "4", Font_7x10, BLACK, WHITE);
	  ST7789_WriteString(150,224, "6", Font_7x10, BLACK, WHITE);
	  ST7789_WriteString(200,224, "8", Font_7x10, BLACK, WHITE);
	  ST7789_WriteString(210,224, " Sec", Font_7x10, BLACK, WHITE);
	  ST7789_WriteString(0,185, "30", Font_7x10, BLACK, WHITE);
	  ST7789_WriteString(0,150, "60", Font_7x10, BLACK, WHITE);
	  ST7789_WriteString(0,140, "ETCO2", Font_7x10, BLACK, WHITE);
  uint16_t i =10;
  uint16_t c, n;
n = 10;
float s1;
float j = 190;
float x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20,x21;
float y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12,y13,y14,y15,y16,y17,y18,y19,y20,y21;
x1=30;
x2=39;
x3=48;
x4=57;
x5=66;
x6=75;
x7=84;
x8=93,
x9=102,
x10=111,
x11=120;
x12=129;
x13=138;
x14=147;
x15=156;
x16=165;
x17=174;
x18=183;
x19=192;
x20=201;
x21=210;

y1=214,y2=214,y3=214,y4=200,y5=170,y6=170,y7=170,y8=179,y9=188,y10=200,
y11=200,y12=214,y13=200,y14=170,y15=170,y16=170,y17=170,y18=200,y19=214,y20=214,y21=214;
float ran[100];
int cnt;
for(int i = 150 ;i<240;i++)
	  	   {
	  		   ST7789_DrawFilledRectangle(20, i, 2, 2, BLACK);

	  	   }
	  for(int i = 0 ;i<230;i++)
	 	  	   {
	 	  		   ST7789_DrawFilledRectangle(i, 220, 2, 2, BLACK);

	 	  	   }

  while (1)
  {//ST7789_Fill_Color(WHITE);

/*

	  float c, n ;
	  float k[25];
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
	      if(a>10)
	      {
	          a=0;
	      }

	    }
	    y1 = k[0];
	    y2 = k[1];
	    y3 = k[2];
	    y4 = k[3];
	    y5 = k[4];
	    y6 = k[5];
	    y7 = k[6];
	    y8 = k[7];
	    y9 = k[8];
		y10 = k[9];
		y11 = k[10];

*/


	  y1=214,y2=214,y3=214,y4=200,y5=170,y6=170,y7=170,y8=170,y9=205,y10=214,
	  y11=214,y12=214,y13=200,y14=170,y15=170,y16=170,y17=170,y18=200,y19=214,y20=214,y21=214;

	   int w=19 , h=60;

			ST7789_DrawFilledRectangle(x1, y1, 3, 3, BLACK);
			j = y1;
			for(float i = x1 ;i<x2;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3, BLACK);
			s1 = slope(y2,y1 , x2, x1);
			j = j + s1;
			}
			ST7789_DrawFilledRectangle(x2, y2, 3, 3, BLACK);
			j = y2;

			// ST7789_DrawFilledRectangle(30,160,w, h, WHITE);
			for(int i = x2 ;i<x3;i++)
			{


			ST7789_DrawFilledRectangle(i, j, 3, 3, BLACK);
			s1 = slope(y3,y2 , x3, x2);
			j = j + s1;
			}
			ST7789_DrawFilledRectangle(x3, y3, 3, 3,BLACK);
			j = y3;
			// ST7789_DrawFilledRectangle(50,160,w, h, WHITE);
			for(int i = x3 ;i<x4;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3, BLACK);

			s1 = slope(y4,y3 , x4, x3);
			j = j + s1;
			}
			ST7789_DrawFilledRectangle(x4, y4, 3, 3, BLACK);
			j = y4;

			for(int i = x4 ;i<x5;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3, BLACK);
			s1 = slope(y5,y4 , x5, x4);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x5, y5, 3, 3,BLACK);
			j = y5;

			for(int i = x5 ;i<x6;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3, BLACK);
			s1 = slope(y6,y5 , x6, x5);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x6, y6, 3, 3, BLACK);
			j = y6;

			for(int i = x6 ;i<x7;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3, BLACK);
			s1 = slope(y7,y6 , x7, x6);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x7, y7, 3, 3, BLACK);
			j = y7;

			for(int i = x7 ;i<x8;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3, BLACK);
			s1 = slope(y8,y7 , x8, x7);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x8, y8, 3, 3, BLACK);
			j = y8;

			for(int i = x8 ;i<x9;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y9,y8 , x9, x8);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x9, y9, 3, 3, BLACK);
			j = y9;

			for(int i = x9 ;i<x10;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y10,y9 , x10, x9);
			j = j + s1;

			}

			ST7789_DrawFilledRectangle(x10, y10, 3, 3, BLACK);
			j = y10;
			for(int i = x10 ;i<x11;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y11,y10 , x11, x10);
			j = j + s1;

			}

			ST7789_DrawFilledRectangle(x11, y11, 3, 3,BLACK);
			j = y11;
			for(int i = x11 ;i<x12;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y12,y11 , x12, x11);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x12, y12, 3, 3,BLACK);
			j = y12;
			for(int i = x12 ;i<x13;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y13,y12 , x13, x12);
			j = j + s1;

			}

			ST7789_DrawFilledRectangle(x13, y13, 3, 3,BLACK);
			j = y13;
			for(int i = x13 ;i<x14;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y14,y13 , x14, x13);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x14, y14, 3, 3,BLACK);
			j = y14;
			for(int i = x14 ;i<x15;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y15,y14 , x15, x14);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x15, y15, 3, 3,BLACK);
			j = y15;
			for(int i = x15 ;i<x16;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y16,y15 , x16, x15);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x16, y16, 3, 3,BLACK);
			j = y16;
			for(int i = x16 ;i<x17;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y17,y16 , x17, x16);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x17, y17, 3, 3,BLACK);
			j = y17;
			for(int i = x17 ;i<x18;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y18,y17 , x18, x17);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x18, y18, 3, 3,BLACK);
			j = y18;
			for(int i = x18 ;i<x19;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y19,y18 , x19, x18);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x19, y19, 3, 3,BLACK);
			j = y19;
			for(int i = x19 ;i<x20;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y20,y19 , x20, x19);
			j = j + s1;

			}
			ST7789_DrawFilledRectangle(x20, y20, 3, 3,BLACK);
			j = y20;
			for(int i = x20 ;i<x21;i++)
			{
			ST7789_DrawFilledRectangle(i, j, 3, 3,BLACK);
			s1 = slope(y21,y20 , x21, x20);
			j = j + s1;

			}


  //clear
		ST7789_DrawFilledRectangle(x1, y1, 3, 3, WHITE);
		j = y1;
		for(float i = x1 ;i<x2;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3, WHITE);
		s1 = slope(y2,y1 , x2, x1);
		j = j + s1;
		}
		ST7789_DrawFilledRectangle(x2, y2, 3, 3, WHITE);
		j = y2;

		// ST7789_DrawFilledRectangle(30,160,w, h, WHITE);
		for(int i = x2 ;i<x3;i++)
		{


		ST7789_DrawFilledRectangle(i, j, 3, 3, WHITE);
		s1 = slope(y3,y2 , x3, x2);
		j = j + s1;
		}
		ST7789_DrawFilledRectangle(x3, y3, 3, 3,WHITE);
		j = y3;
		// ST7789_DrawFilledRectangle(50,160,w, h, WHITE);
		for(int i = x3 ;i<x4;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3, WHITE);

		s1 = slope(y4,y3 , x4, x3);
		j = j + s1;
		}
		ST7789_DrawFilledRectangle(x4, y4, 3, 3, WHITE);
		j = y4;

		for(int i = x4 ;i<x5;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3, WHITE);
		s1 = slope(y5,y4 , x5, x4);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x5, y5, 3, 3,WHITE);
		j = y5;

		for(int i = x5 ;i<x6;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3, WHITE);
		s1 = slope(y6,y5 , x6, x5);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x6, y6, 3, 3, WHITE);
		j = y6;

		for(int i = x6 ;i<x7;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3, WHITE);
		s1 = slope(y7,y6 , x7, x6);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x7, y7, 3, 3, WHITE);
		j = y7;

		for(int i = x7 ;i<x8;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3, WHITE);
		s1 = slope(y8,y7 , x8, x7);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x8, y8, 3, 3, WHITE);
		j = y8;

		for(int i = x8 ;i<x9;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y9,y8 , x9, x8);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x9, y9, 3, 3, WHITE);
		j = y9;

		for(int i = x9 ;i<x10;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y10,y9 , x10, x9);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x10, y10, 3, 3, WHITE);
		j = y10;

		for(int i = x10 ;i<x11;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y11,y10 , x11, x10);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x11, y11, 3, 3,WHITE);
		j = y11;
		for(int i = x11 ;i<x12;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y12,y11 , x12, x11);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x12, y12, 3, 3,WHITE);
		j = y12;
		for(int i = x12 ;i<x13;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y13,y12 , x13, x12);
		j = j + s1;

		}

		ST7789_DrawFilledRectangle(x13, y13, 3, 3,WHITE);
		j = y13;
		for(int i = x13 ;i<x14;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y14,y13 , x14, x13);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x14, y14, 3, 3,WHITE);
		j = y14;
		for(int i = x14 ;i<x15;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y15,y14 , x15, x14);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x15, y15, 3, 3,WHITE);
		j = y15;
		for(int i = x15 ;i<x16;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y16,y15 , x16, x15);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x16, y16, 3, 3,WHITE);
		j = y16;
		for(int i = x16 ;i<x17;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y17,y16 , x17, x16);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x17, y17, 3, 3,WHITE);
		j = y17;
		for(int i = x17 ;i<x18;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y18,y17 , x18, x17);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x18, y18, 3, 3,WHITE);
		j = y18;
		for(int i = x18 ;i<x19;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y19,y18 , x19, x18);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x19, y19, 3, 3,WHITE);
		j = y19;
		for(int i = x19 ;i<x20;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y20,y19 , x20, x19);
		j = j + s1;

		}
		ST7789_DrawFilledRectangle(x20, y20, 3, 3,WHITE);
		j = y20;
		for(int i = x20 ;i<x21;i++)
		{
		ST7789_DrawFilledRectangle(i, j, 3, 3,WHITE);
		s1 = slope(y21,y20 , x21, x20);
		j = j + s1;

		}




				  				   /////////
	// ST7789_WriteStringk(30, 60, "77", Font_32x60, BLACK, WHITE);

	  // ST7789_Test();
	 // ST7789_Fill_Color(WHITE);

	 // ST7789_DrawImage(170, 0, 69, 34, (uint16_t *)unfillbattery);
	//  ST7789_DrawImage(170, 0, 69, 34, (uint16_t *)lowbattery_1);
	//  ST7789_DrawImage(170, 90, 50, 50, (uint16_t *)btempty);


	  //ST7789_DrawImage(170, 80, 150, 150, (uint16_t *)cap150);
	 // ST7789_DrawImage(0, 0, 128, 128, (uint16_t *)saber);

/*
          if(i>99)
          {
        	  i = 0;
        	  ST7789_WriteString(190, 100, "00", Font_16x26, WHITE, WHITE);
          }
          if(j>99)
               {
                  	  j = 0;
                  	ST7789_WriteStringk(30, 60, "00", Font_32x60, WHITE, WHITE);
               }

	  	  itoa(i, min, 10);
	  	  ST7789_WriteString(190, 100, min, Font_16x26, BLACK, WHITE);

	  	  itoa(j, etco2, 10);
	  	  ST7789_WriteStringk(30, 60, etco2, Font_32x60, BLACK, WHITE);
	  	  HAL_Delay(500);
	  	  i = i+1;
	  	  j = j+1;

*/
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
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
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
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

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4;
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
