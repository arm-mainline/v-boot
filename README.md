# v-boot

A lightweight secondary bootloader with a **Das U-Boot** payload designed for ARM32 and ARM64 platforms, specifically targeting legacy and mainline mobile devices (smartphones and tablets).
`v-boot` aims to bridge the gap between proprietary vendor bootloaders and standard Linux boot ecosystems without the massive overhead of EDK2.
---
## 💡 Inspiration

This project is deeply inspired by the **lk2nd** project. While `lk2nd` provides an amazing Fastboot interface and hardware initialization abstraction layer for Qualcomm devices, `v-boot` extends this philosophy by chainloading **Das U-Boot** directly as a payload, offering a fully standard, highly scriptable, and feature-rich Linux booting environment on mobile screens.
---
## 🚀 Key Features

* **Dual Architecture Support:** Designed from the ground up to support both legacy ARM32 (ARMv7, e.g., MSM8226) and modern ARM64 (ARMv8) mobile SoCs.
* **Zero UEFI Bloat:** Avoids the complexity and size of full UEFI environments (like EDK2) while maintaining native hardware access.
* **U-Boot Integration:** Leverages the power of Das U-Boot for standard boot scripts, modern file system support (ext4, btrfs, f2fs), and standard tools.
* **Display & Peripherals:** Early framebuffer initialization to give visual feedback directly on the smartphone/tablet panel.
* **Mainlining Helper:** Simplifies booting standard Linux distributions (like Arch Linux ARM, PostmarketOS, Debian) using standard standard boot configurations (`extlinux.conf`).
---

## 🛠️ Boot Flow Architecture
Unlike standard PCs, mobile ARM devices boot in chains. `v-boot` fits perfectly in the middle to bring freedom:
---
Uras and Mami vibe
