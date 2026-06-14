#ifndef UTILS_H
#define UTILS_H

// Basit bir yazılımsal milisaniye gecikme döngüsü
static inline void mdelay(unsigned int ms) {
    volatile unsigned int i;
    while (ms--) {
        // Cortex-A7 için kabaca 1 milisaniyeye denk gelecek döngü sayısı
        for (i = 0; i < 5000; i++) {
            asm volatile("nop");
        }
    }
}

#endif // UTILS_H

