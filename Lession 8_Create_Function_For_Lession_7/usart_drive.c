#include "stm32f10x.h"                  // Device header
#include "gpio_drive.h"
#include "usart_drive.h"
unsigned long Find_BaudRate(unsigned char usart, unsigned long baud_Rate);
//unsigned long USART_BRR(unsigned short usart, unsigned long BR);

void Init_USART(unsigned char usart, unsigned long baud_Rate){
	unsigned long val;
	val = Find_BaudRate(usart, baud_Rate);
	if (usart == USART_1){
		RCC->APB2ENR |= 1;                         //Enable AFIO
		RCC->APB2ENR |= (1<<14);                   //Enable USART_1
		Init_GPIO (Port_A, 9, OUT_50, OUT_AF_PP);  //Initilize for port A pin 9 is output push-pull for TX
		Init_GPIO (Port_A, 10, IN, IN_PP);          // Initilize for port A pin 10 is input push-pull for RX
		USART1->BRR = val;                       // Setup Baud rate
		USART1->CR1 |= (1<<13) | (1<<2) | (1<<3);  // Enable USART, USART Transmit and USART Receive
	
	}
	else if (usart == USART_2) {
		RCC->APB2ENR |= 1;                         //Enable AFIO
		RCC->APB1ENR |= (1<<17);                   //Enable USART_2
		Init_GPIO (Port_A, 2, OUT_50, OUT_AF_PP);  //Initilize for port A pin 2 is output push-pull for TX
		Init_GPIO (Port_A, 3, IN, IN_PP);          // Initilize for port A pin 3 is input push-pull for RX
		USART2->BRR = val;                       // Setup Baud rate
		USART2->CR1 |= (1<<13) | (1<<2) | (1<<3);  // Enable USART, USART Transmit and USART Receive
	
	}
	else if (usart == USART_3) {
		RCC->APB2ENR |= 1;                         //Enable AFIO
		RCC->APB1ENR |= (1<<18);                   //Enable USART_3
		Init_GPIO (Port_B, 10, OUT_50, OUT_AF_PP);  //Initilize for port B pin 10 is output push-pull for TX
		Init_GPIO (Port_B, 11, IN, IN_PP);          // Initilize for port B pin 11 is input push-pull for RX
		USART3->BRR = val;                       // Setup Baud rate
		USART3->CR1 |= (1<<13) | (1<<2) | (1<<3);  // Enable USART, USART Transmit and USART Receive
	
	}
}

unsigned long Find_BaudRate(unsigned char usart, unsigned long baud_Rate) {
	unsigned long frequency;
	double frequency_double;
	unsigned int div;
	unsigned int frac;
	double frac_1;
	double div_double;
	double sub;
	unsigned long final;
	
	frequency = 36000000;
	frequency_double = 36000000.00;
	if (usart == USART_1) {
		frequency = 72000000;
		frequency_double = 72000000.00;
	}
	div = frequency / (16 * baud_Rate);
	div_double = frequency_double / (16 * baud_Rate);
	frac = (unsigned int)((div_double - div) * 16);
	frac_1 = (div_double - div) * 16;
  sub = frac_1 - frac;
	if (sub >= 0.5) {
		frac = frac + 1;
		   if (frac == 16){
				 div++;
			 }
	}
	
	final = div<<4;
	final += frac;
	return final;
}

//unsigned long USART_BRR(unsigned short usart, unsigned long BR)
//{
//	unsigned long div = 36000000UL;
//	unsigned long dec;
//	unsigned long final;
//	double frac = 36000000.00;
//	double frac2 = 1.00;
//	
//	if(usart == 1)
//	{
//	div = 72000000UL;
//	frac = 72000000.00;
//	}
//	div = div / (BR*16);
//	frac = 16*((frac / (BR*16))-div);
//	dec = frac;
//	frac2 = 100*(frac-dec);
//	if(frac2>50)
//	{
//		dec ++;
//		if(dec == 16)
//		{
//			dec = 0;
//			div ++;
//		}
//	}
//	
//	final = (div<<4);
//	final += dec;
//	
//	return final;
//}
