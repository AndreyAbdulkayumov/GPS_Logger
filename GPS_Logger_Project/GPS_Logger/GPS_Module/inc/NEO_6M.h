#pragma once

#include "stm32f4xx_hal.h"
#include "string.h"
#include "Logging.h"

void GPS_Module_Init(
		UART_HandleTypeDef* Selected_UART_Module,
		Logging_Status (*CallbackAction) (char* String, uint32_t StringSize)
		);
void GPS_Module_StartReceive(void);
void GPS_Module_StopReceive(void);
