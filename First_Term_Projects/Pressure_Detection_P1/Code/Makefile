#@copyright: ibrahim
CC    =arm-none-eabi-
CFLAGS=-gdwarf-2 -mcpu=cortex-m3
INCS  =-I .
LIBS  =
SRC   =$(wildcard *.c)
OBJ   =$(SRC:.c=.o)
AS    =$(wildcard *.s)
AsOBJ =$(AS:.s=.o)
project_name=Pressure_Controller_cortex_m3

all: $(project_name).bin
	@echo "=== Bulid is done ==="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c 
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@


clean_all:
	rm *.o *.bin *.elf

clean:
	rm *.bin *.elf
