/*
 * include/arch/boot.h
 * Bootloader zıplama (jump) arayüzü
 */

#ifndef BOOT_H
#define BOOT_H

#include <stdint.h>

/**
 * boot_linux - ARM Boot Protocol'ü ile kernel'a zıplar
 * @kernel_addr: Kernel'ın RAM'de yüklendiği adres
 * @dtb_addr: Device Tree Blob'un RAM'de yüklendiği adres
 */
void boot_linux(uint32_t kernel_addr, uint32_t dtb_addr);

#endif // BOOT_H

