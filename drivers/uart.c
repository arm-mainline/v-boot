#include "../include/arch/uart.h"
#include "../include/arch/io.h"

// Sürücünün iç konfigürasyonu (arch katmanından çağrılacak)
void uart_driver_config(void) {
    // UARTDM Reset
    writel(0x8000, UART_BASE + 0x10); 
    // UARTDM Enable (TX/RX)
    writel(0x05, UART_BASE + 0x10);
    // Interruptları temizle
    writel(0x00, UART_BASE + UART_DM_ISR);
}

void uart_putc(char c) {
    while (!(readl(UART_BASE + UART_DM_SR) & UART_DM_SR_TXRDY));
    writel((unsigned int)c, UART_BASE + UART_DM_TF);
}

void uart_puts(const char *s) {
    while (*s) {
        if (*s == '\n') uart_putc('\r');
        uart_putc(*s++);
    }
}
