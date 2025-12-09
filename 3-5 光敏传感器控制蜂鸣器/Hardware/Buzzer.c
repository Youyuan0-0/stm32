#include "stm32f10x.h"                  // Device header

void Buzzer_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
}

void Buzzer_ON(uint16_t GPIO_Pin){
	GPIO_ResetBits(GPIOB, GPIO_Pin);
}

void Buzzer_OFF(uint16_t GPIO_Pin){
	GPIO_SetBits(GPIOB, GPIO_Pin);
}
