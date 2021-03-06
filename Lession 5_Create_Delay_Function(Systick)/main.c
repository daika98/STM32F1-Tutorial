#include "stm32f10x.h"                  // Device header
#include "gpio_drive.h"

void delay_us (void);
void delay_ms (unsigned int time);

int  main(void) {
	Init_GPIO(Port_C, 13, OUT_50, OUT_GP_PP);
//	Init_AFIO_Port_A();
	Init_Delay();

	while (1) {
		delay_ms(1000);
			Toggle_Pin(Port_C, 13); // Toggle pin C13 - Blink led
	}
}

void delay_us (){
   SysTick->LOAD |= 72000 - 1;
	 SysTick->VAL |= 0;
	while ((SysTick->CTRL & 0x00010000) == 0) {}
}

void delay_ms(volatile unsigned int time){
	while (time--){
			delay_us(); 
}
}

void EXTI0_IRQHandler(){
	EXTI->PR |= 1;//Clear state of pin
	while (1) {
			//	delay_ms(1000);
			Toggle_Pin(Port_C, 13); // Toggle pin C13 - Blink led
			delay_ms(1000);				
	}
	
}



