/*
 * epilometer_sampling.c
 *
 *  Created on: Apr 24, 2017
 *      Author: aleboyer
 */


#include "ep_sampling.h"



/******************************************************************************
 * @name poll_RX
 * @brief
 *   check if a user is trying to talk to the board
 * @details
 *	read the RX buffer
 *
 * @Author A. Le Boyer
 *****************************************************************************/

enum States0 poll_RX(){


	// quick check if the RX buffer empty
	uint16_t rxData = 0;
	if((USART1->STATUS & USART_STATUS_RXDATAV)){
		rxData = USART_RxDouble(USART1);
		USART1->CMD =(USART1->CMD & ~_USART_CMD_CLEARRX_MASK)|USART_CMD_CLEARRX;

		if (rxData==0x1e1e){
		    GPIO_PinModeSet(gpioPortA, 13, gpioModePushPull, 1); //
		    State=Menu;
		    GPIO_PinModeSet(gpioPortA, 13, gpioModePushPull, 0);
	    }
	}

	return State;

}
