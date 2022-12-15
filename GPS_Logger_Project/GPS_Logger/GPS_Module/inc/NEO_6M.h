#pragma once

#include "stm32f4xx_hal.h"
#include "string.h"

void GPS_Module_Init(UART_HandleTypeDef* Selected_UART_Module);
void GPS_Module_StartReceive(void);
