$NetBSD$

--- arch/arm/include/asm/arch-sunxi/gpio.h.orig	2018-11-14 16:10:06.000000000 +0000
+++ arch/arm/include/asm/arch-sunxi/gpio.h
@@ -176,6 +176,7 @@ enum sunxi_gpio_number {
 
 #define SUN5I_GPE_SDC2		3
 #define SUN8I_GPE_TWI2		3
+#define SUN8I_V3S_GPE_LCD	3
 
 #define SUNXI_GPF_SDC0		2
 #define SUNXI_GPF_UART0		4
