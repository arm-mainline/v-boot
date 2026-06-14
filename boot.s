.section ".text.boot"

.global _start

_start:
    /* Stack Pointer (SP) ayarı */
    /* Belleğin güvenli bir bölgesini stack olarak ayırıyoruz */
    mov sp, #0x8000

    /* C koduna (main fonksiyonuna) atla */
    bl main

    /* Eğer main'den dönerse (ki dönmemeli), sonsuz döngüde bekle */
    halt:
        wfe
        b halt
