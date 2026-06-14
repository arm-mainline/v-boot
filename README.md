v-boot

A lightweight, custom-engineered secondary bootloader for ARM mobile devices.
👋 Who We Are

We are Uras and Mami, two 11-year-old 5th-grade students from Turkey. We have a deep passion for embedded systems, low-level programming, and hardware hacking. Despite our age, we are dedicated to exploring the depths of ARM architecture and contributing to the open-source community by building tools that bring freedom to locked-down mobile hardware. v-boot is our journey into understanding how mobile devices come to life.
💡 Engineering Philosophy

v-boot is a lightweight, custom-engineered secondary bootloader designed to provide native Fastboot and Recovery booting capabilities on ARM32 and ARM64 mobile platforms.

We are deeply inspired by the lk2nd project's robust design and hardware abstraction patterns. However, v-boot is a clean-room implementation, developed to offer a minimal, high-performance environment for bringing up mainline Linux kernels. We do not use bloated payloads (like EDK2 or U-Boot); instead, we rely on a custom, streamlined boot flow that communicates directly with the hardware.
🚀 Key Features

    Custom Fastboot & Recovery: Full, hand-written control over the boot process, enabling custom Fastboot commands and recovery partition handling.

    Mainline-First Approach: We utilize Mainline Kernel Device Trees as the "source of truth," ensuring our bootloader aligns perfectly with upstream Linux developments.

    Zero Payload Overhead: No UEFI/EDK2 bloat. The logic is native, lightweight, and tightly integrated for maximum performance.

    Dual Architecture Support: Engineered to handle both legacy ARM32 (ARMv7) and modern ARM64 (ARMv8) SoCs.

    Education & Openness: We document our process to help other young developers learn how mobile boot chains work.

🛠️ Boot Flow Architecture

v-boot acts as a direct, lightweight bridge between the vendor's primary bootloader and the Linux environment:
Plaintext

[PBL] -> [SBL/ABOOT] -> [v-boot (Custom)] -> [Linux Kernel]

🏗️ Getting Started
git clone https://github.com/little-arm-mainline/v-boot
# Build instructions and prerequisites will be added soon.


📜 License

This project is licensed under the GPL-3.0 License.
Neden bu şekilde oldu?
