#include "gpio_drive.h"

void Init_GPIO (unsigned short port, unsigned short pin, unsigned short dir, unsigned short opt){
	volatile unsigned long *CR = 0;
	unsigned short new_pin, offset = 0x00;
	new_pin = pin;
	if (pin > 7) { //(if pin = 8..15. This is CRH)
		new_pin -= 8;
		offset  = 0x01;
	}
	if (port == 1) {
		RCC_APB2ENR |=  4;  //Enable GPIO port A
		CR = (volatile unsigned long*)(&GPIO_A + offset);
	}
  if (port == 3) {
		RCC_APB2ENR |=  0x10;  //Enable GPIO port C
		CR = (volatile unsigned long*)(&GPIO_C + offset);
	}
	*CR &= (unsigned long)~(0xf << (4*new_pin));//Reset the target pin
	*CR |= (unsigned long)((dir << (4*new_pin)) | (opt <<(4*new_pin + 2)));// Set value on the target pin
}
	
int  Read_GPIO (unsigned short port, unsigned short pin){
	 volatile unsigned long *IDR = 0;
	 int state;
	 unsigned long offset = 0x02;
	
	 if (port == Port_A) {
		 IDR = (volatile unsigned long*)(&GPIO_A + offset);
	 }
	 else if (port == Port_C) {
		 IDR = (volatile unsigned long*)(&GPIO_C + offset);
	 }
	 state = (int)((*IDR & (1 << pin)) >> pin);// Read state of pin on the varriable state 
	 return state;
	 
}


void Write_GPIO (unsigned short port, unsigned short pin, unsigned short state) {
	volatile unsigned long *ODR = 0;
	 unsigned long offset = 0x03;
	
	 if (port == Port_A) {
		 ODR = (volatile unsigned long*)(&GPIO_A + offset);
	 }
	 else if (port == Port_C) {
		 ODR = (volatile unsigned long*)(&GPIO_C + offset);
	 }
	 state ? (*ODR |= (1 << pin)) : (*ODR &= ~(1 << pin));// if varriable state = 1 we write value 1 on the target pin or if varriable state = 0 we write value 0 on the target
}

void Toggle_Pin (unsigned short port, unsigned short pin) {
   if (Read_GPIO (port,pin) == 1) {
		 Write_GPIO(port, pin, 0);//If state of pin is 1 we rewrite value 0 on the pin 
	 }
	 else {
		 Write_GPIO(port, pin, 1);//If state of pin is 0 we rewrite value 1 on the pin 
	 }
}
