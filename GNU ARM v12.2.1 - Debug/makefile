################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include scr/subdir.mk
-include gecko_sdk_4.4.5/platform/service/system/src/subdir.mk
-include gecko_sdk_4.4.5/platform/service/sleeptimer/src/subdir.mk
-include gecko_sdk_4.4.5/platform/service/device_init/src/subdir.mk
-include gecko_sdk_4.4.5/platform/emlib/src/subdir.mk
-include gecko_sdk_4.4.5/platform/driver/leddrv/src/subdir.mk
-include gecko_sdk_4.4.5/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_4.4.5/platform/common/src/subdir.mk
-include gecko_sdk_4.4.5/platform/Device/SiliconLabs/EFM32GG/Source/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := flying_soft
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: flying_soft.axf

# Tool invocations
flying_soft.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C++ Linker'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen/linkerfile.ld" -Wl,--no-warn-rwx-segments --specs=nosys.specs -Xlinker --gc-sections -Xlinker -Map="flying_soft.map" --specs=nano.specs -o flying_soft.axf -Wl,--start-group "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./autogen/sl_simple_led_instances.o" "./gecko_sdk_4.4.5/platform/Device/SiliconLabs/EFM32GG/Source/startup_efm32gg.o" "./gecko_sdk_4.4.5/platform/Device/SiliconLabs/EFM32GG/Source/system_efm32gg.o" "./gecko_sdk_4.4.5/platform/common/src/sl_assert.o" "./gecko_sdk_4.4.5/platform/common/src/sl_syscalls.o" "./gecko_sdk_4.4.5/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_4.4.5/platform/driver/leddrv/src/sl_led.o" "./gecko_sdk_4.4.5/platform/driver/leddrv/src/sl_simple_led.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_cmu.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_core.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_emu.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_gpio.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_msc.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_rtc.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_system.o" "./gecko_sdk_4.4.5/platform/emlib/src/em_timer.o" "./gecko_sdk_4.4.5/platform/service/device_init/src/sl_device_init_emu_s0.o" "./gecko_sdk_4.4.5/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_4.4.5/platform/service/sleeptimer/src/sl_sleeptimer.o" "./gecko_sdk_4.4.5/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtc.o" "./gecko_sdk_4.4.5/platform/service/system/src/sl_system_init.o" "./gecko_sdk_4.4.5/platform/service/system/src/sl_system_process_action.o" "./scr/app.o" "./scr/blink.o" "./scr/main.o" -lstdc++ -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: flying_soft.out'
	arm-none-eabi-objcopy "flying_soft.axf" "flying_soft.out"
	@echo ' '

	@echo 'Building hex file: flying_soft.hex'
	arm-none-eabi-objcopy -O ihex "flying_soft.axf" "flying_soft.hex"
	@echo ' '

	@echo 'Building bin file: flying_soft.bin'
	arm-none-eabi-objcopy -O binary "flying_soft.axf" "flying_soft.bin"
	@echo ' '

	@echo 'Building s37 file: flying_soft.s37'
	arm-none-eabi-objcopy -O srec "flying_soft.axf" "flying_soft.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "flying_soft.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(CC_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C++_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_UPPER_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(CXX_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(CPP_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) flying_soft.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
