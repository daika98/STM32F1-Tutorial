#include "stm32f10x.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include "RTE_Device.h"                 // Keil::Device:Startup


void delay ( unsigned int time);

int  main(void) {
	RCC->APB2ENR |=  RCC_APB2ENR_IOPAEN;  //Enable GPIO port A
	GPIOA->CRL &= 0xfffffff0;   //Reset value of pin 0 of port A
	GPIOA->CRL |= 0x00000008;   //Set pin 0 of port A value 1000-Mode Input with pull up/pull down
	RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN;//0x00000010- Enable GPIO port C
	GPIOC->CRH &= 0xFF0FFFFF; // Reset pin 13
	GPIOC->CRH |= 0x00300000; //Write pin 13 values 0011//11 is mode OUTPUT max speed 50 MHz ; 00 is mode General purpose push pull -> LED turn on
	
	while (1) {
		if (GPIOA->IDR & 0x00000001) {// if value in the pin A0 = 1
		delay(50);
			GPIOC->ODR ^= 0x2000; // Toggle pin C13 - Blink led
			delay(50);	
		}
		else {
			GPIOC->ODR |= 0x0000;   //Reset pin C13 value 0 - Turn on led 
		}
	}
}

void delay ( unsigned int time){
     	while (time--) {
			volatile unsigned int i; //NEED use volatile
			for (i = 0; i < 10000; i++)
			{}
			}
}

