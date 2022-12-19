#pragma once

#include <stm32f4xx.h>
#include "ILI9341_commands.h"

//Выбор FSMC
#define BASE_COM    0x60000000
#define BASE_DATA   0x60080000

#define FCMS_Send_COM(com)      *(uint16_t*)BASE_COM = com
#define FCMS_Send_DATA(data)    *(uint16_t*)BASE_DATA = data

#define Backlights_On     GPIOB->BSRR = GPIO_BSRR_BS1
#define Backlights_Off    GPIOB->BSRR = GPIO_BSRR_BR1

extern uint16_t DataBuffer[];

void SendCommand(uint16_t Command);
void SendData(uint16_t* Data, uint16_t DataSize);
