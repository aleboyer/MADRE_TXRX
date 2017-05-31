/*
 * proto Epsilometer_coms.c
 *
 *  Created on: May 24, 2016
 *      Author: leumas64
 */

#include "ep_coms.h"
#include "ep_common.h"
#include "em_usart.h"
#include "em_cmu.h"
#include "efm32wg_uart.h"



/******************************************************************************
 * @name UART_Setup
 * @brief
 *  set up the communication with the RS232
 * @details
 *	enable USART1 clock
 *	switch on the TX and RX GPIO
 *	configure USART1: baudrate ....
 *	set up an interrupt to TX the data
 *	lower the priority of the interrupt so it is lower than tha sampling interrupt
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void UART_Setup() {
	/*UART1 shit*/
	CMU_ClockEnable(cmuClock_USART1, true); // Enable clock for USART1 module
	GPIO_PinModeSet(gpioPortD, 7, gpioModePushPull, 1); // TX
	GPIO_PinModeSet(gpioPortD, 6, gpioModeInput, 0); // RX

	USART_InitAsync_TypeDef usartInitUSART1 = {
		.enable = usartDisable, 					// Initially disabled
		.refFreq = 0,								// configured reference frequency
		.baudrate = boardSetup_ptr->usart_baudrate, 				    // Baud rate defined in common.h
		.oversampling = usartOVS16, 				// overSampling rate x16
		.databits = USART_FRAME_DATABITS_EIGHT, 	// 8-bit frames
		.parity = USART_FRAME_PARITY_NONE,			// parity - none
		.stopbits = USART_FRAME_STOPBITS_ONE,		// 1 stop bit
	};

	/*Initialize UART registers*/
	USART_InitAsync(USART1, &usartInitUSART1);

	USART1 -> ROUTE = USART_ROUTE_RXPEN | USART_ROUTE_TXPEN
			| USART_ROUTE_LOCATION_LOC2;

	/* Inform NVIC of IRQ changes*/
//	NVIC_ClearPendingIRQ(USART1_TX_IRQn);
//	NVIC_EnableIRQ(USART1_TX_IRQn);

	// enable the TX and RX transfers
	USART_Enable(USART1, usartEnable);
//	NVIC_SetPriority(USART1_TX_IRQn, 1);
}


/******************************************************************************
 * @name send_byte
 * @brief
 *  send hello world
 * @details
 *
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void send_byte(void)
{
	char str[80];
	sprintf(str, "Hello World \n");
    //uint8_t A[12];

    GPIO_PinModeSet(gpioPortA, 14, gpioModePushPull, 1); //
	for (int i=0;i<13;i++){
		USART_Tx(USART1, str[i]);
	}
	GPIO_PinModeSet(gpioPortA, 14, gpioModePushPull, 0);


//    for(int i=0;i<12;i++){
//		/* Transmit pending character */
//		USART_Tx(USART1, A[i]);
//	}

}






