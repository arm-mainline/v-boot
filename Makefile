# Derleyici ve Araçlar
CROSS_COMPILE = arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy

# Derleme Bayrakları
# -Iinclude: include klasörünü header dosyaları için arama yoluna ekler
CFLAGS = -mcpu=cortex-a7 -ffreestanding -Wall -O2 -Iinclude -Iarch/arm/mach-msm8226
LDFLAGS = -T link.ld -nostdlib

# Tüm kaynak dosyalarını otomatik bul
# .c uzantılı tüm dosyaları bulur
C_SOURCES = $(shell find . -name "*.c")
# .s uzantılı tüm dosyaları bulur (boot.s dahil)
S_SOURCES = $(shell find . -name "*.s")

# Object dosyalarına çevir
OBJECTS = $(C_SOURCES:.c=.o) $(S_SOURCES:.s=.o)

# Hedefler
all: vboot.bin

# Binary dosyasını üret
vboot.bin: vboot.elf
	$(OBJCOPY) -O binary $< $@

# ELF dosyasını oluştur
vboot.elf: $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^

# .c dosyalarını derle
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# .s dosyalarını derle
%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	find . -name "*.o" -type f -delete
	rm -f vboot.elf vboot.bin
