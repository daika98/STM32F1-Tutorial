#include "stm32f10x.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include "RTE_Device.h"                 // Keil::Device:Startup
#include "gpio_drive.h"

void delay ( unsigned int time);

int  main(void) {
	Init_GPIO(Port_A, 0, IN, IN_PP);
	Init_GPIO(Port_C, 13, OUT_50, OUT_GP_PP);
	while (1) {
		if (Read_GPIO(Port_A, 0) == 1) {
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

