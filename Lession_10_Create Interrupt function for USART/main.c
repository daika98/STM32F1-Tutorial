#include "stm32f10x.h"                  // Device header
#include "gpio_drive.h"
#include "usart_drive.h"
char str[] = "Follow my channel please!";
char mess2[250];
unsigned short USART2_counter = 0;
unsigned short USART2_recieved_signal = 0 ;
char mess3[250];
unsigned short USART3_counter = 0;
unsigned short USART3_recieved_signal = 0 ;

int main(void) {
	Init_Delay();
	Init_USART(USART_2, 115200);
	Init_USART(USART_3, 115200);
  delay_ms(100);
	 USART_TX_STR(2,str);	
   USART_TX_STR(3,str);	

	while (1) {
	if (USART2_recieved_signal == 1) {
		 USART_TX_STR(USART_3, mess2);
     USART2_recieved_signal = 0;		
		Clear_str(mess2);
	}
	if (USART3_recieved_signal == 1) {
	 USART_TX_STR(USART_2, mess3);	
	 USART3_recieved_signal = 0;
	 Clear_str(mess3);
	}
 }
}


void USART2_IRQHandler(){
	USART_Send(USART_2, 3, 0, &USART2_recieved_signal, mess2, &USART2_counter);
}

void USART3_IRQHandler(){
  USART_Send(USART_3, USART_2, 0, &USART3_recieved_signal, mess3, &USART3_counter);
}
