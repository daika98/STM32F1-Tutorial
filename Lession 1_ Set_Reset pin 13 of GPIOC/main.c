#include "stm32f10x.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include "RTE_Device.h"                 // Keil::Device:Startup

/*
void delay ( unsigned int time);

int  main(void) {
	RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN  ;//0x00000010- Enable GPIO port C
	GPIOC->CRH &= 0xFF0FFFFF; // Reset pin 13
	GPIOC->CRH |= 0x00300000; //Write pin 13 values 0011//11 is mode OUTPUT max speed 50 MHz ; 00 is mode General purpose push pull -> LED turn on
	//GPIOC->ODR |= 0x2000;     // Set pin 13 value 1 LED will turn off
	while (1) {
	GPIOC->ODR |= 0x2000; //In the loop set pin 13 value 1 - USE Output data register
 // GPIOC->BSRR |= 0x2000;	//In the loop set pin 13 value 1 - USE Bit set/reset register
		delay(200);
//  	GPIOC->BRR  |= 0x2000; //In the loop reset pin 13 value 0 - USE Bit reset register
//	 GPIOC->BSRR |= 0x20000000;	//In the loop reset pin 13 value 0 - USE Bit set/reset register
 		 GPIOC->ODR &= ~GPIOC->ODR; //In the loop reset pin 13 value 0 - USE Output data register
		delay(200);
	}
}

void delay ( unsigned int time){
     	while (time--) {
			volatile unsigned int i; //NEED use volatile
			for (i = 0; i < 10000; i++)
			{}
			}
}

*/
#include "stm32f10x.h"                  // Device header
//PC13
//APB2
//RCC->APB2ENR
//GPIOx_CRH
//GPIOx_ODR

void delayMs(int delay);
int main(void)
{
	RCC->APB2ENR |=0x10;   //Enable to port C
		GPIOC->CRH &= 0xFF0FFFFF; // Reset pin 13
	GPIOC->CRH |= 0x00300000; //Write pin 13 values 0011//11 is mode OUTPUT max speed 50 MHz ; 00 is mode General purpose push pull -> 
//	GPIOC->CRH |=0x400000; //PC13 muc MODE 11
	while(1)
	{
		GPIOC->ODR =0x2000;
		delayMs(1000);
		GPIOC->ODR &=~0x2000;
		delayMs(1000);
	}
}

void delayMs(int delay)
{
	int i;
	for(;delay>0;delay--)
	{
		for(i=0;i<3195;i++);
	}
}
