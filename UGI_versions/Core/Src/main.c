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
//#include "st7789.h"
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
//Graph array values 1
//              0   1    2   3   4   5  6    7   8  9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25

float rand1[]={219,219,212,206,192,176,172,170,170,170,170,170,170,170,170,170,170,170,170,170,176,192,206,212,214,214,
//             26  27   28  29  30  31  32  33  34  35  36  37 38   39  40  41  42  43  44  45  46  47  48  49  50
		       214,214,214,212,206,192,176,160,160,160,160,160,160,160,160,160,160,160,160,180,190,210,214,214,214, // 214,214, 214,212,206,192,176,170,170,170,170,170,170,170,170,170,170,170,170,180,190,210,214,214,214,
//             51  52   53  54  55  56  57  58 59  60  61  62  63  64  65  66   67  68  69  70  71 72   73  74  75
			  214,212,206,192,176,172,170,170,170,170,170,170,170,170,170,170,170,170,170,176,192,206,212,214,214,
//            76  77  78  79   80  81  82  83  84  85  86  87  88  89  90  91 92  93  94   95  96  97  98  99  100
		   214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,214,212,206,192,176,160,160,160,160,160,160,160,160,160,160,160,160,180,190,210,214,214,214,
  //       101 102 103 104 105 106 107 108 109 110 111 112 113 114 115
					  };

//Graph array values 2
//              0   1    2   3   4   5  6    7   8  9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25
	  float rand2[]={214,214,212,206,192,176,172,160,160,160,160,160,160,160,160,160,160,160,160,160,176,192,206,212,214,214,
	  //             26  27   28  29  30  31  32  33  34  35  36  37 38   39  40  41  42  43  44  45  46  47  48  49  50
					 214,214, 214,212,206,192,176,170,170,170,170,170,170,170,170,170,170,170,170,180,190,210,214,214,214,      // 214,214,214,212,206,192,176,160,160,160,160,160,160,160,160,160,160,160,160,180,190,210,214,214,214,
	  //             51  52   53  54  55  56  57  58 59  60  61  62  63  64  65  66   67  68  69  70  71 72   73  74  75
					 214,212,206,192,176,172,160,160,160,160,160,160,160,160,160,160,160,160,160,176,192,206,212,214,214,
	  //             76  77  78  79   80  81  82  83  84  85  86  87  88  89  90  91 92  93  94   95  96  97  98  99  100
					 214,214,214,214,214,214,200,190,176,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,
	   //            101 102 103 104 105 106 107 108 109 110 111 112 113 114 115
					 160,160,160,160,160,160,160,160,180,190,210, 214,214,214            };
  /* USER CODE END 1 */


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
						for(float i = y;i<=219;i++)
						{
						ST7789_DrawFilledRectangle(x, i,width, height,BLACK);
						}
				}

void fillgraph2(float x ,float y,uint16_t width ,uint16_t height )
				{
	               float k;
	               k = y;
	              if(k>=170)
	              {//clearing the data in empty portion

	            	  ST7789_DrawFilledRectangle(x, y,width, height,WHITE);
	            	  // 160 is the upper data value by adjusting this value we can increase or decrease upper data position
							for(float i = k;i>=160;i--)
							{ST7789_DrawFilledRectangle(x, i,width, height,WHITE);
							ST7789_DrawFilledRectangle(x, i,width, height,WHITE);
							}
	              }

				ST7789_DrawFilledRectangle(x, y,width, height,BLACK);
				         // 219 is the bottom data value by adjusting this value we can increase or decrease bottom data position
						for(float i = y;i<=219;i++)
						{//draw the graph
						ST7789_DrawFilledRectangle(x, i,width, height,BLACK);
						}
				}
void cleargraph(float x ,float y,uint16_t width ,uint16_t height )
				{
				ST7789_DrawFilledRectangle(x, y,width, height,WHITE);
				        //219 is the bottom data value by adjusting this value we can increase or decrease bottom data position
						for(float i = y;i<=219;i++)
						{//clear the graph
						ST7789_DrawFilledRectangle(x, i,width, height,WHITE);
						}
				}


void drawbattery(int lengthstart,int lengthend,int lengthpostop, int lengthposbottom , int heightstart,int heightend,
		int heightposleft,int heightposright,int tipleightstart,int tipleightend,int tiplnposstart ,int tiplnosend,int tipheightstr ,int tiphightend,int tiphightpos , int fill_battery)
{
	for(int i = lengthstart ;i<=lengthend;i++)
		{
		ST7789_DrawFilledRectangle(i, lengthpostop,1, 1,BLACK);//top
		ST7789_DrawFilledRectangle(i, lengthposbottom,1, 1,BLACK);//bottom
		}
	for(int i = heightstart ;i<=heightend;i++)
		{
		ST7789_DrawFilledRectangle(heightposleft, i,1, 1,BLACK);//sideback
		ST7789_DrawFilledRectangle(heightposright, i,1, 1,BLACK);//side front
		}

	for(int i = tipleightstart ;i<=tipleightend;i++)
		{
		ST7789_DrawFilledRectangle(i, tiplnposstart,1, 1,BLACK);//small top on noc
		ST7789_DrawFilledRectangle(i, tiplnosend,1, 1,BLACK);//small bottom  on noc
		}

	for(int i = tipheightstr ;i<=tiphightend;i++)
		{
		ST7789_DrawFilledRectangle(tiphightpos, i,1, 1,BLACK);//side front on noc
		//ST7789_DrawFilledRectangle(183, i,1, 1,BLACK);
		}


		if(fill_battery == 0)
		  {     for(int  i = 0; i <=11 ; i++ )
			{// max width for filling is 27   9*3
			ST7789_DrawFilledRectangle(202, 12+i,9, 1,WHITE);//main  fill 3
			ST7789_DrawFilledRectangle(211, 12+i,9, 1,WHITE);//main  fill 2
			ST7789_DrawFilledRectangle(220, 12+i,9, 1,WHITE);//main  fill 1


			}
		 for(int  j = 0; j <=3 ; j++ )
				             {
				             ST7789_DrawFilledRectangle(197, 16+j,2, 1,WHITE);//noc fill 4
							// ST7789_DrawFilledRectangle(197, 16+j,2, 1,BLACK);//noc fill 5
				             }


		 }
	if(fill_battery == 1)
	{
		for(int  i = 0; i <=11 ; i++ )
			{
			ST7789_DrawFilledRectangle(202, 12+i,9, 1,WHITE);//main  fill 3
			ST7789_DrawFilledRectangle(211, 12+i,9, 1,WHITE);//main  fill 2
			ST7789_DrawFilledRectangle(220, 12+i,9, 1,BLACK);//main  fill 1


			}
		 for(int  j = 0; j <=3 ; j++ )
				             {
				             ST7789_DrawFilledRectangle(197, 16+j,2, 1,WHITE);//noc fill 4
							// ST7789_DrawFilledRectangle(197, 16+j,2, 1,BLACK);//noc fill 5
				             }

	}
	if (fill_battery == 2)
	{
		for(int  i = 0; i <=11 ; i++ )
					{
					ST7789_DrawFilledRectangle(202, 12+i,9, 1,WHITE);//main  fill 3
					ST7789_DrawFilledRectangle(211, 12+i,9, 1,BLACK);//main  fill 2
					ST7789_DrawFilledRectangle(220, 12+i,9, 1,BLACK);//main  fill 1


					}
				 for(int  j = 0; j <=3 ; j++ )
						             {
						             ST7789_DrawFilledRectangle(197, 16+j,2, 1,WHITE);//noc fill 4
									// ST7789_DrawFilledRectangle(197, 16+j,2, 1,BLACK);//noc fill 5
						             }
	}
	 if (fill_battery == 3)
	{
		 for(int  i = 0; i <=11 ; i++ )
		 			{
		 			ST7789_DrawFilledRectangle(202, 12+i,9, 1,BLACK);//main  fill 3
		 			ST7789_DrawFilledRectangle(211, 12+i,9, 1,BLACK);//main  fill 2
		 			ST7789_DrawFilledRectangle(220, 12+i,9, 1,BLACK);//main  fill 1


		 			}
		 		 for(int  j = 0; j <=3 ; j++ )
		 				             {
		 				             ST7789_DrawFilledRectangle(197, 16+j,2, 1,WHITE);//noc fill 4
		 							// ST7789_DrawFilledRectangle(197, 16+j,2, 1,BLACK);//noc fill 5
		 				             }
	}
	 if (fill_battery == 4)
	{
		 for(int  i = 0; i <=11 ; i++ )
				 			{
				 			ST7789_DrawFilledRectangle(202, 12+i,9, 1,BLACK);//main  fill 3
				 			ST7789_DrawFilledRectangle(211, 12+i,9, 1,BLACK);//main  fill 2
				 			ST7789_DrawFilledRectangle(220, 12+i,9, 1,BLACK);//main  fill 1


				 			}
				 		 for(int  j = 0; j <=3 ; j++ )
				 				             {
				 				             ST7789_DrawFilledRectangle(197, 16+j,2, 1,BLACK);//noc fill 4
				 							// ST7789_DrawFilledRectangle(197, 16+j,2, 1,BLACK);//noc fill 5
				 				             }
	}



}

void dataentry(int curdata,int predata)
{
	int currentdata  ,cdata1,cdata2 ,previousdata ,pdata1,pdata2;
	currentdata = curdata;
	previousdata = predata;
	 cdata1 = currentdata /10;
	 cdata1 = cdata1 %10, cdata2 = currentdata%10;
	 pdata1 = previousdata /10;
	 pdata1 = pdata1 %10, pdata2 = previousdata%10;
	char strp =pdata1 + 48;
	char strp2 =pdata2 + 48;
	char strc = cdata1 + 48;
	char strc2 =cdata2 +48;
	{
		if(strc == strp )
		{
           //do nothing
		}
		else
		{
		//ST7789_WriteChark(10, 40,strc , Font_32x60, BLACK, WHITE);//eto2
			//ST7789_WriteCharpp(10, 40,2,strc,Font_32x35, BLACK, WHITE);
		}
	}

	{
		if(strc2 == strp2 )
		{
			//do nothing
		}
		else
		{
		//ST7789_WriteChark(50, 40,strc2 , Font_32x60, BLACK, WHITE);//eto2
			//ST7789_WriteCharpp(69, 40,2,strc2,Font_32x35_2, BLACK, WHITE);
		}
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
  UG_FillScreen(C_WHITE);
  //ST7789_Fill_Color(WHITE);

  //variables
    uint16_t c, n = 10, i =10;

    float s1, j = 190, x[150] ,temp =5,ran[100],m;

    int cnt = 0;//to enter graph loop
    float y[100], y1[100],y2[100],y3[100],y4[100];
    uint32_t delaytest1 = 100;
    uint16_t widthrt =1 , heightrt =1;

    // graph x axis  this line important to print more data
         for(int i = 0  ;i <= 120 ;i++)
         {
        	 x[i]=temp;
        	 temp = temp+2;
         }


         // draw x axis
    for(int i = 3 ;i<230;i++)
    {
    ST7789_DrawFilledRectangle(i, 220, 2, 2, BLACK);
    }



    //y axis this line import to print more data
    for(int i = 0 ; i <=120;i++)
    {
    	  y2[i] = 170;
    }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

    //ST7789_Fill_Color(WHITE);

    //dataentry(48, 56);
    //dataentry(78, 48);
    /*
    int jj= 9;
    char hh = jj +48;
    ST7789_WriteCharpp(60, 40,2,hh,Font_32x35, BLACK, WHITE);
    */
    /*
    ST7789_Fill_Color(WHITE);
    ST7789_WriteStringk(0, 0, "1234", Font_32x60, BLACK, WHITE);//eto2
    ST7789_WriteStringk(0, 80, "5678", Font_32x60, BLACK, WHITE);//eto2
    ST7789_WriteStringk(0, 160, "90", Font_32x60, BLACK, WHITE);//eto2
    */

    // ST7789_WriteStringpp(0, 0,2,"1234",Font_32x35, BLACK, WHITE);
    // ST7789_WriteStringpp(0, 80,2,"5678",Font_32x35, BLACK, WHITE);
     //ST7789_WriteStringpp(0, 160,2,"90",Font_32x35, BLACK, WHITE);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
 // drawbattery(200, 230, 10, 25, 10, 25, 200, 230, 195, 200, 14, 21, 14, 21, 195,4);
  //ST7789_PutStr(10, 10, "!", &FONT_32X53, C_RED, C_WHITE);
  //  UG_FillScreen(C_WHITE);
    //    UG_FillScreen(C_RED);
      //  ST7789_PutStr(10, 10, "Rectfgfj", &FONT_12X16, C_YELLOW, C_RED);
  while (1)
  {
	//  UG_FillScreen(C_BLACK);
	//  UG_FillScreen(C_GREEN);




 // HAL_Delay(2000);
  //Insert Graph array values 1
  		for(i=0;i<=113;i++)
  		{
  		y[i]=rand1[i];
  		}

  if(cnt==0)
  		{
  		//update number in graph 1
  		for(int i =0 ;i <=113;i++)
  		{

  			if(i==20)
  			{ //ST7789_WriteStringpp(10, 40,2,"36",Font_32x35, BLACK, WHITE);
  				//ST7789_WriteCharpp(10, 40,2,'1',Font_32x35, BLACK, WHITE);
  			//	ST7789_WriteCharpp(60, 40,2,'3',Font_32x35, BLACK, WHITE);
  				//ST7789_WriteStringk(30, 60, "01",Font_32x60, BLACK, WHITE);//eto2
  				//dataentry(78, 25);
  			}
  			else if(i == 44)
  			{ //ST7789_WriteStringpp(10, 40,2,"42",Font_32x35, BLACK, WHITE);
  				//ST7789_WriteCharpp(10, 40,2,'4',Font_32x35, BLACK, WHITE);
  				//ST7789_WriteCharpp(60, 40,2,'8',Font_32x35, BLACK, WHITE);
  				//ST7789_WriteStringk(30, 60, "23", Font_32x60, BLACK, WHITE);//eto2
  				//dataentry(48, 78);
  			}
  			else if(i == 69)
  				{ //ST7789_WriteStringpp(10, 40,2,"36",Font_32x35, BLACK, WHITE);
  				//ST7789_WriteCharpp(10, 40,2,'2',Font_32x35, BLACK, WHITE);
  				//ST7789_WriteCharpp(60, 40,2,'8',Font_32x35, BLACK, WHITE);
  					//ST7789_WriteStringk(30, 60, "45", Font_32x60, BLACK, WHITE);//eto2
  				//dataentry(23, 48);
  				}
  			else if(i == 110)
  				{//ST7789_WriteStringpp(10, 40,2,"43",Font_32x35, BLACK, WHITE);
  				//ST7789_WriteCharpp(10, 40,2,'9',Font_32x35, BLACK, WHITE);
  				//ST7789_WriteCharpp(60, 40,2,'0',Font_32x35, BLACK, WHITE);
  					//ST7789_WriteStringk(30, 60, "67", Font_32x60, BLACK, WHITE);//eto2
  				//dataentry(25, 23);
  				}
  			//make graph 1
  		cleargraph(x[i] ,155,widthrt ,heightrt );
  		cleargraph(x[i+1] ,155,widthrt ,heightrt );
  		fillgraph2(x[i] ,y[i],widthrt ,heightrt );
  		}

  		 //insert previous values for clear the graph
  		for(int i = 0 ;i<=113;i++)
  		{
  			y1[i]=y[i];
  		}
  		cnt=cnt+1;
  		}


  	if(cnt==2)
  		{


  		//insert graph 2 values
  		for(i=0;i<=113;i++)
  		{
  			y[i]=rand2[i];

  		}

  		//make graph 2
  		for(int i =0 ;i <=113;i++)
  		{
  		cleargraph(x[i] ,155,widthrt ,heightrt );
  		cleargraph(x[i+1] ,155,widthrt ,heightrt );
  		fillgraph2(x[i] ,y[i],widthrt ,heightrt );
  		}


  		 //insert previous values for clear the graph
  		for(int i = 0 ; i <=113;i++)
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
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

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
