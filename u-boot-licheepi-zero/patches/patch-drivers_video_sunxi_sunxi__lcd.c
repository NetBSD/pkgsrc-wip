$NetBSD$

--- drivers/video/sunxi/sunxi_lcd.c.orig	2024-03-30 08:20:35.017516490 +0000
+++ drivers/video/sunxi/sunxi_lcd.c
@@ -31,6 +31,13 @@ static void sunxi_lcdc_config_pinmux(voi
 		sunxi_gpio_set_cfgpin(pin, SUNXI_GPD_LCD0);
 		sunxi_gpio_set_drv(pin, 3);
 	}
+#elif defined(CONFIG_MACH_SUN8I_V3S)
+	int pin;
+
+	for (pin = SUNXI_GPE(0); pin <= SUNXI_GPE(19); pin++)
+		sunxi_gpio_set_cfgpin(pin, SUN8I_V3S_GPE_LCD);
+	sunxi_gpio_set_cfgpin(SUNXI_GPE(23), SUN8I_V3S_GPE_LCD);
+	sunxi_gpio_set_cfgpin(SUNXI_GPE(24), SUN8I_V3S_GPE_LCD);
 #endif
 }
 
@@ -144,7 +151,7 @@ U_BOOT_DRIVER(sunxi_lcd) = {
 	.priv_auto_alloc_size = sizeof(struct sunxi_lcd_priv),
 };
 
-#ifdef CONFIG_MACH_SUN50I
+#if defined(CONFIG_MACH_SUN50I) || defined(CONFIG_MACH_SUN8I_V3S)
 U_BOOT_DEVICE(sunxi_lcd) = {
 	.name = "sunxi_lcd"
 };
