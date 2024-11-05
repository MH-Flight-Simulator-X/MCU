################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../scr/app.cpp \
../scr/blink.cpp \
../scr/main.cpp 

OBJS += \
./scr/app.o \
./scr/blink.o \
./scr/main.o 

CPP_DEPS += \
./scr/app.d \
./scr/blink.d \
./scr/main.d 


# Each subdirectory must supply rules for building sources it contributes
scr/app.o: ../scr/app.cpp scr/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c++11 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -fno-rtti -fno-exceptions --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"scr/app.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

scr/blink.o: ../scr/blink.cpp scr/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c++11 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -fno-rtti -fno-exceptions --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"scr/blink.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

scr/main.o: ../scr/main.cpp scr/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c++11 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -fno-rtti -fno-exceptions --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"scr/main.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

