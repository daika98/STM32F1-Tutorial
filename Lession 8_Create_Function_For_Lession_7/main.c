#include "stm32f10x.h"                  // Device header
#include "gpio_drive.h"
#include "usart_drive.h"
#include "string.h"

int main(void) {
	char str[] = "Khoat Dai ka dep trai";
	char a ;
	unsigned int  i = 0;
  Init_Delay();
	Init_USART(USART_3, 9600);

while (1) {

	a = str[i++];
	if (a == NULL) {
			i = 0;
		a = ' ';
		delay_ms(1000);
		}
// while (!(USART2->SR & (1<<5))) {} // Waiting for state of bit RXNE up to 1 - Data is recieved _ Recived data is ready to be read
//  a = USART2->DR; 		
	while(!(USART3->SR & (1<<7))) {} // Waitting for state of bit TXE up to 1 - Data is transferred
	USART3->DR = a;
delay_ms(100);		
}
}
