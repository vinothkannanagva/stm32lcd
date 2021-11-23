#include "st7789.h"




int currentdata=0  ,cdata1=0,cdata2=0 ,previousdata=0 ,pdata1=0,pdata2=0;






/**
 * @brief x and y cordinator
 * @param y2 -> y2 axis
 * @param y1 -> y1 axis
 * @param x2 -> x2 axis
 * @param x1 -> x1 axis
 * @return none
 */
float slope(float y2 ,float y1  ,float x2 , float x1)

{
	float m ;

 m = (y2-y1)/(x2-x1);
return m;

}


/**
 * @brief Write command to ST7789 controller
 * @param cmd -> command to write
 * @return none
 */
static void ST7789_WriteCommand(uint8_t cmd)
{
	ST7789_Select();
	ST7789_DC_Clr();
	HAL_SPI_Transmit(&ST7789_SPI_PORT, &cmd, sizeof(cmd), HAL_MAX_DELAY);
	ST7789_UnSelect();
}


/**
 * @brief Write data to ST7789 controller
 * @param buff -> pointer of data buffer
 * @param buff_size -> size of the data buffer
 * @return none
 */
static void ST7789_WriteData(uint8_t *buff, size_t buff_size)
{
	ST7789_Select();
	ST7789_DC_Set();

	// split data in small chunks because HAL can't send more than 64K at once

	while (buff_size > 0) {
		uint16_t chunk_size = buff_size > 65535 ? 65535 : buff_size;
		HAL_SPI_Transmit(&ST7789_SPI_PORT, buff, chunk_size, HAL_MAX_DELAY);
		buff += chunk_size;
		buff_size -= chunk_size;
	}

	ST7789_UnSelect();
}

 void ST7789_WriteData2(uint8_t *buff, size_t buff_size)
{
	ST7789_Select();
	ST7789_DC_Set();

	// split data in small chunks because HAL can't send more than 64K at once

	while (buff_size > 0) {
		uint16_t chunk_size = buff_size > 65535 ? 65535 : buff_size;
		HAL_SPI_Transmit(&ST7789_SPI_PORT, buff, chunk_size, HAL_MAX_DELAY);
		buff += chunk_size;
		buff_size -= chunk_size;
	}

	ST7789_UnSelect();
}
/**
 * @brief Write data to ST7789 controller, simplify for 8bit data.
 * data -> data to write
 * @return none
 */
static void ST7789_WriteSmallData(uint8_t data)
{
	ST7789_Select();
	ST7789_DC_Set();
	HAL_SPI_Transmit(&ST7789_SPI_PORT, &data, sizeof(data), HAL_MAX_DELAY);
	ST7789_UnSelect();
}

/**
 * @brief Set the rotation direction of the display
 * @param m -> rotation parameter(please refer it in st7789.h)
 * @return none
 */
void ST7789_SetRotation(uint8_t m)
{
	ST7789_WriteCommand(ST7789_MADCTL);	// MADCTL
	switch (m) {
	case 0:
		ST7789_WriteSmallData(ST7789_MADCTL_MX | ST7789_MADCTL_MY | ST7789_MADCTL_RGB);
		break;
	case 1:
		ST7789_WriteSmallData(ST7789_MADCTL_MY | ST7789_MADCTL_MV | ST7789_MADCTL_RGB);
		break;
	case 2:
		ST7789_WriteSmallData(ST7789_MADCTL_RGB);
		break;
	case 3:
		ST7789_WriteSmallData(ST7789_MADCTL_MX | ST7789_MADCTL_MV | ST7789_MADCTL_RGB);
		break;
	default:
		break;
	}
}

/**
 * @brief Set address of DisplayWindow
 * @param xi&yi -> coordinates of window
 * @return none
 */
static void ST7789_SetAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
	ST7789_Select();
	uint16_t x_start = x0 + X_SHIFT, x_end = x1 + X_SHIFT;
	uint16_t y_start = y0 + Y_SHIFT, y_end = y1 + Y_SHIFT;
	
	/* Column Address set */
	ST7789_WriteCommand(ST7789_CASET); 
	{
		uint8_t data[] = {x_start >> 8, x_start & 0xFF, x_end >> 8, x_end & 0xFF};
		ST7789_WriteData(data, sizeof(data));
	}

	/* Row Address set */
	ST7789_WriteCommand(ST7789_RASET);
	{
		uint8_t data[] = {y_start >> 8, y_start & 0xFF, y_end >> 8, y_end & 0xFF};
		ST7789_WriteData(data, sizeof(data));
	}
	/* Write to RAM */
	ST7789_WriteCommand(ST7789_RAMWR);
	ST7789_UnSelect();
}

 void ST7789_SetAddressWindow2(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
	ST7789_Select();
	uint16_t x_start = x0 + X_SHIFT, x_end = x1 + X_SHIFT;
	uint16_t y_start = y0 + Y_SHIFT, y_end = y1 + Y_SHIFT;

	/* Column Address set */
	ST7789_WriteCommand(ST7789_CASET);
	{
		uint8_t data[] = {x_start >> 8, x_start & 0xFF, x_end >> 8, x_end & 0xFF};
		ST7789_WriteData(data, sizeof(data));
	}

	/* Row Address set */
	ST7789_WriteCommand(ST7789_RASET);
	{
		uint8_t data[] = {y_start >> 8, y_start & 0xFF, y_end >> 8, y_end & 0xFF};
		ST7789_WriteData(data, sizeof(data));
	}
	/* Write to RAM */
	ST7789_WriteCommand(ST7789_RAMWR);
	ST7789_UnSelect();
}
/**
 * @brief Initialize ST7789 controller
 * @param none
 * @return none
 */
void ST7789_Init(void)
{
	HAL_Delay(25);
    ST7789_RST_Clr();
    HAL_Delay(25);
    ST7789_RST_Set();
    HAL_Delay(100);
   // ST7789_WriteCommand(ST7789_COLMOD);
    ST7789_WriteCommand(ST7789_COLMOD);		//	Set color mode
    ST7789_WriteSmallData(ST7789_COLOR_MODE_16bit);
  	ST7789_WriteCommand(0xB2);				//	Porch control
	{   //uint8_t data[] = {0x01, 0x01, 0x00, 0x11, 0x11};//new
		uint8_t data[] = {0x0C, 0x0C, 0x00, 0x33, 0x33};//old
		ST7789_WriteData(data, sizeof(data));
	}
	ST7789_SetRotation(ST7789_ROTATION);	//	MADCTL (Display Rotation)
	
	/* Internal LCD Voltage generator settings */
	    ST7789_WriteCommand(0XB7);				//	Gate Control
	    ST7789_WriteSmallData(0x35);			//	Default value
	    ST7789_WriteCommand(0xBB);				//	VCOM setting
	    ST7789_WriteSmallData(0x19);			//	0.725v (default 0.75v for 0x20)
	    ST7789_WriteCommand(0xC0);				//	LCMCTRL
	    ST7789_WriteSmallData (0x2C);			//	Default value
	    ST7789_WriteCommand (0xC2);				//	VDV and VRH command Enable
	    ST7789_WriteSmallData (0x01);			//	Default value
	    ST7789_WriteCommand (0xC3);				//	VRH set
	    ST7789_WriteSmallData (0x14);			//	+-4.45v (defalut +-4.1v for 0x0B)
	    ST7789_WriteCommand (0xC4);				//	VDV set
	    ST7789_WriteSmallData (0x20);			//	Default value
	    ST7789_WriteCommand (0xC6);				//	Frame rate control in normal mode
	    ST7789_WriteSmallData (0x01);			//	Default value (60HZ)
	    ST7789_WriteCommand (0xD0);				//	Power control
	    ST7789_WriteSmallData (0xA4);			//	Default value
	    ST7789_WriteSmallData (0xA1);			//	Default value

	/**************** Division line ****************/

	ST7789_WriteCommand(0xE0);
	{
		uint8_t data[] = {0xD0, 0x04, 0x0D, 0x11, 0x13, 0x2B, 0x3F, 0x54, 0x4C, 0x18, 0x0D, 0x0B, 0x1F, 0x23};
		ST7789_WriteData(data, sizeof(data));
	}

    ST7789_WriteCommand(0xE1);
	{
		uint8_t data[] = {0xD0, 0x04, 0x0C, 0x11, 0x13, 0x2C, 0x3F, 0x44, 0x51, 0x2F, 0x1F, 0x1F, 0x20, 0x23};
		ST7789_WriteData(data, sizeof(data));
	}
    ST7789_WriteCommand (ST7789_INVON);		//	Inversion ON
	ST7789_WriteCommand (ST7789_SLPOUT);	//	Out of sleep mode
  	ST7789_WriteCommand (ST7789_NORON);		//	Normal Display on
  	ST7789_WriteCommand (ST7789_DISPON);	//	Main screen turned on	
	HAL_Delay(50);
	ST7789_Fill_Color(BLACK);				//	Fill with Black.
}

/**
 * @brief Fill the DisplayWindow with single color
 * @param color -> color to Fill with
 * @return none
 */
void ST7789_Fill_Color(uint16_t color)
{
register uint16_t i, j;
	ST7789_SetAddressWindow(0, 0, ST7789_WIDTH - 1, ST7789_HEIGHT - 1);
	ST7789_Select();
	for (i = 0; i < ST7789_WIDTH; i++)
	{
		//HAL_Delay(1);
		for (j = 0; j < ST7789_HEIGHT; j++) {
			//HAL_Delay(1);
			uint8_t data[] = {color >> 8, color & 0xFF};
			ST7789_WriteData(data, sizeof(data));
		}
	}
	ST7789_UnSelect();
}

void ST7789_Fill_Color2(uint16_t color)
{
	uint16_t i, j;
	ST7789_SetAddressWindow(0, 0, ST7789_WIDTH - 1, ST7789_HEIGHT - 1);
	ST7789_Select();

		//HAL_Delay(1);
		for (j = 0; j <57360; j++) {
			//HAL_Delay(1);
			uint8_t data[] = {color >> 8, color & 0xFF};
			ST7789_WriteData(data, sizeof(data));
		}

	ST7789_UnSelect();
}
/**
 * @brief Draw a Pixel
 * @param x&y -> coordinate to Draw
 * @param color -> color of the Pixel
 * @return none
 */
void ST7789_DrawPixel(uint16_t x, uint16_t y, uint16_t color)
{
	if ((x < 0) || (x >= ST7789_WIDTH) ||
		 (y < 0) || (y >= ST7789_HEIGHT))	return;
	
	ST7789_SetAddressWindow(x, y, x, y);
	uint8_t data[] = {color >> 8, color & 0xFF};
	ST7789_Select();
	ST7789_WriteData(data, sizeof(data));
	ST7789_UnSelect();
}

/**
 * @brief Fill an Area with single color
 * @param xSta&ySta -> coordinate of the start point
 * @param xEnd&yEnd -> coordinate of the end point
 * @param color -> color to Fill with
 * @return none
 */
void ST7789_Fill(uint16_t xSta, uint16_t ySta, uint16_t xEnd, uint16_t yEnd, uint16_t color)
{
	if ((xEnd < 0) || (xEnd >= ST7789_WIDTH) ||
		 (yEnd < 0) || (yEnd >= ST7789_HEIGHT))	return;
	ST7789_Select();
	uint16_t i, j;
	ST7789_SetAddressWindow(xSta, ySta, xEnd, yEnd);
	for (i = ySta; i <= yEnd; i++)
		for (j = xSta; j <= xEnd; j++) {
			uint8_t data[] = {color >> 8, color & 0xFF};
			ST7789_WriteData(data, sizeof(data));
		}
	ST7789_UnSelect();
}

/**
 * @brief Draw a big Pixel at a point
 * @param x&y -> coordinate of the point
 * @param color -> color of the Pixel
 * @return none
 */
void ST7789_DrawPixel_4px(uint16_t x, uint16_t y, uint16_t color)
{
	if ((x <= 0) || (x > ST7789_WIDTH) ||
		 (y <= 0) || (y > ST7789_HEIGHT))	return;
	ST7789_Select();
	ST7789_Fill(x - 1, y - 1, x + 1, y + 1, color);
	ST7789_UnSelect();
}

/**
 * @brief Draw a line with single color
 * @param x1&y1 -> coordinate of the start point
 * @param x2&y2 -> coordinate of the end point
 * @param color -> color of the line to Draw
 * @return none
 */
void ST7789_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1,
        uint16_t color) {
	uint16_t swap;
    uint16_t steep = ABS(y1 - y0) > ABS(x1 - x0);
    if (steep) {
		swap = x0;
		x0 = y0;
		y0 = swap;

		swap = x1;
		x1 = y1;
		y1 = swap;
        //_swap_int16_t(x0, y0);
        //_swap_int16_t(x1, y1);
    }

    if (x0 > x1) {
		swap = x0;
		x0 = x1;
		x1 = swap;

		swap = y0;
		y0 = y1;
		y1 = swap;
        //_swap_int16_t(x0, x1);
        //_swap_int16_t(y0, y1);
    }

    int16_t dx, dy;
    dx = x1 - x0;
    dy = ABS(y1 - y0);

    int16_t err = dx / 2;
    int16_t ystep;

    if (y0 < y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }

    for (; x0<=x1; x0++) {
        if (steep) {
            ST7789_DrawPixel(y0, x0, color);
        } else {
            ST7789_DrawPixel(x0, y0, color);
        }
        err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
}

/**
 * @brief Draw a Rectangle with single color
 * @param xi&yi -> 2 coordinates of 2 top points.
 * @param color -> color of the Rectangle line
 * @return none
 */
void ST7789_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
	ST7789_Select();
	ST7789_DrawLine(x1, y1, x2, y1, color);
	ST7789_DrawLine(x1, y1, x1, y2, color);
	ST7789_DrawLine(x1, y2, x2, y2, color);
	ST7789_DrawLine(x2, y1, x2, y2, color);
	ST7789_UnSelect();
}

/** 
 * @brief Draw a circle with single color
 * @param x0&y0 -> coordinate of circle center
 * @param r -> radius of circle
 * @param color -> color of circle line
 * @return  none
 */
void ST7789_DrawCircle(uint16_t x0, uint16_t y0, uint8_t r, uint16_t color)
{
	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;

	ST7789_Select();
	ST7789_DrawPixel(x0, y0 + r, color);
	ST7789_DrawPixel(x0, y0 - r, color);
	ST7789_DrawPixel(x0 + r, y0, color);
	ST7789_DrawPixel(x0 - r, y0, color);

	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		ST7789_DrawPixel(x0 + x, y0 + y, color);
		ST7789_DrawPixel(x0 - x, y0 + y, color);
		ST7789_DrawPixel(x0 + x, y0 - y, color);
		ST7789_DrawPixel(x0 - x, y0 - y, color);

		ST7789_DrawPixel(x0 + y, y0 + x, color);
		ST7789_DrawPixel(x0 - y, y0 + x, color);
		ST7789_DrawPixel(x0 + y, y0 - x, color);
		ST7789_DrawPixel(x0 - y, y0 - x, color);
	}
	ST7789_UnSelect();
}

/**
 * @brief Draw an Image on the screen
 * @param x&y -> start point of the Image
 * @param w&h -> width & height of the Image to Draw
 * @param data -> pointer of the Image array
 * @return none
 */
void ST7789_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t *data)
{
	if ((x >= ST7789_WIDTH) || (y >= ST7789_HEIGHT))
		return;
	if ((x + w - 1) >= ST7789_WIDTH)
		return;
	if ((y + h - 1) >= ST7789_HEIGHT)
		return;

	ST7789_Select();
	ST7789_SetAddressWindow(x, y, x + w - 1, y + h - 1);
	ST7789_WriteData((uint8_t *)data, sizeof(uint16_t) * w * h);
	ST7789_UnSelect();
}

void ST7789_DrawImage2(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t data)
{
	if ((x >= ST7789_WIDTH) || (y >= ST7789_HEIGHT))
		return;
	if ((x + w - 1) >= ST7789_WIDTH)
		return;
	if ((y + h - 1) >= ST7789_HEIGHT)
		return;

	ST7789_Select();
	ST7789_SetAddressWindow(x, y, x + w - 1, y + h - 1);
	ST7789_WriteData((uint8_t *)data, sizeof(uint16_t) * w * h);
	ST7789_UnSelect();
}

/**
 * @brief Invert Fullscreen color
 * @param invert -> Whether to invert
 * @return none
 */
void ST7789_InvertColors(uint8_t invert)
{
	ST7789_Select();
	ST7789_WriteCommand(invert ? 0x21 /* INVON */ : 0x20 /* INVOFF */);
	ST7789_UnSelect();
}

/** 
 * @brief Write a char
 * @param  x&y -> cursor of the start point.
 * @param ch -> char to write
 * @param font -> fontstyle of the string
 * @param color -> color of the char
 * @param bgcolor -> background color of the char
 * @return  none
 */
void ST7789_WriteCharj(uint16_t x, uint16_t y, char ch, FontDef font, uint16_t color, uint16_t bgcolor)
{
	uint32_t i, b, j;
	ST7789_Select();

	ST7789_SetAddressWindow(x, y, x + font.width - 1, y + font.height - 1);

	for (i = 0; i < font.height; i++) {
		b = font.data[(ch - 32) * font.height + i];
		for (j = 0; j < font.width; j++) {
			if ((b << j) & 0x8000) {
				uint8_t data[] = {color >> 8, color & 0xFF};
				ST7789_WriteData(data, sizeof(data));
			}
			else {
				uint8_t data[] = {bgcolor >> 8, bgcolor & 0xFF};
				ST7789_WriteData(data, sizeof(data));
			}
		}
	}
	ST7789_UnSelect();
}
void ST7789_WriteStringj(uint16_t x, uint16_t y, char *str, FontDef font, uint16_t color, uint16_t bgcolor)
{
	ST7789_Select();
	while (*str) {
		if (x + font.width >= ST7789_WIDTH) {
			x = 0;
			y += font.height;
			if (y + font.height >= ST7789_HEIGHT) {
				break;
			}

			if (*str == ' ') {
				// skip spaces in the beginning of the new line
				str++;
				continue;
			}
		}
		ST7789_WriteCharj(x, y, *str, font, color, bgcolor);
		x += font.width;
		str++;
	}
	ST7789_UnSelect();
}
void ST7789_WriteChar(uint32_t x, uint32_t y, char ch, FontDef font, uint32_t color, uint32_t bgcolor)
{
	uint32_t i, b, j;
	ST7789_Select();
	ST7789_SetAddressWindow(x, y, x + font.width - 1, y + font.height - 1);
	for (i = 0; i < font.height; i++) {
		b = font.data[(ch - 32) * font.height + i];
		for (j = 0; j < font.width; j++) {
			if ((b << j) & 0x8000) {
				uint8_t data[] = {color >> 8, color & 0xFF};
				ST7789_WriteData(data, sizeof(data));
			}
			else {
				uint8_t data[] = {bgcolor >> 8, bgcolor & 0xFF};
				ST7789_WriteData(data, sizeof(data));
			}
		}
	}
	ST7789_UnSelect();
}

void ST7789_WriteString(uint32_t x, uint32_t y, char *str, FontDef font, uint32_t color, uint32_t bgcolor)
{
	ST7789_Select();//ss pin spi start
	while (*str) {
		if (x + font.width >= ST7789_WIDTH) {
			x = 0;
			y += font.height;
			if (y + font.height >= ST7789_HEIGHT) {
				break;
			}

			if (*str == ' ') {
				// skip spaces in the beginning of the new line
				str++;
				continue;
			}
		}
		ST7789_WriteChar(x, y,*str, font, color, bgcolor);
		x += font.width;
		str++;
	}
	ST7789_UnSelect();
}

void ST7789_WriteCharpp(uint32_t x, uint32_t y, uint32_t size,char ch, FontDef1 font, uint32_t color, uint32_t bgcolor)
{
	register uint32_t f,i, b, j,k;
	//uint32_t size = 6;
	ST7789_Select();
	ST7789_SetAddressWindow(x, y, x + font.width*size - 1, y + font.height*size - 1);
	for (i = 0,k=0; i < font.height*size; i++) {

		if(i%size==0)
		{
		b = font.data[(ch - 48) * font.height + i/size];
		}
		else
		{
			b = font.data[(ch - 48) * font.height + (i-1)/size];
		}

		for (j = 0; j < font.width; j++) {
			if ((b << j) & 0x80000000) {
				//ST7789_DrawFilledRectangle(i, j,2, 2, BLACK);
				uint8_t data[] = {color >> 8, color & 0xFF};
				for( f=0;f<size;f++)
				{
				ST7789_WriteData(data, sizeof(data));
				/*ST7789_WriteData(data, sizeof(data));
				ST7789_WriteData(data, sizeof(data));
				ST7789_WriteData(data, sizeof(data));
				ST7789_WriteData(data, sizeof(data));
								ST7789_WriteData(data, sizeof(data));
								ST7789_WriteData(data, sizeof(data));
								ST7789_WriteData(data, sizeof(data));*/
				}

			}
			else {
				//ST7789_DrawFilledRectangle(i, j, 2, 2, WHITE);
			  uint8_t data[] = {bgcolor >> 8, bgcolor & 0xFF};
				for(uint32_t bg=0;bg<size;bg++)
				{
				ST7789_WriteData(data, sizeof(data));
				}

			}
		}
	}
	ST7789_UnSelect();
}

void ST7789_WriteStringpp(uint32_t x, uint32_t y, uint32_t size,char *str, FontDef1 font, uint32_t color, uint32_t bgcolor)
{
	ST7789_Select();//ss pin spi start
	//ST7789_WriteCharpp(x, y,*str, font, color, bgcolor);
	//y=y+30;
	while (*str) {
		/*if (x + font.width >= ST7789_WIDTH) {
			x = 0;
			y += font.height;
			if (y + font.height >= ST7789_HEIGHT) {
				break;
			}

			if (*str == ' ') {
				// skip spaces in the beginning of the new line
				str++;
				continue;
			}
		}*/
		ST7789_WriteCharpp(x, y,size,*str, font, color, bgcolor);
		x += (font.width+20);
		str++;
	}
	ST7789_UnSelect();
}
void ST7789_WriteChark(uint32_t x, uint32_t y, char ch, FontDef1 font, uint32_t color, uint32_t bgcolor)
{
	uint32_t i, b, j;
	ST7789_Select();
	ST7789_SetAddressWindow(x, y, x + font.width - 1, y + font.height - 1);

	for (i = 0; i < font.height; i++) {
		b = font.data[(ch - 48) * font.height + i];
		for (j = 0; j < font.width; j++) {
			if ((b << j) & 0x80000000) {
				uint8_t data[] = {color >> 8, color & 0xFF};
				ST7789_WriteData(data, sizeof(data));
			}
			else {
				uint8_t data[] = {bgcolor >> 8, bgcolor & 0xFF};
				ST7789_WriteData(data, sizeof(data));
			}
		}
	}
	ST7789_UnSelect();
}
void ST7789_WriteStringk(uint32_t x, uint32_t y, char *str, FontDef1 font, uint32_t color, uint32_t bgcolor)
{
	ST7789_Select();
	while (*str) {
		if (x + font.width >= ST7789_WIDTH) {
			x = 0;
			y += font.height;
			if (y + font.height >= ST7789_HEIGHT) {
				break;
			}

			if (*str == ' ') {
				// skip spaces in the beginning of the new line
				str++;
				continue;
			}
		}
		ST7789_WriteChark(x, y, *str, font, color, bgcolor);
		x += font.width;
		str++;
	}
	ST7789_UnSelect();
}

void ST7789_WriteCharg(uint8_t x, uint8_t y, char ch, FontDef2 font, uint16_t color, uint16_t bgcolor)
{
	uint16_t i, j,w,h,byteWidth;
	uint16_t y_temp = y;
	uint8_t b=0;
	byteWidth  = (w + 7) / 8;
	ST7789_Select();
	//ST7789_SetAddressWindow(x, y, x + font.width - 1, y + font.height - 1);
	for (i = 0; i < font.height; i++,y_temp++)
	{
		//b = font.data[(ch - 48) * font.height + i];


		for (j = 0; j < font.width; j++)
		{


			if (j & 7)
				{
					b <<= 1;
				}
			else
			{
			b =  font.data[(((ch-48)*54)+(i * byteWidth) + j / 8)];

			}

			if ((b) & 0x80) {

				ST7789_DrawPixel(x+j, y_temp, color);


			//	uint8_t data[] = {color >> 8, color & 0xFF};
				//ST7789_WriteData(data, sizeof(data));
			}
			else {

				ST7789_DrawPixel(x+j, y_temp, bgcolor);
				//uint8_t data[] = {bgcolor >> 8, bgcolor & 0xFF};
				//ST7789_WriteData(data, sizeof(data));
			}
		}
	}

	y_temp=y;
	x += 14;



	ST7789_UnSelect();
}

void ST7789_WriteCharkk(uint32_t x, uint32_t y, uint16_t sizek, char ch, FontDef font, uint32_t color, uint32_t bgcolor)
{
	uint32_t i, b, j;
	ST7789_Select();
	ST7789_SetAddressWindow(x, y, x + font.width - 1, y + font.height - 1);

	for (i = 0; i < font.height; i++) {
		b = font.data[(ch - 32) * font.height + i];
		for (j = 0; j < font.width; j++) {

			if ((b << j) & 0x80000000) {
				uint8_t data[] = {color >> 8, color & 0xFF};
				if(sizek==1)
					{
					ST7789_WriteData(data, sizeof(data));
					}
				else
				{
					ST7789_DrawFilledRectangle(x+(j*sizek), y+(i*sizek), sizek, sizek,  color);
				}
			}
			else {
				uint8_t data[] = {bgcolor >> 8, bgcolor & 0xFF};

					//ST7789_WriteData(data, sizeof(data));

				if(sizek==1)
									{
									ST7789_WriteData(data, sizeof(data));
									}
								else
								{
									ST7789_DrawFilledRectangle(x+(j*sizek), y+(i*sizek), sizek, sizek,  bgcolor);
								}


			}
		}
	}
	ST7789_UnSelect();
}
void ST7789_WriteStringkk(uint32_t x, uint32_t y,uint16_t sizek, char *str, FontDef font, uint32_t color, uint32_t bgcolor)
{
	ST7789_Select();
	while (*str) {
		if (x + font.width >= ST7789_WIDTH) {
			x = 0;
			y += font.height;
			if (y + font.height >= ST7789_HEIGHT) {
				break;
			}

			if (*str == ' ') {
				// skip spaces in the beginning of the new line
				str++;
				continue;
			}
		}
		ST7789_WriteCharkk(x, y,sizek, *str, font, color, bgcolor);
		x += font.width;
		str++;
	}
	ST7789_UnSelect();
}



/** 
 * @brief Write a string 
 * @param  x&y -> cursor of the start point.
 * @param str -> string to write
 * @param font -> fontstyle of the string
 * @param color -> color of the string
 * @param bgcolor -> background color of the string
 * @return  none
 */


/** 
 * @brief Draw a filled Rectangle with single color
 * @param  x&y -> coordinates of the starting point
 * @param w&h -> width & height of the Rectangle
 * @param color -> color of the Rectangle
 * @return  none
 */
void ST7789_DrawFilledRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
	ST7789_Select();
	uint8_t i;

	/* Check input parameters */
	if (x >= ST7789_WIDTH ||
		y >= ST7789_HEIGHT) {
		/* Return error */
		return;
	}

	/* Check width and height */
	if ((x + w) >= ST7789_WIDTH) {
		w = ST7789_WIDTH - x;
	}
	if ((y + h) >= ST7789_HEIGHT) {
		h = ST7789_HEIGHT - y;
	}

	/* Draw lines */
	for (i = 0; i <= h; i++) {
		/* Draw lines */
		ST7789_DrawLine(x, y + i, x + w, y + i, color);
	}
	ST7789_UnSelect();
}

void ST7789_DrawFilledRectanglek(uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color)
{
	ST7789_Select();
	uint32_t i;

	/* Check input parameters */
	if (x >= ST7789_WIDTH ||
		y >= ST7789_HEIGHT) {
		/* Return error */
		return;
	}

	/* Check width and height */
	if ((x + w) >= ST7789_WIDTH) {
		w = ST7789_WIDTH - x;
	}
	if ((y + h) >= ST7789_HEIGHT) {
		h = ST7789_HEIGHT - y;
	}

	/* Draw lines */
	for (i = 0; i <= h; i++) {
		/* Draw lines */
		ST7789_DrawLine(x, y + i, x + w, y + i, color);
	}
	ST7789_UnSelect();
}



/** 
 * @brief Draw a Triangle with single color
 * @param  xi&yi -> 3 coordinates of 3 top points.
 * @param color ->color of the lines
 * @return  none
 */
void ST7789_DrawTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t color)
{
	ST7789_Select();
	/* Draw lines */
	ST7789_DrawLine(x1, y1, x2, y2, color);
	ST7789_DrawLine(x2, y2, x3, y3, color);
	ST7789_DrawLine(x3, y3, x1, y1, color);
	ST7789_UnSelect();
}

/** 
 * @brief Draw a filled Triangle with single color
 * @param  xi&yi -> 3 coordinates of 3 top points.
 * @param color ->color of the triangle
 * @return  none
 */
void ST7789_DrawFilledTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t color)
{
	ST7789_Select();
	int16_t deltax = 0, deltay = 0, x = 0, y = 0, xinc1 = 0, xinc2 = 0,
			yinc1 = 0, yinc2 = 0, den = 0, num = 0, numadd = 0, numpixels = 0,
			curpixel = 0;

	deltax = ABS(x2 - x1);
	deltay = ABS(y2 - y1);
	x = x1;
	y = y1;

	if (x2 >= x1) {
		xinc1 = 1;
		xinc2 = 1;
	}
	else {
		xinc1 = -1;
		xinc2 = -1;
	}

	if (y2 >= y1) {
		yinc1 = 1;
		yinc2 = 1;
	}
	else {
		yinc1 = -1;
		yinc2 = -1;
	}

	if (deltax >= deltay) {
		xinc1 = 0;
		yinc2 = 0;
		den = deltax;
		num = deltax / 2;
		numadd = deltay;
		numpixels = deltax;
	}
	else {
		xinc2 = 0;
		yinc1 = 0;
		den = deltay;
		num = deltay / 2;
		numadd = deltax;
		numpixels = deltay;
	}

	for (curpixel = 0; curpixel <= numpixels; curpixel++) {
		ST7789_DrawLine(x, y, x3, y3, color);

		num += numadd;
		if (num >= den) {
			num -= den;
			x += xinc1;
			y += yinc1;
		}
		x += xinc2;
		y += yinc2;
	}
	ST7789_UnSelect();
}

/** 
 * @brief Draw a Filled circle with single color
 * @param x0&y0 -> coordinate of circle center
 * @param r -> radius of circle
 * @param color -> color of circle
 * @return  none
 */
void ST7789_DrawFilledCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
	ST7789_Select();
	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;

	ST7789_DrawPixel(x0, y0 + r, color);
	ST7789_DrawPixel(x0, y0 - r, color);
	ST7789_DrawPixel(x0 + r, y0, color);
	ST7789_DrawPixel(x0 - r, y0, color);
	ST7789_DrawLine(x0 - r, y0, x0 + r, y0, color);

	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		ST7789_DrawLine(x0 - x, y0 + y, x0 + x, y0 + y, color);
		ST7789_DrawLine(x0 + x, y0 - y, x0 - x, y0 - y, color);

		ST7789_DrawLine(x0 + y, y0 + x, x0 - y, y0 + x, color);
		ST7789_DrawLine(x0 + y, y0 - x, x0 - y, y0 - x, color);
	}
	ST7789_UnSelect();
}


/**
 * @brief Open/Close tearing effect line
 * @param tear -> Whether to tear
 * @return none
 */
void ST7789_TearEffect(uint8_t tear)
{
	ST7789_Select();
	ST7789_WriteCommand(tear ? 0x35 /* TEON */ : 0x34 /* TEOFF */);
	ST7789_UnSelect();
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
	if(curdata<=0)
	curdata=0;
	if(curdata>60)
		curdata=60;

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

		if(strc == strp )
		{
		   //do nothing
		}
		if(strc != strp )
		{
		//ST7789_WriteChark(10, 40,strc , Font_32x60, BLACK, WHITE);//eto2
			ST7789_WriteCharpp(10, 40,2,strc,Font_32x35, BLACK, WHITE);
		}
		if(strc2 == strp2 )
		{
			//do nothing
		}
		if(strc2 != strp2 )
		{
		//ST7789_WriteChark(50, 40,strc2 , Font_32x60, BLACK, WHITE);//eto2
			ST7789_WriteCharpp(69, 40,2,strc2,Font_32x35_2, BLACK, WHITE);
		}



}

void Capnography_AgVa_Logo()
 {
//initial logo
 ST7789_WriteString(40,70, "CAPNOGRAPHY", Font_16x26, BLUE,WHITE);
 ST7789_WriteString(90,100, "AgVa", Font_16x26, RED,WHITE);
 ST7789_WriteString(40,130, "Healthcare", Font_16x26, BLACK,WHITE);
 ST7789_Fill_Color(WHITE);
 }
/** 
 * @brief A Simple test function for ST7789
 * @param  none
 * @return  none
 */
void ST7789_Test(void)
{
	ST7789_Fill_Color(WHITE);
	HAL_Delay(1000);
	ST7789_WriteString(10, 20, "Speed Test", Font_11x18, RED, WHITE);
	HAL_Delay(1000);
	ST7789_Fill_Color(CYAN);
    HAL_Delay(500);
	ST7789_Fill_Color(RED);
    HAL_Delay(500);
	ST7789_Fill_Color(BLUE);
    HAL_Delay(500);
	ST7789_Fill_Color(GREEN);
    HAL_Delay(500);
	ST7789_Fill_Color(YELLOW);
    HAL_Delay(500);
	ST7789_Fill_Color(BROWN);
    HAL_Delay(500);
	ST7789_Fill_Color(DARKBLUE);
    HAL_Delay(500);
	ST7789_Fill_Color(MAGENTA);
    HAL_Delay(500);
	ST7789_Fill_Color(LIGHTGREEN);
    HAL_Delay(500);
	ST7789_Fill_Color(LGRAY);
    HAL_Delay(500);
	ST7789_Fill_Color(LBBLUE);
    HAL_Delay(500);
	ST7789_Fill_Color(WHITE);
	HAL_Delay(500);

	ST7789_WriteString(10, 10, "Font test.", Font_16x26, GBLUE, WHITE);
	ST7789_WriteString(10, 50, "Hello Steve!", Font_7x10, RED, WHITE);
	ST7789_WriteString(10, 75, "Hello Steve!", Font_11x18, YELLOW, WHITE);
	ST7789_WriteString(10, 100, "Hello Steve!", Font_16x26, MAGENTA, WHITE);
	HAL_Delay(1000);

	ST7789_Fill_Color(RED);
	ST7789_WriteString(10, 10, "Rect./Line.", Font_11x18, YELLOW, RED);
	ST7789_DrawRectangle(30, 30, 100, 100, WHITE);
	HAL_Delay(1000);

	ST7789_Fill_Color(RED);
	ST7789_WriteString(10, 10, "Filled Rect.", Font_11x18, YELLOW, RED);
	ST7789_DrawFilledRectangle(30, 30, 50, 50, WHITE);
	HAL_Delay(1000);


	ST7789_Fill_Color(RED);
	ST7789_WriteString(10, 10, "Circle.", Font_11x18, YELLOW, RED);
	ST7789_DrawCircle(60, 60, 25, WHITE);
	HAL_Delay(1000);

	ST7789_Fill_Color(RED);
	ST7789_WriteString(10, 10, "Filled Cir.", Font_11x18, YELLOW, RED);
	ST7789_DrawFilledCircle(60, 60, 25, WHITE);
	HAL_Delay(1000);

	ST7789_Fill_Color(RED);
	ST7789_WriteString(10, 10, "Triangle", Font_11x18, YELLOW, RED);
	ST7789_DrawTriangle(30, 30, 30, 70, 60, 40, WHITE);
	HAL_Delay(1000);

	ST7789_Fill_Color(RED);
	ST7789_WriteString(10, 10, "Filled Tri", Font_11x18, YELLOW, RED);
	ST7789_DrawFilledTriangle(30, 30, 30, 70, 60, 40, WHITE);
	HAL_Delay(1000);

	//	If FLASH cannot storage anymore datas, please delete codes below.
	ST7789_Fill_Color(WHITE);
	//ST7789_DrawImage(0, 0, 128, 128, (uint16_t *)saber);

}




