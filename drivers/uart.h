// include/arch/uart.h
#ifndef _UART_H_
#define _UART_H_

// Adresleri ve registerları tek bir yerden yönetmek en doğrusudur
#define UART_BASE           0xf991f000
#define UART_DM_SR          0xA4
#define UART_DM_TF          0x70
#define UART_DM_ISR         0xB4
#define UART_DM_SR_TXRDY    (1 << 3)

// Fonksiyon prototipleri
void uart_init(void);
void uart_putc(char c);

#endif
