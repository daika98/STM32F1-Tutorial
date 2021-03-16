#include "stm32f10x.h"                  // Device header
#include "RTE_Components.h"             // Component selection
#include "RTE_Device.h"                 // Keil::Device:Startup
#include "gpio_drive.h"
#include "spi_drive.h"


int main(void) {
	Init_Delay();
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	Init_GPIO(Port_C, 13, OUT_50, OUT_GP_PP);
	Write_GPIO(Port_C,13,0);
	Init_SPI(SPI_1);
	
	while (1) {

		delay_ms(50);
		SPI_Transfer_Data(SPI_1,"Khoat");
		
	}
}

