#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"

int main(void)
{
	
	LED_Init();
	Key_Init();
	uint8_t KeyNum1;
	uint8_t KeyNum2;
	
	while(1)
	{
		KeyNum1 = Key_GetNum(GPIOB,GPIO_Pin_1);		
		if(KeyNum1 == 1){
			LED_Turn(GPIOA,GPIO_Pin_1);
		}
		
		KeyNum2 = Key_GetNum(GPIOB,GPIO_Pin_11);
		if(KeyNum2 == 1){
			LED_ON(GPIOA,GPIO_Pin_0);
			Delay_ms(200);
		}else{
			LED_OFF(GPIOA,GPIO_Pin_0);
		}
	}
}


 