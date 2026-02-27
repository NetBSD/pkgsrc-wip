$NetBSD$

--- drivers/video/sunxi/sunxi_dw_hdmi.c.orig	2024-03-30 08:20:35.016849087 +0000
+++ drivers/video/sunxi/sunxi_dw_hdmi.c
@@ -379,6 +379,8 @@ U_BOOT_DRIVER(sunxi_dw_hdmi) = {
 	.priv_auto_alloc_size = sizeof(struct sunxi_dw_hdmi_priv),
 };
 
+#ifndef CONFIG_MACH_SUN8I_V3S
 U_BOOT_DEVICE(sunxi_dw_hdmi) = {
 	.name = "sunxi_dw_hdmi"
 };
+#endif
