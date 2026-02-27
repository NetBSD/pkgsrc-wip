$NetBSD$

--- drivers/video/sunxi/lcdc.c.orig	2024-03-30 08:20:35.015098026 +0000
+++ drivers/video/sunxi/lcdc.c
@@ -236,7 +236,7 @@ void lcdc_pll_set(struct sunxi_ccm_reg *
 	 * not sync to higher frequencies.
 	 */
 	for (m = min_m; m <= max_m; m++) {
-#ifndef CONFIG_SUNXI_DE2
+#if !defined(CONFIG_SUNXI_DE2) || defined(CONFIG_MACH_SUN8I_V3S)
 		n = (m * dotclock) / 3000;
 
 		if ((n >= 9) && (n <= 127)) {
@@ -254,7 +254,7 @@ void lcdc_pll_set(struct sunxi_ccm_reg *
 		if (!(m & 1))
 			continue;
 #endif
-
+#ifndef CONFIG_MACH_SUN8I_V3S
 		/* No double clock on DE2 */
 		n = (m * dotclock) / 6000;
 		if ((n >= 9) && (n <= 127)) {
@@ -267,6 +267,7 @@ void lcdc_pll_set(struct sunxi_ccm_reg *
 				best_double = 1;
 			}
 		}
+#endif
 	}
 
 #ifdef CONFIG_MACH_SUN6I
