$NetBSD$

Misc change to support FIT_IMAGE_TINY. from crust-firmware/u-boot

--- common/spl/spl_fit.c.orig	2018-11-07 03:37:06.000000000 +0000
+++ common/spl/spl_fit.c
@@ -170,7 +170,6 @@ static int spl_load_fit_image(struct spl
 	void *src;
 	ulong overhead;
 	int nr_sectors;
-	int align_len = ARCH_DMA_MINALIGN - 1;
 	uint8_t image_comp = -1, type = -1;
 	const void *data;
 	bool external_data = false;
@@ -205,7 +204,7 @@ static int spl_load_fit_image(struct spl
 		if (fit_image_get_data_size(fit, node, &len))
 			return -ENOENT;
 
-		load_ptr = (load_addr + align_len) & ~align_len;
+		load_ptr = CONFIG_SYS_LOAD_ADDR;
 		length = len;
 
 		overhead = get_aligned_image_overhead(info, offset);
@@ -325,7 +324,16 @@ static int spl_fit_record_loadable(const
 static int spl_fit_image_get_os(const void *fit, int noffset, uint8_t *os)
 {
 #if CONFIG_IS_ENABLED(FIT_IMAGE_TINY)
-	return -ENOTSUPP;
+	const char *str;
+	int len;
+
+	str = fdt_getprop(fit, noffset, FIT_OS_PROP, &len);
+	if (str && !strcmp(str, "u-boot"))
+		*os = IH_OS_U_BOOT;
+	else
+		*os = IH_OS_INVALID;
+
+	return 0;
 #else
 	return fit_image_get_os(fit, noffset, os);
 #endif
@@ -451,7 +459,11 @@ int spl_load_simple_fit(struct spl_image
 	 * as a U-Boot image, if no OS-type has been declared.
 	 */
 	if (!spl_fit_image_get_os(fit, node, &spl_image->os))
+#if CONFIG_IS_ENABLED(FIT_IMAGE_TINY)
+		debug("Image OS is %d\n", spl_image->os);
+#else
 		debug("Image OS is %s\n", genimg_get_os_name(spl_image->os));
+#endif
 #if !defined(CONFIG_SPL_OS_BOOT)
 	else
 		spl_image->os = IH_OS_U_BOOT;
