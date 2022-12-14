#include "Text.h"

void Display_Write_Char(uint16_t x, uint16_t y, char symbol, uint16_t back_color, uint16_t char_color, uint16_t size) {

	int buffer;  //Переменная для хранения значения выводимого пикселя
	int counter = 0;  //Переменная счетчик для прорисовки строк
	uint8_t itog_symbol = symbol - 32;  //Номер символа в таблице ASCII

	//Вывод пикселей по x в сторону уменьшения
	for(int8_t i = 7; i >= 0; i--)
	{
		//Вывод пикселей по y в сторону уменьшения
		for(int8_t j = 0; j < 8; j++)
		{
			//Заносим значение пикселя выбранного символа из массива font
			buffer = font[itog_symbol][i] & (128 >> j);

			//Закрашивание пикселя нужным цветом

			//Если пиксель равен 1
			if (buffer != 0)
			{
				Display_DrawFillPixel(
						x + (counter) * size,
						y - j * size,
						size,
						char_color);
			}

			//Если пиксель равен 0
			else
			{
				Display_DrawFillPixel(
						x + (counter) * size,
						y - j * size,
						size,
						back_color);
			}
		}

		counter++;
	}
}

void Display_Write_String(uint16_t x, uint16_t y, char *str, uint16_t back_color, uint16_t char_color, uint16_t size) {

    uint16_t next = 0; //Переменная счетчик для вывода следующего сивмола на НОВОМ знакоместе

	while(*str)
	{
		//Вывод каждого символа строчки по отдельности
		Display_Write_Char(
				x + size * next * 8,
				y,
				*str++,
				back_color,
				char_color,
				size
				);
        next++;
    }
}

void Display_Write_Number(uint16_t x, uint16_t y, int number, uint16_t back_color, uint16_t char_color, uint16_t size) {

	uint8_t NumberOfDigits = 0;
	int NumberForCountDigits = number;
	
	//Счет количества разрядов
	while(NumberForCountDigits != 0)
	{
		NumberForCountDigits /= 10;
		NumberOfDigits++;
	}
	
	for(uint8_t i = 0; i < NumberOfDigits; i++)
	{
		Display_Write_Char(x,y-size*8*(i-1),
		        ((number % (int)pow(10, NumberOfDigits - i)) / pow(10, NumberOfDigits - i - 1)) + 48,
				back_color,
				char_color,
				size);
	}
	
}


void Display_Write_Time(uint16_t x, uint16_t y, uint32_t sec, uint16_t back_color, uint16_t char_color, uint16_t size) {

	uint8_t ed_sec, dec_sec, ed_min, dec_min, ed_hour, dec_hour;  //Вспомогательные переменные для хранения разрядов
  
	uint32_t min = sec / 60;
	uint32_t hours = min / 60;
	
	if (hours != 0) {
		min = sec / 60 - hours * 60;
	}
	
	sec -= min*60;
	
	//Разбитие числа на разряды
	ed_sec = (sec % 10) + 48;
	dec_sec = ((sec % 100) / 10) + 48;
	
	ed_min = (min % 10) + 48;
	dec_min = ((min % 100) / 10) + 48;
	
	ed_hour = (hours % 10) + 48;
	dec_hour = ((hours % 100) / 10) + 48;
	
	//Вывод часов
	if (hours<10)
	{
		Display_Write_Char(x, y - size * 8, '0', back_color, char_color, size);
		Display_Write_Char(x, y - size * 16, ed_hour, back_color, char_color, size);
	}

	else if (hours >= 10)
	{
		Display_Write_Char(x, y - size * 8, dec_hour, back_color, char_color, size);
		Display_Write_Char(x, y - size * 16, ed_hour, back_color, char_color, size);
	}
	
	Display_Write_Char(x, y - size * 24, ':', back_color, char_color, size);
	
	//Вывод минут
	if (min < 10)
	{
		Display_Write_Char(x, y - size * 32, '0', back_color, char_color, size);
		Display_Write_Char(x, y - size * 40, ed_min, back_color, char_color, size);
	}

	else if (min >= 10)
	{
		Display_Write_Char(x, y - size * 32, dec_min, back_color, char_color, size);
		Display_Write_Char(x, y - size * 40, ed_min, back_color, char_color, size);
	}
	
	Display_Write_Char(x, y - size * 48, ':', back_color, char_color, size);
	
	//Вывод секунд
	if (sec<10)
	{
		Display_Write_Char(x, y - size * 56, '0', back_color, char_color, size);
		Display_Write_Char(x, y - size * 64, ed_sec, back_color, char_color, size);
	}

	else if (sec >= 10)
	{
		Display_Write_Char(x, y - size * 56, dec_sec, back_color, char_color, size);
		Display_Write_Char(x, y - size * 64, ed_sec, back_color, char_color, size);
	}
}

