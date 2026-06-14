#include <arch/gpio.h>
#include <arch/io.h> // readl ve writel makrolarımız için

#define TLMM_BASE 0xfd510000

// MSM8226 TLMM register haritası
// Her GPIO bloğu 16 byte'lık (0x10) aralıklarla sıralanır
#define GPIO_CFG(pin)      (TLMM_BASE + (pin * 0x10))
#define GPIO_IN_OUT(pin)   (TLMM_BASE + (pin * 0x10) + 0x04)

void gpio_init(void) {
    // S3 Neo Tuşları için pin konfigürasyonu
    // Bizim ihtiyacımız olan mod: GPIO Modu (Func 0), Input Yönü, Pull-Up Aktif
    
    unsigned int pins[] = {GPIO_VOL_UP, GPIO_VOL_DOWN, GPIO_POWER};
    
    for (int i = 0; i < 3; i++) {
        unsigned int pin = pins[i];
        unsigned int val = readl(GPIO_CFG(pin));
        
        // Bit 0-1: Func_Sel (00 = GPIO)
        // Bit 2: DIR (0 = Input)
        // Bit 3-4: Pull (10 = Pull Up)
        val &= ~(0x3FF);    // Önce eski ayarları temizle
        val |= (0x2 << 3);  // Pull Up aktivasyonu
        
        writel(val, GPIO_CFG(pin));
    }
}

int gpio_get_state(int pin) {
    // GPIO_IN_OUT register'ının 1. biti (mask 0x2) "IN" değerini tutar
    // Eğer 0 ise buton basılıdır (çünkü Pull-Up ile 1'de tutulur, basınca GND'ye çeker)
    unsigned int val = readl(GPIO_IN_OUT(pin));
    return !(val & 0x2); 
}
