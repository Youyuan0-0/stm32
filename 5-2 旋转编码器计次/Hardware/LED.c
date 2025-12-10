#include "stm32f10x.h"                  // Device header

void LED_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_ResetBits(GPIOA, GPIO_Pin_All);
}

void LED_ON(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	GPIO_SetBits(GPIOx, GPIO_Pin);
}

void LED_OFF(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	GPIO_ResetBits(GPIOx, GPIO_Pin);
}

void LED_Turn(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	if(GPIO_ReadOutputDataBit(GPIOx, GPIO_Pin) == 1){
		GPIO_ResetBits(GPIOx, GPIO_Pin);
	}else{
		GPIO_SetBits(GPIOx, GPIO_Pin);
	}
}

