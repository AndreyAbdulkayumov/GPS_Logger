#include "XPT2046.h"

SPI_HandleTypeDef* SPI_Module = NULL;
GPIO_TypeDef* CS_GPIO = NULL;
uint16_t CS_Pin = 0;

void CS_Active()
{
	CS_GPIO->BSRR = CS_Pin << 16;
}

void CS_Deactive()
{
	CS_GPIO->BSRR = CS_Pin;
}

void TouchDriver_Init(
		SPI_HandleTypeDef* Module,
		GPIO_TypeDef* Selected_CS_GPIO,
		uint16_t Selected_CS_Pin
		)
{
	SPI_Module = Module;

	CS_GPIO = Selected_CS_GPIO;
	CS_Pin = Selected_CS_Pin;

	uint8_t RX[5] = { 0, 0, 0 };

	CS_Active();
	HAL_SPI_TransmitReceive(SPI_Module, (uint8_t *)0x80, RX, 3, HAL_MAX_DELAY);
	CS_Deactive();
}

uint16_t TouchDriver_GetTouch_Axis(uint8_t AxisValue)
{
	uint8_t RX[5] = { 0, 0, 0 };

	uint8_t SelectedAxis = AxisValue;

	CS_Active();
	HAL_SPI_TransmitReceive(SPI_Module, &SelectedAxis, RX, 3, HAL_MAX_DELAY);
	CS_Deactive();

	uint16_t Result = ((RX[1] << 8) | RX[2]) >> 3;

	return Result;
}

TouchPoint TouchDriver_Get_TouchPoint(void)
{

}
