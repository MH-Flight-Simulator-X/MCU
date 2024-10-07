####################################################################
# Automatically-generated file. Do not edit!                       #
# Makefile Version 15                                              #
####################################################################

BASE_SDK_PATH = ./gecko_sdk
UNAME:=$(shell $(POSIX_TOOL_PATH)uname -s | $(POSIX_TOOL_PATH)sed -e 's/^\(CYGWIN\).*/\1/' | $(POSIX_TOOL_PATH)sed -e 's/^\(MINGW\).*/\1/')
ifeq ($(UNAME),MINGW)
# Translate "C:/super" into "/C/super" for MinGW make.
SDK_PATH := /$(shell $(POSIX_TOOL_PATH)echo $(BASE_SDK_PATH) | sed s/://)
endif
SDK_PATH ?= $(BASE_SDK_PATH)
COPIED_SDK_PATH ?= gecko_sdk

# This uses the explicit build rules below
PROJECT_SOURCE_FILES =

C_SOURCE_FILES   += $(filter %.c, $(PROJECT_SOURCE_FILES))
CXX_SOURCE_FILES += $(filter %.cpp, $(PROJECT_SOURCE_FILES))
CXX_SOURCE_FILES += $(filter %.cc, $(PROJECT_SOURCE_FILES))
ASM_SOURCE_FILES += $(filter %.s, $(PROJECT_SOURCE_FILES))
ASM_SOURCE_FILES += $(filter %.S, $(PROJECT_SOURCE_FILES))
LIB_FILES        += $(filter %.a, $(PROJECT_SOURCE_FILES))

C_DEFS += \
 '-DDEBUG_EFM=1' \
 '-DEFM32GG990F1024=1' \
 '-DHFXO_FREQ=48000000' \
 '-DSL_BOARD_NAME="BRD2200C"' \
 '-DSL_BOARD_REV="A01"' \
 '-DSL_COMPONENT_CATALOG_PRESENT=1'

ASM_DEFS += \
 '-DDEBUG_EFM=1' \
 '-DEFM32GG990F1024=1' \
 '-DHFXO_FREQ=48000000' \
 '-DSL_BOARD_NAME="BRD2200C"' \
 '-DSL_BOARD_REV="A01"' \
 '-DSL_COMPONENT_CATALOG_PRESENT=1'

INCLUDES += \
 -Iconfig \
 -Iautogen \
 -Iinc \
 -I. \
 -I$(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFM32GG/Include \
 -I$(COPIED_SDK_PATH)/platform/common/inc \
 -I$(COPIED_SDK_PATH)/hardware/board/inc \
 -I$(COPIED_SDK_PATH)/platform/driver/button/inc \
 -I$(COPIED_SDK_PATH)/platform/CMSIS/Core/Include \
 -I$(COPIED_SDK_PATH)/hardware/driver/configuration_over_swo/inc \
 -I$(COPIED_SDK_PATH)/platform/driver/debug/inc \
 -I$(COPIED_SDK_PATH)/platform/service/device_init/inc \
 -I$(COPIED_SDK_PATH)/platform/emdrv/dmadrv/inc \
 -I$(COPIED_SDK_PATH)/platform/emdrv/common/inc \
 -I$(COPIED_SDK_PATH)/platform/emlib/inc \
 -I$(COPIED_SDK_PATH)/platform/emdrv/gpiointerrupt/inc \
 -I$(COPIED_SDK_PATH)/platform/service/iostream/inc \
 -I$(COPIED_SDK_PATH)/platform/driver/leddrv/inc \
 -I$(COPIED_SDK_PATH)/platform/emdrv/spidrv/inc \
 -I$(COPIED_SDK_PATH)/platform/emdrv/spidrv/config \
 -I$(COPIED_SDK_PATH)/platform/service/power_manager/inc \
 -I$(COPIED_SDK_PATH)/platform/common/toolchain/inc \
 -I$(COPIED_SDK_PATH)/platform/service/system/inc \
 -I$(COPIED_SDK_PATH)/platform/service/sleeptimer/inc \
 -I$(COPIED_SDK_PATH)/platform/emdrv/spidrv/inc \
 -I$(COPIED_SDK_PATH)/hardware/kit/common/drivers


GROUP_START =-Wl,--start-group
GROUP_END =-Wl,--end-group

PROJECT_LIBS = \
 -lgcc \
 -lc \
 -lm \
 -lnosys

LIBS += $(GROUP_START) $(PROJECT_LIBS) $(GROUP_END)

LIB_FILES += $(filter %.a, $(PROJECT_LIBS))

C_FLAGS += \
 -mcpu=cortex-m3 \
 -mthumb \
 -std=c99 \
 -Wall \
 -Wextra \
 -Os \
 -fdata-sections \
 -ffunction-sections \
 -fomit-frame-pointer \
 -imacros sl_gcc_preinclude.h \
 --specs=nano.specs \
 -g

CXX_FLAGS += \
 -mcpu=cortex-m3 \
 -mthumb \
 -std=c++11 \
 -fno-rtti \
 -fno-exceptions \
 -Wall \
 -Wextra \
 -Os \
 -fdata-sections \
 -ffunction-sections \
 -fomit-frame-pointer \
 -imacros sl_gcc_preinclude.h \
 --specs=nano.specs \
 -g

ASM_FLAGS += \
 -mcpu=cortex-m3 \
 -mthumb \
 -imacros sl_gcc_preinclude.h \
 -x assembler-with-cpp

LD_FLAGS += \
 -mcpu=cortex-m3 \
 -mthumb \
 -T"autogen/linkerfile.ld" \
 --specs=nano.specs \
 -Xlinker -Map=$(OUTPUT_DIR)/$(PROJECTNAME).map \
 -Wl,--gc-sections \
 -Wl,--no-warn-rwx-segments


####################################################################
# Pre/Post Build Rules                                             #
####################################################################
pre-build:
	# No pre-build defined

post-build: $(OUTPUT_DIR)/$(PROJECTNAME).out
	# No post-build defined

####################################################################
# SDK Build Rules                                                  #
####################################################################
$(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_control_gpio.o: $(COPIED_SDK_PATH)/hardware/board/src/sl_board_control_gpio.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/hardware/board/src/sl_board_control_gpio.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/hardware/board/src/sl_board_control_gpio.c
CDEPS += $(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_control_gpio.d
OBJS += $(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_control_gpio.o

$(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_init.o: $(COPIED_SDK_PATH)/hardware/board/src/sl_board_init.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/hardware/board/src/sl_board_init.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/hardware/board/src/sl_board_init.c
CDEPS += $(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_init.d
OBJS += $(OUTPUT_DIR)/sdk/hardware/board/src/sl_board_init.o

$(OUTPUT_DIR)/sdk/hardware/driver/configuration_over_swo/src/sl_cos.o: $(COPIED_SDK_PATH)/hardware/driver/configuration_over_swo/src/sl_cos.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/hardware/driver/configuration_over_swo/src/sl_cos.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/hardware/driver/configuration_over_swo/src/sl_cos.c
CDEPS += $(OUTPUT_DIR)/sdk/hardware/driver/configuration_over_swo/src/sl_cos.d
OBJS += $(OUTPUT_DIR)/sdk/hardware/driver/configuration_over_swo/src/sl_cos.o

$(OUTPUT_DIR)/sdk/platform/common/src/sl_assert.o: $(COPIED_SDK_PATH)/platform/common/src/sl_assert.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/common/src/sl_assert.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/common/src/sl_assert.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_assert.d
OBJS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_assert.o

$(OUTPUT_DIR)/sdk/platform/common/src/sl_slist.o: $(COPIED_SDK_PATH)/platform/common/src/sl_slist.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/common/src/sl_slist.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/common/src/sl_slist.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_slist.d
OBJS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_slist.o

$(OUTPUT_DIR)/sdk/platform/common/src/sl_string.o: $(COPIED_SDK_PATH)/platform/common/src/sl_string.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/common/src/sl_string.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/common/src/sl_string.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_string.d
OBJS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_string.o

$(OUTPUT_DIR)/sdk/platform/common/src/sl_syscalls.o: $(COPIED_SDK_PATH)/platform/common/src/sl_syscalls.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/common/src/sl_syscalls.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/common/src/sl_syscalls.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_syscalls.d
OBJS += $(OUTPUT_DIR)/sdk/platform/common/src/sl_syscalls.o

$(OUTPUT_DIR)/sdk/platform/common/toolchain/src/sl_memory.o: $(COPIED_SDK_PATH)/platform/common/toolchain/src/sl_memory.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/common/toolchain/src/sl_memory.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/common/toolchain/src/sl_memory.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/common/toolchain/src/sl_memory.d
OBJS += $(OUTPUT_DIR)/sdk/platform/common/toolchain/src/sl_memory.o

$(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFM32GG/Source/startup_efm32gg.o: $(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFM32GG/Source/startup_efm32gg.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFM32GG/Source/startup_efm32gg.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFM32GG/Source/startup_efm32gg.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFM32GG/Source/startup_efm32gg.d
OBJS += $(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFM32GG/Source/startup_efm32gg.o

$(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFM32GG/Source/system_efm32gg.o: $(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFM32GG/Source/system_efm32gg.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFM32GG/Source/system_efm32gg.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/Device/SiliconLabs/EFM32GG/Source/system_efm32gg.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFM32GG/Source/system_efm32gg.d
OBJS += $(OUTPUT_DIR)/sdk/platform/Device/SiliconLabs/EFM32GG/Source/system_efm32gg.o

$(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_button.o: $(COPIED_SDK_PATH)/platform/driver/button/src/sl_button.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/driver/button/src/sl_button.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/driver/button/src/sl_button.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_button.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_button.o

$(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_simple_button.o: $(COPIED_SDK_PATH)/platform/driver/button/src/sl_simple_button.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/driver/button/src/sl_simple_button.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/driver/button/src/sl_simple_button.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_simple_button.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/button/src/sl_simple_button.o

$(OUTPUT_DIR)/sdk/platform/driver/debug/src/sl_debug_swo.o: $(COPIED_SDK_PATH)/platform/driver/debug/src/sl_debug_swo.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/driver/debug/src/sl_debug_swo.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/driver/debug/src/sl_debug_swo.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/debug/src/sl_debug_swo.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/debug/src/sl_debug_swo.o

$(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_led.o: $(COPIED_SDK_PATH)/platform/driver/leddrv/src/sl_led.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/driver/leddrv/src/sl_led.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/driver/leddrv/src/sl_led.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_led.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_led.o

$(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_simple_led.o: $(COPIED_SDK_PATH)/platform/driver/leddrv/src/sl_simple_led.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/driver/leddrv/src/sl_simple_led.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/driver/leddrv/src/sl_simple_led.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_simple_led.d
OBJS += $(OUTPUT_DIR)/sdk/platform/driver/leddrv/src/sl_simple_led.o

$(OUTPUT_DIR)/sdk/platform/emdrv/dmadrv/src/dmactrl.o: $(COPIED_SDK_PATH)/platform/emdrv/dmadrv/src/dmactrl.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emdrv/dmadrv/src/dmactrl.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emdrv/dmadrv/src/dmactrl.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emdrv/dmadrv/src/dmactrl.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emdrv/dmadrv/src/dmactrl.o

$(OUTPUT_DIR)/sdk/platform/emdrv/dmadrv/src/dmadrv.o: $(COPIED_SDK_PATH)/platform/emdrv/dmadrv/src/dmadrv.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emdrv/dmadrv/src/dmadrv.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emdrv/dmadrv/src/dmadrv.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emdrv/dmadrv/src/dmadrv.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emdrv/dmadrv/src/dmadrv.o

$(OUTPUT_DIR)/sdk/platform/emdrv/gpiointerrupt/src/gpiointerrupt.o: $(COPIED_SDK_PATH)/platform/emdrv/gpiointerrupt/src/gpiointerrupt.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emdrv/gpiointerrupt/src/gpiointerrupt.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emdrv/gpiointerrupt/src/gpiointerrupt.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emdrv/gpiointerrupt/src/gpiointerrupt.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emdrv/gpiointerrupt/src/gpiointerrupt.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_cmu.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_cmu.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_cmu.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_cmu.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_cmu.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_cmu.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_core.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_core.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_core.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_core.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_core.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_core.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_dma.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_dma.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_dma.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_dma.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_dma.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_dma.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_emu.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_emu.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_emu.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_emu.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_emu.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_emu.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_gpio.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_gpio.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_gpio.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_gpio.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_gpio.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_gpio.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_msc.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_msc.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_msc.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_msc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_msc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_msc.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_rtc.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_rtc.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_rtc.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_rtc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_rtc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_rtc.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_system.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_system.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_system.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_system.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_system.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_system.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_timer.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_timer.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_timer.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_timer.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_timer.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_timer.o

$(OUTPUT_DIR)/sdk/platform/emlib/src/em_usart.o: $(COPIED_SDK_PATH)/platform/emlib/src/em_usart.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emlib/src/em_usart.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emlib/src/em_usart.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_usart.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emlib/src/em_usart.o

$(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_emu_s0.o: $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_emu_s0.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_emu_s0.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_emu_s0.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_emu_s0.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_emu_s0.o

$(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_hfxo_s0.o: $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_hfxo_s0.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_hfxo_s0.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_hfxo_s0.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_hfxo_s0.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_hfxo_s0.o

$(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_lfxo_s0.o: $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_lfxo_s0.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_lfxo_s0.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_lfxo_s0.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_lfxo_s0.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_lfxo_s0.o

$(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_nvic.o: $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_nvic.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_nvic.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/device_init/src/sl_device_init_nvic.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_nvic.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/device_init/src/sl_device_init_nvic.o

$(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream.o: $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream.o

$(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_retarget_stdio.o: $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream_retarget_stdio.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream_retarget_stdio.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream_retarget_stdio.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_retarget_stdio.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_retarget_stdio.o

$(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_stdlib_config.o: $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream_stdlib_config.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream_stdlib_config.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream_stdlib_config.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_stdlib_config.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_stdlib_config.o

$(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_uart.o: $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream_uart.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream_uart.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream_uart.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_uart.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_uart.o

$(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_usart.o: $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream_usart.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream_usart.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/iostream/src/sl_iostream_usart.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_usart.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/iostream/src/sl_iostream_usart.o

$(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager.o: $(COPIED_SDK_PATH)/platform/service/power_manager/src/sl_power_manager.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/power_manager/src/sl_power_manager.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/power_manager/src/sl_power_manager.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager.o

$(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager_debug.o: $(COPIED_SDK_PATH)/platform/service/power_manager/src/sl_power_manager_debug.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/power_manager/src/sl_power_manager_debug.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/power_manager/src/sl_power_manager_debug.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager_debug.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager_debug.o

$(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager_hal_s0_s1.o: $(COPIED_SDK_PATH)/platform/service/power_manager/src/sl_power_manager_hal_s0_s1.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/power_manager/src/sl_power_manager_hal_s0_s1.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/power_manager/src/sl_power_manager_hal_s0_s1.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager_hal_s0_s1.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/power_manager/src/sl_power_manager_hal_s0_s1.o

$(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer.o: $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer.o

$(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtc.o: $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtc.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtc.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtc.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtc.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtc.o

$(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_init.o: $(COPIED_SDK_PATH)/platform/service/system/src/sl_system_init.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/system/src/sl_system_init.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/system/src/sl_system_init.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_init.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_init.o

$(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_process_action.o: $(COPIED_SDK_PATH)/platform/service/system/src/sl_system_process_action.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/service/system/src/sl_system_process_action.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/service/system/src/sl_system_process_action.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_process_action.d
OBJS += $(OUTPUT_DIR)/sdk/platform/service/system/src/sl_system_process_action.o

$(OUTPUT_DIR)/project/app.o: scr/app.c
	@$(POSIX_TOOL_PATH)echo 'Building app.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ scr/app.c
CDEPS += $(OUTPUT_DIR)/project/app.d
OBJS += $(OUTPUT_DIR)/project/app.o

$(OUTPUT_DIR)/project/autogen/sl_board_default_init.o: autogen/sl_board_default_init.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_board_default_init.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_board_default_init.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_board_default_init.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_board_default_init.o

$(OUTPUT_DIR)/project/autogen/sl_device_init_clocks.o: autogen/sl_device_init_clocks.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_device_init_clocks.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_device_init_clocks.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_device_init_clocks.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_device_init_clocks.o

$(OUTPUT_DIR)/project/autogen/sl_event_handler.o: autogen/sl_event_handler.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_event_handler.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_event_handler.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_event_handler.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_event_handler.o

$(OUTPUT_DIR)/project/autogen/sl_iostream_handles.o: autogen/sl_iostream_handles.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_iostream_handles.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_iostream_handles.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_iostream_handles.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_iostream_handles.o

$(OUTPUT_DIR)/project/autogen/sl_iostream_init_uart_instances.o: autogen/sl_iostream_init_uart_instances.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_iostream_init_uart_instances.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_iostream_init_uart_instances.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_iostream_init_uart_instances.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_iostream_init_uart_instances.o

$(OUTPUT_DIR)/project/autogen/sl_power_manager_handler.o: autogen/sl_power_manager_handler.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_power_manager_handler.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_power_manager_handler.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_power_manager_handler.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_power_manager_handler.o

$(OUTPUT_DIR)/project/autogen/sl_simple_button_instances.o: autogen/sl_simple_button_instances.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_simple_button_instances.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_simple_button_instances.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_simple_button_instances.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_simple_button_instances.o

$(OUTPUT_DIR)/project/autogen/sl_simple_led_instances.o: autogen/sl_simple_led_instances.c
	@$(POSIX_TOOL_PATH)echo 'Building autogen/sl_simple_led_instances.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/sl_simple_led_instances.c
CDEPS += $(OUTPUT_DIR)/project/autogen/sl_simple_led_instances.d
OBJS += $(OUTPUT_DIR)/project/autogen/sl_simple_led_instances.o

$(OUTPUT_DIR)/project/main.o: scr/main.c
	@$(POSIX_TOOL_PATH)echo 'Building scr/main.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ scr/main.c
CDEPS += $(OUTPUT_DIR)/project/main.d
OBJS += $(OUTPUT_DIR)/project/main.o

# $(OUTPUT_DIR)/project/spi_button.o: scr/spi_button.c
# 	@$(POSIX_TOOL_PATH)echo 'Building spi_button.c'
# 	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
# 	$(ECHO)$(CC) $(CFLAGS) -c -o $@ scr/spi_button.c
# CDEPS += $(OUTPUT_DIR)/project/spi_button.d
# OBJS += $(OUTPUT_DIR)/project/spi_button.o

$(OUTPUT_DIR)/project/spi_slave.o: scr/spi_slave.c
	@$(POSIX_TOOL_PATH)echo 'Building spi_slave.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ scr/spi_slave.c
CDEPS += $(OUTPUT_DIR)/project/spi_slave.d
OBJS += $(OUTPUT_DIR)/project/spi_slave.o

$(OUTPUT_DIR)/sdk/platform/emdrv/spidrv/src/spidrv.o: $(COPIED_SDK_PATH)/platform/emdrv/spidrv/src/spidrv.c
	@$(POSIX_TOOL_PATH)echo 'Building $(COPIED_SDK_PATH)/platform/emdrv/spidrv/src/spidrv.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ $(COPIED_SDK_PATH)/platform/emdrv/spidrv/src/spidrv.c
CDEPS += $(OUTPUT_DIR)/sdk/platform/emdrv/spidrv/src/spidrv.d
OBJS += $(OUTPUT_DIR)/sdk/platform/emdrv/spidrv/src/spidrv.o

$(OUTPUT_DIR)/project/physics_engine.o: scr/physics_engine.c
	@$(POSIX_TOOL_PATH)echo 'Building physics_engine.c'
	@$(POSIX_TOOL_PATH)mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ scr/physics_engine.c
CDEPS += $(OUTPUT_DIR)/project/physics_engine.d
OBJS += $(OUTPUT_DIR)/project/physics_engine.o

# Automatically-generated Simplicity Studio Metadata
# Please do not edit or delete these lines!
# SIMPLICITY_STUDIO_METADATA=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END_SIMPLICITY_STUDIO_METADATA
# END OF METADATA