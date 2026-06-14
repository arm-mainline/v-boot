/*
 * v-boot: main.c
 * Projenin giriş noktası ve menü yönetim merkezi
 */

#include <arch/uart.h>
#include <arch/gpio.h>
#include <arch/boot.h>  // arch/arm/boot.c fonksiyonlarını buradan çağıracağız
#include <lib/utils.h>  // mdelay vb. için
extern void uart_init(void);
extern void uart_puts(const char *s);
// Menü seçenekleri
typedef enum {
    MODE_BOOT_KERNEL,
    MODE_FASTBOOT,
    MODE_RECOVERY
} boot_mode_t;

static boot_mode_t current_mode = MODE_BOOT_KERNEL;

// Kernel ve DTB adresleri (MSM8226 standartları)
#define KERNEL_ADDR 0x00008000
#define DTB_ADDR    0x01E00000

void draw_menu(void) {
    uart_puts("\033[2J\033[H"); // Ekranı temizle
    uart_puts("--- v-boot Manager v0.1 ---\n");
    uart_puts(current_mode == MODE_BOOT_KERNEL  ? "> [ ] Boot Kernel\n"  : "    [ ] Boot Kernel\n");
    uart_puts(current_mode == MODE_FASTBOOT     ? "> [ ] Fastboot\n"     : "    [ ] Fastboot\n");
    uart_puts(current_mode == MODE_RECOVERY     ? "> [ ] Recovery\n"     : "    [ ] Recovery\n");
    uart_puts("\nVol Up/Down: Select | Power: Confirm\n");
}

void main(void) {
    // 1. Donanım Başlatma
    uart_init();
    gpio_init();

    uart_puts("v-boot initialising...\n");

    // 2. Ana Menü Döngüsü
    while(1) {
        draw_menu();

        // Tuş okuma (GPIO sürücülerine bağlı)
        if (gpio_get_state(GPIO_VOL_UP)) {
            if (current_mode > 0) current_mode--;
            mdelay(200);
        }
        else if (gpio_get_state(GPIO_VOL_DOWN)) {
            if (current_mode < 2) current_mode++;
            mdelay(200);
        }
        else if (gpio_get_state(GPIO_POWER)) {
            // Seçim yapıldı
            break;
        }
        mdelay(50);
    }

    // 3. Seçilen Aksiyon
    switch (current_mode) {
        case MODE_BOOT_KERNEL:
            uart_puts("Booting Android Kernel...\n");
            // arch/arm/boot.c içindeki fonksiyonu çağır
            boot_linux(KERNEL_ADDR, DTB_ADDR);
            break;

        case MODE_FASTBOOT:
            uart_puts("Entering Fastboot mode...\n");
            // fastboot_init(); 
            break;

        case MODE_RECOVERY:
            uart_puts("Entering Recovery mode...\n");
            // recovery_init();
            break;
    }

    // Eğer bir şekilde buraya düşersek (hata durumu)
    while(1); 
}
