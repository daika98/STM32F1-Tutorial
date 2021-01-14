#include "stm32f10x.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include "RTE_Device.h"                 // Keil::Device:Startup
#include "drive.h"
#include "string.h"

int main(void) {
	char str[] = "Khoat Dai ka dep trai";
	char a ;
	unsigned int  i = 0;
  Init_Delay();
	
	RCC->APB2ENR |= 1;                         //Enable AFIO
  RCC->APB1ENR |= (1<<17);                   //Enable USART_2
  Init_GPIO (Port_A, 2, OUT_50, OUT_AF_PP);  //Initilize for port A pin 2 is output push-pull
  Init_GPIO (Port_A, 3, IN, IN_PP);          // Initilize for port A pin 3 is input push-pull
	USART2->BRR = 0xEA6;                       // Setup Baud rate 9600
	USART2->CR1 |= (1<<13) | (1<<2) | (1<<3);  // Enable USART, USART Transmit and USART Receive
	
while (1) {

	a = str[i++];
	if (a == NULL) {
			i = 0;
		a = ' ';
		delay_ms(1000);
		}
// while (!(USART2->SR & (1<<5))) {} // Waiting for state of bit RXNE up to 1 - Data is recieved _ Recived data is ready to be read
//  a = USART2->DR; 		
	while(!(USART2->SR & (1<<7))) {} // Waitting for state of bit TXE up to 1 - Data is transferred
	USART2->DR = a;
delay_ms(100);		
}
}
