#include "stm32f10x.h"                  // Device header
#include "gpio_drive.h"

volatile unsigned int signal;

void delay (unsigned int time);

int  main(void) {
	Init_GPIO(Port_A, 0, IN, IN_PP);
	Init_GPIO(Port_C, 13, OUT_50, OUT_GP_PP);
	Init_GPIO(Port_A, 12, OUT_50, OUT_GP_PP);
	
	__disable_irq();
	AFIO->EXTICR[0] = 0x00;
	EXTI->PR |= 1;
	EXTI->IMR |= 1;
	EXTI->RTSR |= 1;
	NVIC_EnableIRQ(EXTI0_IRQn);
	__enable_irq();
	
	while (1) {
		Write_GPIO(Port_A, 12, signal);
		if (signal) {
			Toggle_Pin(Port_C, 13); // Toggle pin C13 - Blink led
			delay(50);				
		}
		else {
			Write_GPIO(Port_C, 13, 0);   //Write pin C13 value 0 - Turn on led 
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

void EXTI0_IRQHandler(){
	EXTI->PR |= 1;
	if (signal == 1) {
		signal = 0;
	} else { 
		signal = 1;
	}
}
