##
# Steering wheel
#
# @file
# @version 0.1

CC := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy
LD := arm-none-ld
SIZE := arm-none-eabi-size
STF := st-flash

TARGET := wheel

MCU := cortex-m0

INCLUDE := include
CMSIS := $(INCLUDE)/CMSIS
LINKER_SCRIPT := linker.ld

FLASH_ADDR := 0x08000000

OBJ_DIR := build/obj
BIN_DIR := build/bin
SRC_DIR := src

BIN := $(BIN_DIR)/$(TARGET)
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -std=c99 -mthumb -mcpu=$(MCU)
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -g
CFLAGS += -fno-common -ffunction-sections --gc-sections
CFLAGS += -MMD -MP
CFLAGS += -I$(INCLUDE)

ASFLAGS := -mthumb -mcpu=$(MCU) -g -Wall

LDFLAGS := -T$(LINKER_SCRIPT) -g

all: $(TARGET).bin

$(TARGET).bin: $(TARGET).elf | $(BIN_DIR)
	$(OBJCOPY) -O binary $(TARGET).elf $(BIN_DIR)/$@

$(TARGET).elf: $(OBJ) | $(BIN_DIR)
	$(LD) $(LDFLAGS) $^ -o $(TARGET).elf -o $(BIN_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

.PHONY: all clean

-include
# end
