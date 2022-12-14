#pragma once

#include <stm32f4xx.h>
#include "Graphics.h"
#include "Text.h"

void DisplayDriver_Init(DisplayOrientation Orientation);  //Функция инициализации дисплея

void Display_Backlight_On(GPIO_TypeDef* Backlight_GPIO, uint16_t Backlight_Pin);
void Display_Backlight_Off(GPIO_TypeDef* Backlight_GPIO, uint16_t Backlight_Pin);
