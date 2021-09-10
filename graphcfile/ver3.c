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
uint16_t i =10;
uint16_t c, n;
n = 10;
float s1;
float j = 190;
float x[41];
float y[41];


x[0]=30;
x[1]=35;
x[2]=40;
x[3]=45;
x[4]=50;
x[5]=55;
x[6]=60;
x[7]=65,
x[8]=70,
x[9]=75,
x[10]=80;
x[11]=85;
x[12]=90;
x[13]=95;
x[14]=100;
x[15]=105;
x[16]=110;
x[17]=115;
x[18]=120;
x[19]=125;
x[20]=130;
x[21]=135;
x[22]=140;
x[23]=145;
x[24]=150;
x[25]=155;
x[26]=160;
x[27]=165;
x[28]=170;
x[29]=175;
x[30]=180;
x[31]=185;
x[32]=190;
x[33]=195;
x[34]=200;
x[35]=205;
x[36]=210;
x[37]=215;
x[38]=220;
x[39]=225;

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



int cnt = 0;
float y1[20],y2[20],y3[20],y4[20];
uint32_t delaytest1 = 100;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
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
	 	      if(a>11)
	 	      {
	 	          a=0;
	 	      }

	 	    }




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

	 /*
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
	 */
	 	  uint16_t widthrt =1 , heightrt =1;


	      while(cnt==0)
	      {
	    	        ST7789_DrawFilledRectangle(x[0], y4[0], widthrt, heightrt, WHITE);
					j = y4[0];
					for(float i = x[0] ;i<x[1];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
					s1 = slope(y4[1],y4[0] , x[1], x[0]);
					j = j + s1;
					}
					ST7789_DrawFilledRectangle(x[1], y4[1],widthrt, heightrt, WHITE);
					j = y4[1];

					// ST7789_DrawFilledRectangle(30,160,w, h, WHITE);
					for(int i = x[1] ;i<x[2];i++)
					{


					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, WHITE);
					s1 = slope(y4[2],y4[1] , x[2], x[1]);
					j = j + s1;
					}
	    	  ///////////////////////////
	 	            ST7789_DrawFilledRectangle(x[0], y[0], widthrt, heightrt, BLACK);
	 	  			j = y[0];
	 	  			for(float i = x[0] ;i<x[1];i++)
	 	  			{
	 	  			ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	 	  			s1 = slope(y[1],y[0] , x[1], x[0]);
	 	  			j = j + s1;
	 	  			}
	 	  			ST7789_DrawFilledRectangle(x[1], y[1],widthrt, heightrt, BLACK);
	 	  			j = y[1];

	 	  			// ST7789_DrawFilledRectangle(30,160,w, h, WHITE);
	 	  			for(int i = x[1] ;i<x[2];i++)
	 	  			{


	 	  			ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, BLACK);
	 	  			s1 = slope(y[2],y[1] , x[2], x[1]);
	 	  			j = j + s1;
	 	  			}
	 	  			//////////////////////////
	 	  			ST7789_DrawFilledRectangle(x[2], y4[2],widthrt, heightrt,WHITE);
					j = y4[2];
					// ST7789_DrawFilledRectangle(50,160,w, h, WHITE);
					for(int i = x[2] ;i<x[3];i++)
					{
					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, WHITE);

					s1 = slope(y4[3],y4[2] , x[3], x[2]);
					j = j + s1;
					}
					ST7789_DrawFilledRectangle(x[3], y4[3],widthrt, heightrt, WHITE);
					j = y4[3];

					for(int i = x[3];i<x[4];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
					s1 = slope(y4[4],y4[3] , x[4], x[3]);
					j = j + s1;

					}
	 	  				 	  			///////////////
	 	  			ST7789_DrawFilledRectangle(x[2], y[2],widthrt, heightrt,BLACK);
	 	  			j = y[2];
	 	  			// ST7789_DrawFilledRectangle(50,160,w, h, WHITE);
	 	  			for(int i = x[2] ;i<x[3];i++)
	 	  			{
	 	  			ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, BLACK);

	 	  			s1 = slope(y[3],y[2] , x[3], x[2]);
	 	  			j = j + s1;
	 	  			}
	 	  			ST7789_DrawFilledRectangle(x[3], y[3],widthrt, heightrt, BLACK);
	 	  			j = y[3];

	 	  			for(int i = x[3];i<x[4];i++)
	 	  			{
	 	  			ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	 	  			s1 = slope(y[4],y[3] , x[4], x[3]);
	 	  			j = j + s1;

	 	  			}
	 	  			//////////////////////////////
	 	  			ST7789_DrawFilledRectangle(x[4], y4[4],widthrt, heightrt,WHITE);
					j = y4[4];

					for(int i = x[4] ;i<x[5];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
					s1 = slope(y4[5],y4[4] , x[5], x[4]);
					j = j + s1;

					}
					ST7789_DrawFilledRectangle(x[5], y4[5],widthrt, heightrt, WHITE);
					j = y4[5];

					for(int i = x[5] ;i<x[6];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,WHITE);
					s1 = slope(y4[6],y4[5] , x[6], x[5]);
					j = j + s1;

					}
	 	  				 	  			//////////////
	 	  			ST7789_DrawFilledRectangle(x[4], y[4],widthrt, heightrt,BLACK);
	 	  			j = y[4];

	 	  			for(int i = x[4] ;i<x[5];i++)
	 	  			{
	 	  			ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	 	  			s1 = slope(y[5],y[4] , x[5], x[4]);
	 	  			j = j + s1;

	 	  			}
	 	  			ST7789_DrawFilledRectangle(x[5], y[5],widthrt, heightrt, BLACK);
	 	  			j = y[5];

	 	  			for(int i = x[5] ;i<x[6];i++)
	 	  			{
	 	  			ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	 	  			s1 = slope(y[6],y[5] , x[6], x[5]);
	 	  			j = j + s1;

	 	  			}
	 	  			///////////////////////////
	 	  			ST7789_DrawFilledRectangle(x[6], y4[6], widthrt, heightrt, WHITE);
					j = y4[6];

					for(int i = x[6] ;i<x[7];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
					s1 = slope(y4[7],y4[6] , x[7], x[6]);
					j = j + s1;

					}
					ST7789_DrawFilledRectangle(x[7], y4[7], widthrt, heightrt, WHITE);
					j = y4[7];

					for(int i = x[7] ;i<x[8];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,WHITE);
					s1 = slope(y4[8],y4[7], x[8], x[7]);
					j = j + s1;

					}
	 	  			ST7789_DrawFilledRectangle(x[6], y[6], widthrt, heightrt, BLACK);
	 	  			j = y[6];

	 	  			for(int i = x[6] ;i<x[7];i++)
	 	  			{
	 	  			ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	 	  			s1 = slope(y[7],y[6] , x[7], x[6]);
	 	  			j = j + s1;

	 	  			}
	 	  			ST7789_DrawFilledRectangle(x[7], y[7], widthrt, heightrt, BLACK);
	 	  			j = y[7];

	 	  			for(int i = x[7] ;i<x[8];i++)
	 	  			{
	 	  			ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,BLACK);
	 	  			s1 = slope(y[8],y[7], x[8], x[7]);
	 	  			j = j + s1;

	 	  			}
	 	  			/////////////////////////
	 	  			ST7789_DrawFilledRectangle(x[8], y4[8], widthrt, heightrt, WHITE);
					j = y4[8];

					for(int i = x[8] ;i<x[9];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,WHITE);
					s1 = slope(y4[9],y4[8] , x[9], x[8]);
					j = j + s1;

					}

					ST7789_DrawFilledRectangle(x[9], y4[9],widthrt, heightrt, WHITE);
					j = y4[9];
					for(int i = x[9] ;i<x[10];i++)
					{
					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,WHITE);
					s1 = slope(y4[10],y4[9] , x[10], x[9]);
					j = j + s1;
					}
	 	  			ST7789_DrawFilledRectangle(x[8], y[8], widthrt, heightrt, BLACK);
	 	  			j = y[8];

	 	  			for(int i = x[8] ;i<x[9];i++)
	 	  			{
	 	  			ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,BLACK);
	 	  			s1 = slope(y[9],y[8] , x[9], x[8]);
	 	  			j = j + s1;

	 	  			}

	 	  			ST7789_DrawFilledRectangle(x[9], y[9],widthrt, heightrt, BLACK);
	 	  			j = y[9];
	 	  			for(int i = x[9] ;i<x[10];i++)
	 	  			{
	 	  			ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,BLACK);
	 	  			s1 = slope(y[10],y[9] , x[10], x[9]);
	 	  			j = j + s1;
	 	  			}
//////////////////////////////////////////////////
	 	  			ST7789_DrawFilledRectangle(x[10], y4[10],widthrt, heightrt,WHITE);
					j = y4[10];
					for(int i = x[10] ;i<x[11];i++)
					{
					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,WHITE);
					s1 = slope(y4[11],y4[10] , x[11], x[10]);
					j = j + s1;

					}
	 	  			ST7789_DrawFilledRectangle(x[10], y[10],widthrt, heightrt,BLACK);
	 	  			j = y[10];
	 	  			for(int i = x[10] ;i<x[11];i++)
	 	  			{
	 	  			ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,BLACK);
	 	  			s1 = slope(y[11],y[10] , x[11], x[10]);
	 	  			j = j + s1;

	 	  			}


	 	  		      y1[0]=y[0];
	 	  			  y1[1]=y[1];
	 	  			  y1[2]=y[2];
	 	  			  y1[3] =y[3];
	 	  			  y1[4] =y[4];
	 	  			  y1[5]=y[5];
	 	  			  y1[6]=y[6];
	 	  			  y1[7]=y[7];
	 	  			  y1[8]=y[8];
	 	  			  y1[9] =y[9];
	 	  			  y1[10]=y[10];
	 	  			  y1[11] =y[11];

	 	  			cnt=cnt+1;

	       }


	      while(cnt==2)
				{
					//////////0clr
					HAL_Delay(delaytest1);

					ST7789_DrawFilledRectangle(x[0], y1[0], widthrt, heightrt,WHITE);
					j = y1[0];
					for(float i = x[0] ;i<x[1];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
					s1 = slope(y1[1],y1[0] , x[1], x[0]);
					j = j + s1;
					}
                    /////////clr1
					ST7789_DrawFilledRectangle(x[1], y1[1],widthrt, heightrt, WHITE);
					j = y1[1];
					for(int i = x[1] ;i<x[2];i++)
					{
					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, WHITE);
					s1 = slope(y1[2],y1[1] , x[2], x[1]);
					j = j + s1;
					}
                   /////////////////////////
					ST7789_DrawFilledRectangle(x[0], y[0], widthrt, heightrt, BLACK);
					j = y[0];
					for(float i = x[0] ;i<x[1];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
					s1 = slope(y[1],y[0] , x[1], x[0]);
					j = j + s1;
					}


					////////////////////1
					HAL_Delay(delaytest1);


					ST7789_DrawFilledRectangle(x[1], y[1],widthrt, heightrt, BLACK);
					j = y[1];

					// ST7789_DrawFilledRectangle(30,160,w, h, WHITE);
					for(int i = x[1] ;i<x[2];i++)
					{
					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, BLACK);
					s1 = slope(y[2],y[1] , x[2], x[1]);
					j = j + s1;
					}

					///////////////////////2 3
					HAL_Delay(delaytest1);

					ST7789_DrawFilledRectangle(x[2], y1[2],widthrt, heightrt,WHITE);
					j = y1[2];
					// ST7789_DrawFilledRectangle(50,160,w, h, WHITE);
					for(int i = x[2] ;i<x[3];i++)
					{
					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, WHITE);

					s1 = slope(y1[3],y1[2] , x[3], x[2]);
					j = j + s1;
					}
					ST7789_DrawFilledRectangle(x[3], y1[3],widthrt, heightrt,WHITE);
					j = y1[3];

					for(int i = x[3];i<x[4];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
					s1 = slope(y1[4],y1[3] , x[4], x[3]);
					j = j + s1;

					}
					ST7789_DrawFilledRectangle(x[2], y[2],widthrt, heightrt,BLACK);
					j = y[2];
					// ST7789_DrawFilledRectangle(50,160,w, h, WHITE);
					for(int i = x[2] ;i<x[3];i++)
					{
					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, BLACK);

					s1 = slope(y[3],y[2] , x[3], x[2]);
					j = j + s1;
					}
					/////////////////////////3
					HAL_Delay(delaytest1);

					ST7789_DrawFilledRectangle(x[3], y[3],widthrt, heightrt, BLACK);
					j = y[3];

					for(int i = x[3];i<x[4];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
					s1 = slope(y[4],y[3] , x[4], x[3]);
					j = j + s1;

					}
					/////////////////////////////4
					HAL_Delay(delaytest1);

					ST7789_DrawFilledRectangle(x[4], y1[4],widthrt, heightrt,WHITE);
					j = y1[4];

					for(int i = x[4] ;i<x[5];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
					s1 = slope(y1[5],y1[4] , x[5], x[4]);
					j = j + s1;

					}
					ST7789_DrawFilledRectangle(x[5], y1[5],widthrt, heightrt, WHITE);
					j = y1[5];

					for(int i = x[5] ;i<x[6];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,WHITE);
					s1 = slope(y1[6],y1[5] , x[6], x[5]);
					j = j + s1;

					}
					ST7789_DrawFilledRectangle(x[4], y[4],widthrt, heightrt,BLACK);
					j = y[4];

					for(int i = x[4] ;i<x[5];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
					s1 = slope(y[5],y[4] , x[5], x[4]);
					j = j + s1;

					}

					/////////////////////////////5
					HAL_Delay(delaytest1);

					ST7789_DrawFilledRectangle(x[5], y[5],widthrt, heightrt, BLACK);
					j = y[5];

					for(int i = x[5] ;i<x[6];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
					s1 = slope(y[6],y[5] , x[6], x[5]);
					j = j + s1;

					}
					///////////////////////////////6
					HAL_Delay(delaytest1);
					ST7789_DrawFilledRectangle(x[6], y1[6], widthrt, heightrt, WHITE);
					j = y1[6];

					for(int i = x[6] ;i<x[7];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
					s1 = slope(y1[7],y1[6] , x[7], x[6]);
					j = j + s1;
					}
					ST7789_DrawFilledRectangle(x[7], y1[7], widthrt, heightrt, WHITE);
					j = y1[7];

					for(int i = x[7] ;i<x[8];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,WHITE);
					s1 = slope(y1[8],y1[7], x[8], x[7]);
					j = j + s1;

					}
					ST7789_DrawFilledRectangle(x[6], y[6], widthrt, heightrt, BLACK);
					j = y[6];

					for(int i = x[6] ;i<x[7];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
					s1 = slope(y[7],y[6] , x[7], x[6]);
					j = j + s1;

					}
					/////////////////////////////////7
					HAL_Delay(delaytest1);

					ST7789_DrawFilledRectangle(x[7], y[7], widthrt, heightrt, BLACK);
					j = y[7];

					for(int i = x[7] ;i<x[8];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,BLACK);
					s1 = slope(y[8],y[7], x[8], x[7]);
					j = j + s1;

					}
					/////////////////////////////8
					HAL_Delay(delaytest1);
					ST7789_DrawFilledRectangle(x[8], y1[8], widthrt, heightrt,WHITE);
					j = y1[8];

					for(int i = x[8] ;i<x[9];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,WHITE);
					s1 = slope(y1[9],y1[8] , x[9], x[8]);
					j = j + s1;

					}
					ST7789_DrawFilledRectangle(x[9], y1[9],widthrt, heightrt, WHITE);
					j = y1[9];
					for(int i = x[9] ;i<x[10];i++)
					{
					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,WHITE);
					s1 = slope(y1[10],y1[9] , x[10], x[9]);
					j = j + s1;
					}
					ST7789_DrawFilledRectangle(x[8], y[8], widthrt, heightrt, BLACK);
					j = y[8];

					for(int i = x[8] ;i<x[9];i++)
					{
					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,BLACK);
					s1 = slope(y[9],y[8] , x[9], x[8]);
					j = j + s1;

					}
					////////////////////////////////////////////9
					HAL_Delay(delaytest1);

					ST7789_DrawFilledRectangle(x[9], y[9],widthrt, heightrt, BLACK);
					j = y[9];
					for(int i = x[9] ;i<x[10];i++)
					{
					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,BLACK);
					s1 = slope(y[10],y[9] , x[10], x[9]);
					j = j + s1;
					}
					/////////////////////////////////////////////10
					HAL_Delay(delaytest1);
					ST7789_DrawFilledRectangle(x[10], y1[10],widthrt, heightrt,WHITE);
					j = y1[10];
					for(int i = x[10] ;i<x[11];i++)
					{
					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,WHITE);
					s1 = slope(y1[11],y1[10] , x[11], x[10]);
					j = j + s1;

					}
					ST7789_DrawFilledRectangle(x[10], y[10],widthrt, heightrt,BLACK);
					j = y[10];
					for(int i = x[10] ;i<x[11];i++)
					{
					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,BLACK);
					s1 = slope(y[11],y[10] , x[11], x[10]);
					j = j + s1;

					}
					  y2[0]= y[0];
					  y2[1]=y[1];
					  y2[2]=y[2];
					  y2[3] =y[3];
					  y2[4] =y[4];
					  y2[5]=y[5];
					  y2[6]=y[6];
					  y2[7]=y[7];
					  y2[8]=y[8];
					  y2[9] =y[9];
					  y2[10]=y[10];
					  y2[11] =y[11];
					  cnt = cnt +1;

	      	  }

	      while(cnt==4)
	      				{
	      					//////////0
	    	                HAL_Delay(delaytest1);
	      					ST7789_DrawFilledRectangle(x[0], y2[0], widthrt, heightrt,WHITE);
	      					j = y2[0];
	      					for(float i = x[0] ;i<x[1];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
	      					s1 = slope(y2[1],y2[0] , x[1], x[0]);
	      					j = j + s1;
	      					}
	      					ST7789_DrawFilledRectangle(x[1], y2[1],widthrt, heightrt, WHITE);
							j = y2[1];

							// ST7789_DrawFilledRectangle(30,160,w, h, WHITE);
							for(int i = x[1] ;i<x[2];i++)
							{
							ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, WHITE);
							s1 = slope(y2[2],y2[1] , x[2], x[1]);
							j = j + s1;
							}


	      					ST7789_DrawFilledRectangle(x[0], y[0], widthrt, heightrt, BLACK);
	      					j = y[0];
	      					for(float i = x[0] ;i<x[1];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	      					s1 = slope(y[1],y[0] , x[1], x[0]);
	      					j = j + s1;
	      					}


	      					////////////////////1
	      					HAL_Delay(delaytest1);

	      					ST7789_DrawFilledRectangle(x[1], y[1],widthrt, heightrt, BLACK);
	      					j = y[1];

	      					// ST7789_DrawFilledRectangle(30,160,w, h, WHITE);
	      					for(int i = x[1] ;i<x[2];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, BLACK);
	      					s1 = slope(y[2],y[1] , x[2], x[1]);
	      					j = j + s1;
	      					}

	      					///////////////////////2
	      					HAL_Delay(delaytest1);
	      					ST7789_DrawFilledRectangle(x[2], y2[2],widthrt, heightrt,WHITE);
	      					j = y2[2];
	      					// ST7789_DrawFilledRectangle(50,160,w, h, WHITE);
	      					for(int i = x[2] ;i<x[3];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, WHITE);

	      					s1 = slope(y2[3],y2[2] , x[3], x[2]);
	      					j = j + s1;
	      					}
	      					ST7789_DrawFilledRectangle(x[3], y2[3],widthrt, heightrt,WHITE);
							j = y2[3];

							for(int i = x[3];i<x[4];i++)
							{
							ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
							s1 = slope(y2[4],y2[3] , x[4], x[3]);
							j = j + s1;

							}
	      					ST7789_DrawFilledRectangle(x[2], y[2],widthrt, heightrt,BLACK);
	      					j = y[2];
	      					// ST7789_DrawFilledRectangle(50,160,w, h, WHITE);
	      					for(int i = x[2] ;i<x[3];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, BLACK);

	      					s1 = slope(y[3],y[2] , x[3], x[2]);
	      					j = j + s1;
	      					}
	      					/////////////////////////3
	      					HAL_Delay(delaytest1);

	      					ST7789_DrawFilledRectangle(x[3], y[3],widthrt, heightrt, BLACK);
	      					j = y[3];

	      					for(int i = x[3];i<x[4];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	      					s1 = slope(y[4],y[3] , x[4], x[3]);
	      					j = j + s1;

	      					}
	      					/////////////////////////////4
	      					HAL_Delay(delaytest1);
	      					ST7789_DrawFilledRectangle(x[4], y2[4],widthrt, heightrt,WHITE);
	      					j = y2[4];

	      					for(int i = x[4] ;i<x[5];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
	      					s1 = slope(y2[5],y2[4] , x[5], x[4]);
	      					j = j + s1;

	      					}
	      					ST7789_DrawFilledRectangle(x[5], y2[5],widthrt, heightrt, WHITE);
							j = y2[5];

							for(int i = x[5] ;i<x[6];i++)
							{
							ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,WHITE);
							s1 = slope(y2[6],y2[5] , x[6], x[5]);
							j = j + s1;

							}
	      					ST7789_DrawFilledRectangle(x[4], y[4],widthrt, heightrt,BLACK);
	      					j = y[4];

	      					for(int i = x[4] ;i<x[5];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	      					s1 = slope(y[5],y[4] , x[5], x[4]);
	      					j = j + s1;

	      					}

	      					/////////////////////////////5
	      					HAL_Delay(delaytest1);

	      					ST7789_DrawFilledRectangle(x[5], y[5],widthrt, heightrt, BLACK);
	      					j = y[5];

	      					for(int i = x[5] ;i<x[6];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	      					s1 = slope(y[6],y[5] , x[6], x[5]);
	      					j = j + s1;

	      					}
	      					///////////////////////////////6
	      					HAL_Delay(delaytest1);
	      					ST7789_DrawFilledRectangle(x[6], y2[6], widthrt, heightrt, WHITE);
	      					j = y2[6];

	      					for(int i = x[6] ;i<x[7];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
	      					s1 = slope(y2[7],y2[6] , x[7], x[6]);
	      					j = j + s1;
	      					}
	      					ST7789_DrawFilledRectangle(x[7], y2[7], widthrt, heightrt, WHITE);
							j = y2[7];

							for(int i = x[7] ;i<x[8];i++)
							{
							ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,WHITE);
							s1 = slope(y2[8],y2[7], x[8], x[7]);
							j = j + s1;

							}
	      					ST7789_DrawFilledRectangle(x[6], y[6], widthrt, heightrt, BLACK);
	      					j = y[6];

	      					for(int i = x[6] ;i<x[7];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	      					s1 = slope(y[7],y[6] , x[7], x[6]);
	      					j = j + s1;

	      					}
	      					/////////////////////////////////7
	      					HAL_Delay(delaytest1);

	      					ST7789_DrawFilledRectangle(x[7], y[7], widthrt, heightrt, BLACK);
	      					j = y[7];

	      					for(int i = x[7] ;i<x[8];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,BLACK);
	      					s1 = slope(y[8],y[7], x[8], x[7]);
	      					j = j + s1;

	      					}
	      					/////////////////////////////8
	      					HAL_Delay(delaytest1);
	      					ST7789_DrawFilledRectangle(x[8], y2[8], widthrt, heightrt,WHITE);
	      					j = y2[8];

	      					for(int i = x[8] ;i<x[9];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,WHITE);
	      					s1 = slope(y2[9],y2[8] , x[9], x[8]);
	      					j = j + s1;

	      					}
	      					ST7789_DrawFilledRectangle(x[9], y2[9],widthrt, heightrt, WHITE);
							j = y2[9];
							for(int i = x[9] ;i<x[10];i++)
							{
							ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,WHITE);
							s1 = slope(y2[10],y2[9] , x[10], x[9]);
							j = j + s1;
							}
	      					ST7789_DrawFilledRectangle(x[8], y[8], widthrt, heightrt, BLACK);
	      					j = y[8];

	      					for(int i = x[8] ;i<x[9];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,BLACK);
	      					s1 = slope(y[9],y[8] , x[9], x[8]);
	      					j = j + s1;

	      					}
	      					////////////////////////////////////////////9
	      					HAL_Delay(delaytest1);

	      					ST7789_DrawFilledRectangle(x[9], y[9],widthrt, heightrt, BLACK);
	      					j = y[9];
	      					for(int i = x[9] ;i<x[10];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,BLACK);
	      					s1 = slope(y[10],y[9] , x[10], x[9]);
	      					j = j + s1;
	      					}
	      					/////////////////////////////////////////////10
	      					HAL_Delay(delaytest1);
	      					ST7789_DrawFilledRectangle(x[10], y2[10],widthrt, heightrt,WHITE);
	      					j = y2[10];
	      					for(int i = x[10] ;i<x[11];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,WHITE);
	      					s1 = slope(y2[11],y2[10] , x[11], x[10]);
	      					j = j + s1;

	      					}
	      					ST7789_DrawFilledRectangle(x[10], y[10],widthrt, heightrt,BLACK);
	      					j = y[10];
	      					for(int i = x[10] ;i<x[11];i++)
	      					{
	      					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,BLACK);
	      					s1 = slope(y[11],y[10] , x[11], x[10]);
	      					j = j + s1;

	      					}
	      					  y3[0]= y[0];
	      					  y3[1]=y[1];
	      					  y3[2]=y[2];
	      					  y3[3] =y[3];
	      					  y3[4] =y[4];
	      					  y3[5]=y[5];
	      					  y3[6]=y[6];
	      					  y3[7]=y[7];
	      					  y3[8]=y[8];
	      					  y3[9] =y[9];
	      					  y3[10]=y[10];
	      					  y3[11] =y[11];
	      					  cnt = cnt+1;

	      	      	  }


	      while(cnt==6)
	     	      				{
	     	      					//////////0
	    	                        HAL_Delay(delaytest1);

	     	      					ST7789_DrawFilledRectangle(x[0], y3[0], widthrt, heightrt,WHITE);
	     	      					j = y3[0];
	     	      					for(float i = x[0] ;i<x[1];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
	     	      					s1 = slope(y3[1],y3[0] , x[1], x[0]);
	     	      					j = j + s1;
	     	      					}

	     	      					ST7789_DrawFilledRectangle(x[1], y3[1],widthrt, heightrt, WHITE);
									j = y3[1];

									// ST7789_DrawFilledRectangle(30,160,w, h, WHITE);
									for(int i = x[1] ;i<x[2];i++)
									{
									ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, WHITE);
									s1 = slope(y3[2],y3[1] , x[2], x[1]);
									j = j + s1;
									}

	     	      					ST7789_DrawFilledRectangle(x[0], y[0], widthrt, heightrt, BLACK);
	     	      					j = y[0];
	     	      					for(float i = x[0] ;i<x[1];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	     	      					s1 = slope(y[1],y[0] , x[1], x[0]);
	     	      					j = j + s1;
	     	      					}


	     	      					////////////////////1
	     	      					HAL_Delay(delaytest1);

	     	      					ST7789_DrawFilledRectangle(x[1], y[1],widthrt, heightrt, BLACK);
	     	      					j = y[1];

	     	      					// ST7789_DrawFilledRectangle(30,160,w, h, WHITE);
	     	      					for(int i = x[1] ;i<x[2];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, BLACK);
	     	      					s1 = slope(y[2],y[1] , x[2], x[1]);
	     	      					j = j + s1;
	     	      					}

	     	      					///////////////////////2
	     	      					HAL_Delay(delaytest1);

	     	      					ST7789_DrawFilledRectangle(x[2], y3[2],widthrt, heightrt,WHITE);
	     	      					j = y3[2];
	     	      					// ST7789_DrawFilledRectangle(50,160,w, h, WHITE);
	     	      					for(int i = x[2] ;i<x[3];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, WHITE);

	     	      					s1 = slope(y3[3],y3[2] , x[3], x[2]);
	     	      					j = j + s1;
	     	      					}
	     	      					ST7789_DrawFilledRectangle(x[3], y3[3],widthrt, heightrt,WHITE);
									j = y3[3];

									for(int i = x[3];i<x[4];i++)
									{
									ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
									s1 = slope(y3[4],y3[3] , x[4], x[3]);
									j = j + s1;

									}
	     	      					ST7789_DrawFilledRectangle(x[2], y[2],widthrt, heightrt,BLACK);
	     	      					j = y[2];
	     	      					// ST7789_DrawFilledRectangle(50,160,w, h, WHITE);
	     	      					for(int i = x[2] ;i<x[3];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt, BLACK);

	     	      					s1 = slope(y[3],y[2] , x[3], x[2]);
	     	      					j = j + s1;
	     	      					}
	     	      					/////////////////////////3
	     	      					HAL_Delay(delaytest1);

	     	      					ST7789_DrawFilledRectangle(x[3], y[3],widthrt, heightrt, BLACK);
	     	      					j = y[3];

	     	      					for(int i = x[3];i<x[4];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	     	      					s1 = slope(y[4],y[3] , x[4], x[3]);
	     	      					j = j + s1;

	     	      					}
	     	      					/////////////////////////////4
	     	      					HAL_Delay(delaytest1);

	     	      					ST7789_DrawFilledRectangle(x[4], y3[4],widthrt, heightrt,WHITE);
	     	      					j = y3[4];

	     	      					for(int i = x[4] ;i<x[5];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
	     	      					s1 = slope(y3[5],y3[4] , x[5], x[4]);
	     	      					j = j + s1;

	     	      					}
	     	      					ST7789_DrawFilledRectangle(x[5], y3[5],widthrt, heightrt, WHITE);
									j = y3[5];

									for(int i = x[5] ;i<x[6];i++)
									{
									ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,WHITE);
									s1 = slope(y3[6],y3[5] , x[6], x[5]);
									j = j + s1;

									}
	     	      					ST7789_DrawFilledRectangle(x[4], y[4],widthrt, heightrt,BLACK);
	     	      					j = y[4];

	     	      					for(int i = x[4] ;i<x[5];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	     	      					s1 = slope(y[5],y[4] , x[5], x[4]);
	     	      					j = j + s1;

	     	      					}

	     	      					/////////////////////////////5
	     	      					HAL_Delay(delaytest1);

	     	      					ST7789_DrawFilledRectangle(x[5], y[5],widthrt, heightrt, BLACK);
	     	      					j = y[5];

	     	      					for(int i = x[5] ;i<x[6];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	     	      					s1 = slope(y[6],y[5] , x[6], x[5]);
	     	      					j = j + s1;

	     	      					}
	     	      					///////////////////////////////6
	     	      					HAL_Delay(delaytest1);
	     	      					ST7789_DrawFilledRectangle(x[6], y3[6], widthrt, heightrt, WHITE);
	     	      					j = y3[6];

	     	      					for(int i = x[6] ;i<x[7];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, WHITE);
	     	      					s1 = slope(y3[7],y3[6] , x[7], x[6]);
	     	      					j = j + s1;
	     	      					}
	     	      					ST7789_DrawFilledRectangle(x[7], y3[7], widthrt, heightrt, WHITE);
									j = y3[7];

									for(int i = x[7] ;i<x[8];i++)
									{
									ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,WHITE);
									s1 = slope(y3[8],y3[7], x[8], x[7]);
									j = j + s1;

									}
	     	      					ST7789_DrawFilledRectangle(x[6], y[6], widthrt, heightrt, BLACK);
	     	      					j = y[6];

	     	      					for(int i = x[6] ;i<x[7];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt, BLACK);
	     	      					s1 = slope(y[7],y[6] , x[7], x[6]);
	     	      					j = j + s1;

	     	      					}
	     	      					/////////////////////////////////7
	     	      					HAL_Delay(delaytest1);

	     	      					ST7789_DrawFilledRectangle(x[7], y[7], widthrt, heightrt, BLACK);
	     	      					j = y[7];

	     	      					for(int i = x[7] ;i<x[8];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,BLACK);
	     	      					s1 = slope(y[8],y[7], x[8], x[7]);
	     	      					j = j + s1;

	     	      					}
	     	      					/////////////////////////////8
	     	      					HAL_Delay(delaytest1);
	     	      					ST7789_DrawFilledRectangle(x[8], y3[8], widthrt, heightrt,WHITE);
	     	      					j = y3[8];

	     	      					for(int i = x[8] ;i<x[9];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,WHITE);
	     	      					s1 = slope(y3[9],y3[8] , x[9], x[8]);
	     	      					j = j + s1;

	     	      					}
	     	      					ST7789_DrawFilledRectangle(x[9], y3[9],widthrt, heightrt, WHITE);
									j = y3[9];
									for(int i = x[9] ;i<x[10];i++)
									{
									ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,WHITE);
									s1 = slope(y3[10],y3[9] , x[10], x[9]);
									j = j + s1;
									}
	     	      					ST7789_DrawFilledRectangle(x[8], y[8], widthrt, heightrt, BLACK);
	     	      					j = y[8];

	     	      					for(int i = x[8] ;i<x[9];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j, widthrt, heightrt,BLACK);
	     	      					s1 = slope(y[9],y[8] , x[9], x[8]);
	     	      					j = j + s1;

	     	      					}
	     	      					////////////////////////////////////////////9
	     	      					HAL_Delay(delaytest1);

	     	      					ST7789_DrawFilledRectangle(x[9], y[9],widthrt, heightrt, BLACK);
	     	      					j = y[9];
	     	      					for(int i = x[9] ;i<x[10];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,BLACK);
	     	      					s1 = slope(y[10],y[9] , x[10], x[9]);
	     	      					j = j + s1;
	     	      					}
	     	      					/////////////////////////////////////////////10
	     	      					HAL_Delay(delaytest1);
	     	      					ST7789_DrawFilledRectangle(x[10], y3[10],widthrt, heightrt,WHITE);
	     	      					j = y3[10];
	     	      					for(int i = x[10] ;i<x[11];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,WHITE);
	     	      					s1 = slope(y3[11],y3[10] , x[11], x[10]);
	     	      					j = j + s1;

	     	      					}
	     	      					ST7789_DrawFilledRectangle(x[10], y[10],widthrt, heightrt,BLACK);
	     	      					j = y[10];
	     	      					for(int i = x[10] ;i<x[11];i++)
	     	      					{
	     	      					ST7789_DrawFilledRectangle(i, j,widthrt, heightrt,BLACK);
	     	      					s1 = slope(y[11],y[10] , x[11], x[10]);
	     	      					j = j + s1;

	     	      					}
	     	      					  y4[0]= y[0];
	     	      					  y4[1]=y[1];
	     	      					  y4[2]=y[2];
	     	      					  y4[3] =y[3];
	     	      					  y4[4] =y[4];
	     	      					  y4[5]=y[5];
	     	      					  y4[6]=y[6];
	     	      					  y4[7]=y[7];
	     	      					  y4[8]=y[8];
	     	      					  y4[9] =y[9];
	     	      					  y4[10]=y[10];
	     	      					  y4[11] =y[11];
	     	      					  cnt = -1;
	     	      					// ST7789_Fill_Color(WHITE);
	     	      					 /////////////////////


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
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
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
