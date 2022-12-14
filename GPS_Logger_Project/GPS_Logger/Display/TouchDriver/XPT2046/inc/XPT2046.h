#include "stm32f4xx_hal.h"

#define	Y 	0x90
#define	X 	0xD0

typedef struct touch_point
{
	uint16_t Point_X;
	uint16_t Point_Y;
} TouchPoint;

void TouchDriver_Init(
		SPI_HandleTypeDef* SPI_Module,
		GPIO_TypeDef* Selected_CS_GPIO,
		uint16_t Selected_CS_Pin);

uint16_t TouchDriver_GetTouch_Axis(uint8_t AxisValue);
TouchPoint TouchDriver_Get_TouchPoint(void);

