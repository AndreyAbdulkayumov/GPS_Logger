#pragma once

#include <math.h>
#include "Font.h"
#include "Graphics.h"

void Display_Write_Char(uint16_t x, uint16_t y, char symbol,
		uint16_t back_color, uint16_t char_color, uint16_t size);

void Display_Write_String(uint16_t x, uint16_t y, char *str,
		uint16_t back_color, uint16_t char_color, uint16_t size);

void Display_Write_Number(uint16_t x, uint16_t y, int num,
		uint16_t back_color, uint16_t char_color, uint16_t size);

void Display_Write_Time(uint16_t x, uint16_t y, uint32_t sec,
		uint16_t back_color, uint16_t char_color, uint16_t size);
