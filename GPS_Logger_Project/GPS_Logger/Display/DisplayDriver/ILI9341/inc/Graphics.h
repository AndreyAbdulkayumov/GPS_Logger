#pragma once

#include "stdio.h"
#include "Colors.h"

typedef enum
{
	Portrait,
	Landscape
} DisplayOrientation;

void Display_SetOrientation(DisplayOrientation Orientation);

void Display_FillScreen(uint16_t color);

void Display_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void Display_DrawLine_Vertical(uint16_t x0, uint16_t y0, uint16_t Length, uint16_t Color);
void Display_DrawLine_Horizontal(uint16_t x0, uint16_t y0, uint16_t Length, uint16_t Color);

void Display_DrawFillRect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void Display_DrawFillPixel(int16_t x, int16_t y, uint16_t size, uint16_t color);

void Display_SetCursorPosition(uint16_t x, uint16_t y);
void Display_SetWindow(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
