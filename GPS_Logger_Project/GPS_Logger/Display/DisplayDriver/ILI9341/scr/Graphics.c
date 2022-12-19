//Увеличение пикселя происходит вправо и вверх
//Дисплей:
//
/*   0  --------------------------------------------------------> X
		|
		|
		|
		|
		|
		|
		|
		|
		|

		Y

*/

#include "Graphics.h"
#include "ILI9341_Driver.h"

DisplayOrientation CurrentOrientation = Portrait;


void Display_SetOrientation(DisplayOrientation Orientation)
{
	SendCommand(LCD_MAC);

	switch(Orientation)
	{
	case Portrait:
		DataBuffer[0] = ORIENTATION_PORTRAIT;
		break;

	case Landscape:
		DataBuffer[0] = ORIENTATION_LANDSCAPE;
		break;

	default:
		DataBuffer[0] = ORIENTATION_PORTRAIT;
		break;
	}

	SendData(DataBuffer, 1);

	CurrentOrientation = Orientation;
}


void Display_SetCursorPosition(uint16_t x, uint16_t y)
{
	SendCommand(LCD_COLUMN_ADDR);
	
	DataBuffer[0] = x >> 8;
	DataBuffer[1] = x & 0xFF;
	DataBuffer[2] = x >> 8;
	DataBuffer[3] = x & 0xFF;
	SendData(DataBuffer, 4);
	
	
	SendCommand(LCD_PAGE_ADDR);
	
	DataBuffer[0] = y >> 8;
	DataBuffer[1] = y & 0xFF;
	DataBuffer[2] = y >> 8;
	DataBuffer[3] = y & 0xFF;
	SendData(DataBuffer, 4);
}


void Display_DrawPixel(uint16_t x, uint16_t y, uint16_t Color)
{
	Display_SetCursorPosition(x, y);

	SendCommand(LCD_GRAM);
	
	DataBuffer[0] = Color;
	SendData(DataBuffer, 1);
}


void Display_DrawLine_Vertical(uint16_t x0, uint16_t y0, uint16_t Length, uint16_t Color)
{
	for (uint16_t PixelCounter = 0; PixelCounter < Length; PixelCounter++)
	{
		Display_DrawPixel(x0, y0 + PixelCounter, Color);
	}
}


void Display_DrawLine_Horizontal(uint16_t x0, uint16_t y0, uint16_t Length, uint16_t Color)
{
	for (uint16_t PixelCounter = 0; PixelCounter < Length; PixelCounter++)
	{
		Display_DrawPixel(x0 + PixelCounter, y0, Color);
	}
}


//Заливка экрана попиксельно
void Display_FillScreen(uint16_t color)
{
	if (CurrentOrientation == Portrait)
	{
		Display_SetWindow(0, 0, 239, 319);
	}

	else
	{
		Display_SetWindow(0, 0, 319, 239);
	}
	
	uint16_t NumberOfPixels = 19200;
	
	SendCommand(LCD_GRAM);

	for (uint16_t i = 0; i < NumberOfPixels; i++)
	{
		DataBuffer[i] = color;
	} 

	for (uint8_t r = 0; r < 8; r++)
	{
		SendData(DataBuffer, NumberOfPixels);
	}
}


void Display_DrawRect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
	uint16_t counter;  //Переменная счетчик для вывода пикселей
	uint16_t dx = x2 - x1;      //Вычисление разницы координат по x
	uint16_t dy = y2 - y1 + 1;  //Вычисление разницы координат по y с дополнительным пикселем на пересечении

	//Рисование горизонтальных граней
	for (uint16_t counter = 0 ; counter < dy; counter++)
	{
		Display_DrawPixel(x1, y1 + counter, color);
		Display_DrawPixel(x2, y1 + counter, color);
	}

	//Рисование вертикальных граней
	for (counter = 0; counter < dx; counter++)
	{
		Display_DrawPixel(x1 + counter, y1, color);
		Display_DrawPixel(x1 + counter, y2, color);
	}
}


void Display_DrawFillPixel(int16_t x, int16_t y, uint16_t size, uint16_t color)
{
	Display_SetWindow(x, y - size, x + size, y);
	
	int n = ((x + size) - x + 1) * ((y + size) - y + 1);

	SendCommand(LCD_GRAM);
	
	for (uint32_t i = 0; i < n; i++)
	{
		DataBuffer[i] = color;
	} 

	SendData(DataBuffer, n);
}


void Display_SetWindow(int16_t x0, int16_t y0, int16_t x1, int16_t y1)
{
	SendCommand(LCD_COLUMN_ADDR);
	
	DataBuffer[0] = (x0 >> 8) & 0xFF;
	DataBuffer[1] = x0 & 0xFF;
	DataBuffer[2] = (x1 >> 8) & 0xFF;
	DataBuffer[3] = x1 & 0xFF;
	SendData(DataBuffer, 4);
	
	SendCommand(LCD_PAGE_ADDR);
	
	DataBuffer[0] = (y0 >> 8) & 0xFF;
	DataBuffer[1] = y0 & 0xFF;
	DataBuffer[2] = (y1 >> 8) & 0xFF;
	DataBuffer[3] = y1 & 0xFF;
	SendData(DataBuffer, 4);
}
