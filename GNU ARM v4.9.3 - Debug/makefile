################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/EFM32WG/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: MADRE_TXRX.axf

# Tool invocations
MADRE_TXRX.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "MADRE_TXRX.ld" -Xlinker --gc-sections -Xlinker -Map="MADRE_TXRX.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o MADRE_TXRX.axf "./CMSIS/EFM32WG/startup_efm32wg.o" "./CMSIS/EFM32WG/system_efm32wg.o" "./emlib/em_adc.o" "./emlib/em_cmu.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_int.o" "./emlib/em_rtc.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./emlib/em_usart.o" "./src/epilometer_sampling.o" "./src/epsilometer_CMU_init.o" "./src/epsilometer_GPIO_init.o" "./src/epsilometer_coms.o" "./src/epsilometer_main.o" "./src/epsilometer_menu.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: MADRE_TXRX.hex'
	arm-none-eabi-objcopy -O ihex "MADRE_TXRX.axf" "MADRE_TXRX.hex"
	@echo ' '

	@echo 'Building bin file: MADRE_TXRX.bin'
	arm-none-eabi-objcopy -O binary "MADRE_TXRX.axf" "MADRE_TXRX.bin"
	@echo ' '

	@echo 'Building s37 file: MADRE_TXRX.s37'
	arm-none-eabi-objcopy -O srec "MADRE_TXRX.axf" "MADRE_TXRX.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "MADRE_TXRX.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) MADRE_TXRX.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
