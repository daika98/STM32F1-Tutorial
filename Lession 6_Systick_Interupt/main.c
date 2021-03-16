#include "stm32f10x.h"                  // Device header
#include "gpio_drive.h"

void delay_us (void);
void delay_ms (volatile unsigned int time);

int  main(void) {
	  Init_GPIO(Port_C, 13, OUT_50, OUT_GP_PP);
	  
		Write_GPIO(Port_C,13,0);
   Init_Systick_Interrupt();
	
	while (1) {

}
	}


void SysTick_Handler(void) {

		Toggle_Pin(Port_C,13);
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
