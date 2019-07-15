$NetBSD$

Make SPL serial optional

--- include/spl.h.orig	2018-11-07 03:37:06.000000000 +0000
+++ include/spl.h
@@ -79,7 +79,11 @@ int spl_load_simple_fit(struct spl_image
 #define SPL_COPY_PAYLOAD_ONLY	1
 
 /* SPL common functions */
+#ifdef CONFIG_SPL_SERIAL_SUPPORT
 void preloader_console_init(void);
+#else
+static inline void preloader_console_init(void) {}
+#endif
 u32 spl_boot_device(void);
 u32 spl_boot_mode(const u32 boot_device);
 int spl_boot_partition(const u32 boot_device);
