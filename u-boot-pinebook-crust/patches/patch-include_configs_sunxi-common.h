$NetBSD$

--- include/configs/sunxi-common.h.orig	2019-07-15 12:38:43.332852802 +0000
+++ include/configs/sunxi-common.h
@@ -416,7 +416,6 @@ extern int soft_i2c_gpio_scl;
 	BOOT_TARGET_DEVICES_MMC(func) \
 	BOOT_TARGET_DEVICES_SCSI(func) \
 	BOOT_TARGET_DEVICES_USB(func) \
-	func(PXE, pxe, na) \
 	func(DHCP, dhcp, na)
 
 #ifdef CONFIG_OLD_SUNXI_KERNEL_COMPAT
