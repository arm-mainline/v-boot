#ifndef IO_H
#define IO_H

#define readl(addr) (*(volatile unsigned int *)(addr))
#define writel(v, addr) (*(volatile unsigned int *)(addr) = (v))

#endif
