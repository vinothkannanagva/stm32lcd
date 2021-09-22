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


     for(int i = 0  ;i <= 100 ;i++)
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

for(int i = 0 ; i <=70;i++)
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
	 	      if(a>73)
	 	      {
	 	          a=0;
	 	      }

	 	    }



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
				y[20]=170;
				y[21]=170;
				y[22]=170;
				y[23]=170;
				y[24]=170;
				y[25]=170;
				y[26]=170;
				y[27]=170;
				y[28]=170;
				y[29]=170;
				y[30]=170;
				y[31]=170;
				y[32]=170;
				y[33]=170;
				y[34]=170;
				y[35]=180;
				y[36]=190;
				y[37]=210;
				y[38]=214;
				y[39]=214;
				y[40]=214;

				y[41]=214;
				y[42]=212;
				y[43]=206;
				y[44]=192;
				y[45]=176;
				y[46]=172;
				y[47]=170;
				y[48]=170;
				y[49]=170;
				y[50]=170;
				y[51]=170;
				y[52]=170;
				y[53]=170;
				y[54]=170;
				y[55]=170;
				y[56]=170;
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
				y[70]=170;
				y[71]=170;
				y[72]=170;
				y[73]=170;
				y[74]=170;
				y[75]=180;
				y[76]=190;
				y[77]=210;
				y[78]=214;
				y[79]=214;
				y[80]=214;



	 	  uint16_t widthrt =1 , heightrt =1;










	 	 //	  ST7789_Fill_Color(WHITE);






	      while(cnt==0)
	      {




					for(int i =0 ;i <=80;i++)
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
					y1[12] =y[12];
					y1[13] =y[13];
					y1[14] =y[14];
					y1[15] =y[15];
					y1[16] =y[16];
					y1[17] =y[17];
					y1[18] =y[18];
					y1[19] =y[19];
					y1[20] =y[20];
					y1[21] =y[21];
					y1[22] =y[22];
					y1[23] =y[23];
					y1[24] =y[24];
					y1[25] =y[25];
					y1[26] =y[26];
					y1[27] =y[27];
					y1[28] =y[28];
					y1[29] =y[29];
					y1[30] =y[30];
					y1[31] =y[31];
					y1[32] =y[32];
					y1[33] =y[33];
					y1[34] =y[34];
					y1[35] =y[35];
					y1[36] =y[36];
					y1[37] =y[37];
					y1[38] =y[38];
					y1[39] =y[39];
					y1[40] =y[40];
					y1[41] =y[41];
					y1[42] =y[42];
					y1[43] =y[43];
					y1[44] =y[44];
					y1[45] =y[45];
					y1[46] =y[46];
					y1[47] =y[47];
					y1[48] =y[48];
					y1[49] =y[49];
					y1[50] =y[50];
					y1[51] =y[51];
					y1[52] =y[52];
					y1[53] =y[53];
					y1[54] =y[54];
					y1[55] =y[55];
					y1[56] =y[56];
					y1[57] =y[57];
					y1[58] =y[58];
					y1[59] =y[59];
					y1[60] =y[60];
					y1[61] =y[61];
					y1[62] =y[62];
					y1[63] =y[63];
					y1[64] =y[64];
					y1[65] =y[65];
					y1[66] =y[66];
					y1[67] =y[67];
					y1[68] =y[68];
					y1[69] =y[69];
					y1[70] =y[70];
					y1[71] =y[71];
					y1[72] =y[72];
					y1[73] =y[73];
					y1[74] =y[74];
					y1[75] =y[75];
					y1[76] =y[76];
					y1[77] =y[77];
					y1[78] =y[78];
					y1[79] =y[79];
					y1[80] =y[80];


	 	  			cnt=cnt+1;

	       }


	      while(cnt==2)
				{


	    		                for(int i =0 ;i <=80;i++)
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
					  y2[12]=y[12];
					  y2[13]=y[13];
					  y2[14]=y[14];
					  y2[15]=y[15];
					  y2[16]=y[16];
					  y2[17]=y[17];
					  y2[18]=y[18];
					  y2[19]=y[19];
					  y2[20]=y[20];
					  y2[21]=y[21];
					  y2[22]=y[22];
					  y2[23]=y[23];
					  y2[24]=y[24];
					  y2[25]=y[25];
					  y2[26]=y[26];
					  y2[27]=y[27];
					  y2[28]=y[28];
					  y2[29]=y[29];
					  y2[30]=y[30];
					  y2[31]=y[31];
					  y2[32]=y[32];
					  y2[33]=y[33];
					  y2[34]=y[34];
					  y2[35]=y[35];
					  y2[36]=y[36];
					  y2[37]=y[37];
					  y2[38]=y[38];
					  y2[39]=y[39];
					  y2[40]=y[40];
					  y2[41]=y[41];
					  y2[42]=y[42];
					  y2[43]=y[43];
					  y2[44]=y[44];
					  y2[45]=y[45];
					  y2[46]=y[46];
					  y2[47]=y[47];
					  y2[48]=y[48];
					  y2[49]=y[49];
					  y2[50]=y[50];
					  y2[51]=y[51];
					  y2[52]=y[52];
					  y2[53]=y[53];
					  y2[54]=y[54];
					  y2[55]=y[55];
					  y2[56]=y[56];
					  y2[57]=y[57];
					  y2[58]=y[58];
					  y2[59]=y[59];
					  y2[60]=y[60];
					  y2[61]=y[61];
					  y2[62]=y[62];
					  y2[63]=y[63];
					  y2[64]=y[64];
					  y2[65]=y[65];
					  y2[66]=y[66];
					  y2[67]=y[67];
					  y2[68]=y[68];
					  y2[69]=y[69];
					  y2[70]=y[70];
					  y2[71]=y[71];
					  y2[72]=y[72];
					  y2[73]=y[73];
					  y2[74]=y[74];
					  y2[75]=y[75];
					  y2[76]=y[76];
					  y2[77]=y[77];
					  y2[78]=y[78];
					  y2[79]=y[79];
					  y2[80]=y[80];

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
