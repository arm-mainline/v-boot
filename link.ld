/* Giriş noktasını belirtiyoruz (Genellikle Assembly ile yazılan _start etiketidir) */
ENTRY(_start)

SECTIONS
{
    /* Bootloader kodumuzun 0x8000 adresinden başlayacağını belirtiyoruz */
    . = 0x8000;

    /* Kod bölümü */
    .text : {
        *(.text)
    }

    /* Salt okunur veriler (const değişkenler) */
    .rodata : {
        *(.rodata)
    }

    /* Başlatılmış global değişkenler */
    .data : {
        *(.data)
    }

    /* Başlatılmamış değişkenler (Bunları programın başında sıfırlamalısın) */
    .bss : {
        __bss_start = .;
        *(.bss)
        __bss_end = .;
    }
}
