/*
 * epsilometer_init_gpio.c
 *
 *  Created on: Jan 13, 2017
 *      Author: aleboyer
 */


#include "ep_GPIO_init.h"

/******************************************************************************
 * @name init_GPIO
 * @brief
 *   Switch on some GPIO
 * @details
 * Switch on the parts of MADRE, mainly the ADC
 *
 * @Author A. Le Boyer
 *****************************************************************************/

void init_GPIO(void) {
	GPIO_PinModeSet(gpioPortE, 13, gpioModePushPull, 1); // Enable Analog power
	GPIO_PinModeSet(gpioPortF, 3, gpioModePushPull, 1); // Enable 485 Driver
	GPIO_PinModeSet(gpioPortF, 4, gpioModePushPull, 0); // Enable 485 Receiver power
	GPIO_PinModeSet(gpioPortF, 5, gpioModePushPull, 1); // Enable 485 Transmitter
}
