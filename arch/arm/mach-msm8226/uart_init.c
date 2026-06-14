#include "../../../drivers/uart.h"
#include "../../../drivers/io.h"

// GCC (Clock) ve TLMM (GPIO) Base adresleri
#define GCC_BASE        0xFC400000
#define TLMM_BASE       0xFD510000

// Register Offsetleri
#define GCC_BLSP1_UART3_APPS_CBCR  0x6004
#define UART3_GPIO_CFG_ADDR        0x1000

// drivers/uart.c içindeki fonksiyonu burada tanımlıyoruz
extern void uart_driver_config(void);

void uart_init(void) {
    // 1. Clock (Saat) Sinyalini Aktif Et (GCC)
    unsigned int val = readl(GCC_BASE + GCC_BLSP1_UART3_APPS_CBCR);
    val |= 0x1; 
    writel(val, GCC_BASE + GCC_BLSP1_UART3_APPS_CBCR);

    // 2. GPIO Pinlerini UART Moduna Al (TLMM)
    writel(0x02, TLMM_BASE + UART3_GPIO_CFG_ADDR);

    // 3. Sürücüyü Yapılandır
    uart_driver_config();
}
