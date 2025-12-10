#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"

int main(void)
{
	OLED_Init();
	Encoder_Init();
	OLED_ShowNum(2,1,112,3);
	while(1)
	{
		OLED_ShowSignedNum(1,1,Encoder_Get(),3);
	}
}
   

 