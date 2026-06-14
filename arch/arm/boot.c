/*
 * arch/arm/boot.c
 * ARMv7 mimarisi için kernel zıplama mantığı
 */

#include <stdint.h>
#include <arch/uart.h> // UART logları için

// Kernel'ın beklentisi: r0=0, r1=machine_id, r2=dtb_addr
extern void kernel_entry(uint32_t r0, uint32_t r1, uint32_t r2);

void boot_linux(uint32_t kernel_addr, uint32_t dtb_addr) {
    uart_puts(">> Preparing ARM registers for Kernel...\n");
    uart_puts(">> Kernel Addr: 0x");
    // Burada basit bir hex_print fonksiyonu çağrılabilir (eklemek istersen)
    
    uart_puts(">> Jumping to Kernel entry point!\n");

    // ARM Boot Protocol'ü:
    // r0: 0
    // r1: 0 (Machine ID - Artık DTB kullanıldığı için 0 olması beklenir)
    // r2: dtb_addr (Device Tree adresi - Çok kritik!)
    
    __asm__ volatile (
        "mov r0, #0\n"
        "mov r1, #0\n"
        "mov r2, %0\n"      // r2'ye dtb_addr'ı koy
        "bx %1\n"           // r15 (PC) register'ına kernel adresini at ve zıpla
        : 
        : "r" (dtb_addr), "r" (kernel_addr)
        : "r0", "r1", "r2"
    );
}
