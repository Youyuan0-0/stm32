#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "CountSensor.h"

int main(void)
{
	OLED_Init();
	CountSensor_Init();
	OLED_ShowNum(2,1,112,3);
	while(1)
	{

		OLED_ShowNum(1,1,CountSensor_get(),3);
		
	}
}
   

 