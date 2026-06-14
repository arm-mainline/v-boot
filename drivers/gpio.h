#ifndef GPIO_H
#define GPIO_H

// Gerekli fonksiyon prototipleri
void gpio_init(void);
int gpio_get_state(int pin);

// Eğer GPIO numaraların (GPIO_VOL_UP vb.) başka bir yerde tanımlı değilse
// onları da buraya eklemelisin. Örneğin:
#define GPIO_VOL_UP    115
#define GPIO_VOL_DOWN  114
#define GPIO_POWER     116

#endif
