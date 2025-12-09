#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_All;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//GPIO_SetBits(GPIOA, GPIO_Pin_0);
	//GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	//GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
	
	
	while(1)
	{
		GPIO_Write(GPIOA, 0x0001); //0000 0000 0000 0001 ~按位取反
		Delay_ms(100);
		GPIO_Write(GPIOA, 0x0002); //0000 0000 0000 0010 
		Delay_ms(100);
		GPIO_Write(GPIOA, 0x0004); //0000 0000 0000 0100 
		Delay_ms(100);
		GPIO_Write(GPIOA, 0x0008); //0000 0000 0000 1000 
		Delay_ms(100);
		GPIO_Write(GPIOA, 0x0010); //0000 0000 0001 0000 
		Delay_ms(100);
		GPIO_Write(GPIOA, 0x0020); //0000 0000 0010 0000 
		Delay_ms(100);
		GPIO_Write(GPIOA, 0x0040); //0000 0000 0100 0000 
		Delay_ms(100);
		
	}
}
