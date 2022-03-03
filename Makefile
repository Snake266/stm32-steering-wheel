##
# Steering wheel
#
# @file
# @version 0.1

CC := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy
LD := arm-none-eabi-ld
SIZE := arm-none-eabi-size
STF := st-flash

TARGET := wheel

MCU := cortex-m4
DEF := STM32F3
FP_FLAGS = -mfloat-abi=hard -mfpu=fpv4-sp-d16
ARCH_FLAGS = -D$(DEF) -mthumb -mcpu=$(MCU) $(FP_FLAGS)

INCLUDE := ./libopencm3/include
LIBPATH := ./libopencm3/lib
LIBNAME_OPENCM3 = opencm3_stm32f3
LIBS = $(LIBNAME_OPENCM3)

LINKER_SCRIPT := linker.ld
FLASH_ADDR := 0x08000000

OBJ_DIR := ./build/obj
BIN_DIR := ./build/bin
SRC_DIR := ./src

BIN := $(BIN_DIR)/$(TARGET).bin
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -std=c99 $(ARCH_FLAGS)
CFLAGS += -Wall -Wshadow -Wextra 
CFLAGS += -g3 -O0 --specs=nosys.specs
CFLAGS += -fno-common -ffunction-sections
CFLAGS += -MMD -MP
CFLAGS += -I$(INCLUDE)

LDFLAGS = --static -L$(LIBPATH) -T$(LINKER_SCRIPT) 

all: $(TARGET).bin

$(TARGET).bin: $(TARGET).elf | $(BIN_DIR)
	$(OBJCOPY) -O binary $(BIN_DIR)/$^ $(BIN_DIR)/$@

$(TARGET).elf: $(OBJS) | $(BIN_DIR)
	$(LD) $(LDFLAGS) $^ -o $(BIN_DIR)/$@ -l$(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

.PHONY: all

-include $(OBJ:.o=.d)
# end
