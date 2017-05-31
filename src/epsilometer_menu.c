/*
 * epsilometer_menu.c
 *
 *  Created on: Apr 24, 2017
 *      Author: aleboyer
 */

#include "ep_menu.h"
/******************************************************************************
 * @name MADRE_menu
 * @brief
 *   interaction with the user. User can my python script.
 * @details
 *	define a character chain giving the user options.
 *	If user send 1 sent the user into the change config mode
 *	If user send 2 resume sampling with the new configuration if any
 *
 * @Author A. Le Boyer
 *****************************************************************************/


void MADRE_menu(void){
    // define a sentence to send to the user
	char buf[100];
	uint8_t  rxData16  = 0;
	sprintf(buf,"ACTIONS: \n 1- CHANGE CONFIG \n 2- RESUME SAMPLING\n");

	// USART_RxDouble have while loop which will hold on until a bytes is going to come.
	// giving us the time to clean serial buffer in python. This is not very elegant
	// but I already spend almost a whole day to figure out something "smart"

	// menu selection
	while((rxData16==0) | (rxData16>2)){
		// send the user action option through TX.
		for(int i=0;i<49;i++){
			USART_TxDouble(USART1,buf[i]);
		}
		rxData16 = USART_Rx(USART1);
		if(rxData16==1) {
			break;
		}
	}
	// allow user to change the config
	if (rxData16==1){
			GPIO_PinModeSet(gpioPortA, 13, gpioModePushPull, 1); //
			GPIO_PinModeSet(gpioPortA, 13, gpioModePushPull, 0);
	}
}


/******************************************************************************
 * @name MADRE_Config
 * @brief
 *   Configure and switch on the needed part on MADRE
 * @details
 *   init the clock management
 *   init the GPIO port (switch the ADC)
 *   set up UART the communication port between the ADC and the MCU
 *   set up the GPIO interrupt controled by the ADC
 *   configure the ADC
 *   set the main buffer size
 *   initialize the TIMERS
 *   initialize the RS232 UART
 *   initialize the SD card
 *   open a file on the SD card to start the sampling
 *
 * @Author A. Le Boyer
 *****************************************************************************/
void MADRE_Config(void) {
	/* Use 20 MHZ HFRCO as core clock frequency*/
    /* use of an interrupt on CMU to trigger the Oscillator when ready */
    init_CMU();
	// define GPIO pin mode for ADC and the 485, PA2 to send MCLOCK (for ADCs), and PE7 to send SYNC
    init_GPIO();
    UART_Setup();
}


