#include "stm32f10x.h"                  // Device header
#include "gpio_drive.h"
#include "usart_drive.h"

char str[] = "Khoat dai ka dep trai" ;
/* 
0- Current count of string
1- USART's Target 
2- Same baud Rate 1:Yes 0:No
3- Recieve signal
4- Teminator char(\0 or \n)
5- Interrupt(1) or Terminator(0) 
6- Timer counter
7- Timer counter copy
*/

unsigned short USART1_manager[] = {0,0,0,0,'\n',0,0,0} ;
char mess_1[250];
unsigned short USART2_manager[] = {0,3,1,0,'\n',0,0,0} ;
char mess_2[250];
unsigned short USART3_manager[] = {0,2,1,0,'\n',0,0,0} ;
char mess_3[250];
int main(void) {
	Init_Delay();
	Init_USART(USART_2, 115200);
	Init_USART(USART_3, 115200);
	while (1) {
 
 }
	
}	

void USART2_IRQHandler() {
	USART_Send(USART_2, USART2_manager, mess_2);
}
void USART3_IRQHandler() {
	USART_Send(USART_3, USART3_manager, mess_3);
}

