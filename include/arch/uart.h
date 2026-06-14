#ifndef UART_H
#define UART_H

/* MSM8226 BLSP1 UART2 Standart Base Adresi (Debug Konsolu için Genelde budur) */
#ifndef UART_BASE
#define UART_BASE          0x78B00000 
#endif

/* Qualcomm UARTDM Yazmaç Ofsetleri */
#define UART_DM_SR         0x00A4  /* Status Register */
#define UART_DM_ISR        0x00B4  /* Interrupt Status Register */
#define UART_DM_SR         0x00A4  /* Status Register */
#define UART_DM_ISR        0x00B4  /* Interrupt Status Register */
#define UART_DM_TF         0x0070  /* Transmit FIFO Register <--- BU SATIRI EKLEYİN */

/* UARTDM Durum Bitleri */
#define UART_DM_SR_TXRDY   (1 << 2) /* Transmitter Ready */

/* Fonksiyon Prototipleri (boot.c'deki uyarıyı çözmek için) */
void uart_driver_config(void);
void uart_putc(char c);
void uart_puts(const char *s);

#endif // UART_H

