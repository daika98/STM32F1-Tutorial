#include "stm32f10x.h"                  // Device header
#include "gpio_drive.h"
#include "usart_drive.h"
#include "string.h"

int main (void) {
	char c = 'C';
	Init_Delay();
	Init_USART(USART_3,9600);
	

	while(1) {
	//c =	USART_RX(2);
		USART_TX(USART_3,c);
		delay_ms(100);
	}
	
}

