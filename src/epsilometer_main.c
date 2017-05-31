/**************************************************************************//**
 * @file epsilometer_main.c
 * @brief include, definition, call and main loop needed to operate the MADRE
 * @author A. Le Boyer
 * @version 1.0
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silicon Labs Software License Agreement. See 
 * "http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt"  
 * for details. Before using this software for any purpose, you must agree to the 
 * terms of that agreement.
 *
 ******************************************************************************/

/*local library */
#include "ep_common.h"
#include "ep_sampling.h"
#include "ep_menu.h"

// boardSetup is define in common.h . It should contains all the parameters needed to operate the board.
// The default parameter are for 8 channels ,sampling at ~640Hz, 1GHz SPI ADC to MCU, RS232 TX/RX baud rate 460800
epsiSetup boardsetup = EPSI_SETUP_DEFAULT;

// define a pointer to boardSetup
epsiSetupPtr boardSetup_ptr =  &boardsetup;

/******************************************************************************
 * @brief
 *   Main function.
 * @details
 *   Initialization of the board with CHIP_Init, MADRE_Config.
 *   start sampling by triggering an interrupt with MADRE_resume_sampling
 *****************************************************************************/

int main(void) {
    /* Initialize chip - handle erratas */
    CHIP_Init();

	MADRE_Config();

	while (1) {
		send_byte();
		switch (State){
			case Sampling:
				State=poll_RX();
				break;
			case Menu:
				MADRE_menu();
				break;
		}//end switch
	}//end while
}// end main
