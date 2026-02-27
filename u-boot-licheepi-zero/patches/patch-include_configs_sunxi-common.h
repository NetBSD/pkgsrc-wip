$NetBSD$

--- include/configs/sunxi-common.h.orig	2024-08-31 05:16:31.758892211 +0000
+++ include/configs/sunxi-common.h
@@ -275,7 +275,11 @@ extern int soft_i2c_gpio_scl;
  * The amount of RAM to keep free at the top of RAM when relocating u-boot,
  * to use as framebuffer. This must be a multiple of 4096.
  */
+#ifdef CONFIG_MACH_SUN8I_V3S
+#define CONFIG_SUNXI_MAX_FB_SIZE (4 << 20)
+#else
 #define CONFIG_SUNXI_MAX_FB_SIZE (16 << 20)
+#endif
 
 #define CONFIG_VIDEO_LOGO
 #define CONFIG_VIDEO_STD_TIMINGS
