#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void LightSensor_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	
	GPIO_Init(GPIOB, &GPIO_InitStruct);
}

uint8_t LightSensor_GetNum(uint16_t GPIO_Pin){
	uint8_t LightSensorNum = 0;
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin) == 0){
		LightSensorNum = 1;
	}
	return LightSensorNum;
}
