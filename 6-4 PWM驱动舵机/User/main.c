#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"

float angle;

int main(void)
{
	OLED_Init();
	Servo_Init();
	Key_Init();
	
	while(1)
	{
		if(Key_GetNum(GPIOB,GPIO_Pin_1) == 1){
			if(angle <180){
				angle +=30;
			}else{
				angle = 0;
			}
			
		}
		Servo_Angle(angle);
	}
}
   

 