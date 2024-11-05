################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_cmu.c \
/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_core.c \
/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_emu.c \
/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_gpio.c \
/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_msc.c \
/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_rtc.c \
/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_system.c \
/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_timer.c 

OBJS += \
./gecko_sdk_4.4.5/platform/emlib/src/em_cmu.o \
./gecko_sdk_4.4.5/platform/emlib/src/em_core.o \
./gecko_sdk_4.4.5/platform/emlib/src/em_emu.o \
./gecko_sdk_4.4.5/platform/emlib/src/em_gpio.o \
./gecko_sdk_4.4.5/platform/emlib/src/em_msc.o \
./gecko_sdk_4.4.5/platform/emlib/src/em_rtc.o \
./gecko_sdk_4.4.5/platform/emlib/src/em_system.o \
./gecko_sdk_4.4.5/platform/emlib/src/em_timer.o 

C_DEPS += \
./gecko_sdk_4.4.5/platform/emlib/src/em_cmu.d \
./gecko_sdk_4.4.5/platform/emlib/src/em_core.d \
./gecko_sdk_4.4.5/platform/emlib/src/em_emu.d \
./gecko_sdk_4.4.5/platform/emlib/src/em_gpio.d \
./gecko_sdk_4.4.5/platform/emlib/src/em_msc.d \
./gecko_sdk_4.4.5/platform/emlib/src/em_rtc.d \
./gecko_sdk_4.4.5/platform/emlib/src/em_system.d \
./gecko_sdk_4.4.5/platform/emlib/src/em_timer.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.4.5/platform/emlib/src/em_cmu.o: /Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_cmu.c gecko_sdk_4.4.5/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.5/platform/emlib/src/em_cmu.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.5/platform/emlib/src/em_core.o: /Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_core.c gecko_sdk_4.4.5/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.5/platform/emlib/src/em_core.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.5/platform/emlib/src/em_emu.o: /Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_emu.c gecko_sdk_4.4.5/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.5/platform/emlib/src/em_emu.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.5/platform/emlib/src/em_gpio.o: /Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_gpio.c gecko_sdk_4.4.5/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.5/platform/emlib/src/em_gpio.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.5/platform/emlib/src/em_msc.o: /Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_msc.c gecko_sdk_4.4.5/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.5/platform/emlib/src/em_msc.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.5/platform/emlib/src/em_rtc.o: /Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_rtc.c gecko_sdk_4.4.5/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.5/platform/emlib/src/em_rtc.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.5/platform/emlib/src/em_system.o: /Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_system.c gecko_sdk_4.4.5/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.5/platform/emlib/src/em_system.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.5/platform/emlib/src/em_timer.o: /Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2/platform/emlib/src/em_timer.c gecko_sdk_4.4.5/platform/emlib/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFM32GG842F1024=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/config" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/autogen" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/Device/SiliconLabs/EFM32GG/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/CMSIS/Core/Include" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/device_init/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/emlib/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/driver/leddrv/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/common/toolchain/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/system/inc" -I"/Users/eivindnesje/SimplicityStudio/SDKs/gecko_sdk_2//platform/service/sleeptimer/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/inc" -I"/Users/eivindnesje/SimplicityStudio/v5_workspace/flying_soft/scr" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.5/platform/emlib/src/em_timer.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


