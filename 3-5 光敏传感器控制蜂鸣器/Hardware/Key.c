#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
}

uint8_t Key_GetNum(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	uint8_t KeyNum = 0;
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 0){
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 0);
		Delay_ms(20);
		KeyNum = 1;
	}
	return KeyNum;
}

uint8_t Key_ON(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	uint8_t KeyNum = 0;
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 0){
		Delay_ms(20);
		if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 0){
			KeyNum = 1;
		}
	}else{
		KeyNum = 0;
	}
	return KeyNum;
}

