CC = arm-none-eabi-gcc
MACH = cortex-m4
DRIVERSCORE = Drivers/Core/Include
DRIVERDEVICE = Drivers/Device/ST/STM32F4xx/Include
DRIVERHAL = Drivers/HAL_Inc
PROCESSOR = STM32F401xC
INCLUDES = -I. -I$(DRIVERSCORE) -I$(DRIVERDEVICE) -I$(DRIVERHAL)
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0 $(INCLUDES) -D$(PROCESSOR) -Wall
LDFLAGS = -T startup_f401.ld -nostdlib -lc -lgcc -lnosys -Wl,-Map=$(BUILD_DIR)/final.map
BINFLAG = arm-none-eabi-objcopy -O binary
SOURCE_DIR = Src
STARTUP_DIR = Startup
BUILD_DIR = build
DRIVER_DIR = Drivers/HAL_Src
CUBEPATH = /usr/local/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/STM32_Programmer_CLI


SRC = $(wildcard $(SOURCE_DIR)/*.c) $(wildcard $(STARTUP_DIR)/*.c) $(wildcard $(DRIVER_DIR)/*.c)
OBJ = $(patsubst %.c, $(BUILD_DIR)/%.o, $(notdir $(SRC)))

all: $(BUILD_DIR)/final.bin
	arm-none-eabi-size $(BUILD_DIR)/final.elf

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(DRIVER_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/%.o: $(STARTUP_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/final.elf: $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

$(BUILD_DIR)/final.bin: $(BUILD_DIR)/final.elf
	$(BINFLAG) $(BUILD_DIR)/final.elf $@

clean:
	rm -rf $(BUILD_DIR) $(BUILD_DIR)/*.elf $(BUILD_DIR)/*.bin $(BUILD_DIR)/*.map

release:
	rm -rf $(BUILD_DIR)

flash:
	@echo "--- FLASHING CODE ---"
	$(CUBEPATH) -c port=usb1 speed=1000 -d $(BUILD_DIR)/final.bin 0x08000000
	$(CUBEPATH) -c port=usb1 -s 0x08000000
	@echo "--- FLASH COMPLETE. DEVICE RESET ---"

erase:
	$(CUBEPATH) -c port=usb1 -e all