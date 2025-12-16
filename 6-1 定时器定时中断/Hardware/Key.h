#ifndef __KEY_H_
#define __KEY_H_

void Key_Init(void);
uint8_t Key_GetNum(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint8_t Key_ON(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif
