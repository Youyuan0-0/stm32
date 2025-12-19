#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"



int main(void)
{
	OLED_Init();
	PWM_Init();
	IC_Init();
	
	PWM_SetPrescaler(720 - 1);					//PWMÆµÂÊFreq = 72M / (PSC + 1) / 100
	PWM_SetCompare1(50);						//PWMÕ¼¿Õ±ÈDuty = CCR / 100
	
	OLED_ShowString(1,1,"Freq:00000Hz");
	while(1)
	{
		OLED_ShowNum(1,6,IC_GetFreq(),5);
	}
}
   

 