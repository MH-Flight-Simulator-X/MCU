################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../autogen/sl_device_init_clocks.c \
../autogen/sl_event_handler.c \
../autogen/sl_simple_led_instances.c 

OBJS += \
./autogen/sl_device_init_clocks.o \
./autogen/sl_event_handler.o \
./autogen/sl_simple_led_instances.o 

C_DEPS += \
./autogen/sl_device_init_clocks.d \
./autogen/sl_event_handler.d \
./autogen/sl_simple_led_instances.d 


# Each subdirectory must supply rules for building sources it contributes
autogen/sl_device_init_clocks.o: ../autogen/sl_device_init_clocks.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_device_init_clocks.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_event_handler.o: ../autogen/sl_event_handler.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_event_handler.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

autogen/sl_simple_led_instances.o: ../autogen/sl_simple_led_instances.c autogen/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"autogen/sl_simple_led_instances.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


