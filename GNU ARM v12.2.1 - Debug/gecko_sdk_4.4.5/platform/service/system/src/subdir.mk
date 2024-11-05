################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/service/system/src/sl_system_init.c \
/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/service/system/src/sl_system_process_action.c 

OBJS += \
./gecko_sdk_4.4.5/platform/service/system/src/sl_system_init.o \
./gecko_sdk_4.4.5/platform/service/system/src/sl_system_process_action.o 

C_DEPS += \
./gecko_sdk_4.4.5/platform/service/system/src/sl_system_init.d \
./gecko_sdk_4.4.5/platform/service/system/src/sl_system_process_action.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.4.5/platform/service/system/src/sl_system_init.o: /Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/service/system/src/sl_system_init.c gecko_sdk_4.4.5/platform/service/system/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.5/platform/service/system/src/sl_system_init.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.5/platform/service/system/src/sl_system_process_action.o: /Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/service/system/src/sl_system_process_action.c gecko_sdk_4.4.5/platform/service/system/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.5/platform/service/system/src/sl_system_process_action.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


