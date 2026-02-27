$NetBSD$

--- arch/arm/include/asm/arch-sunxi/clock_sun6i.h.orig	2018-11-14 16:10:06.000000000 +0000
+++ arch/arm/include/asm/arch-sunxi/clock_sun6i.h
@@ -329,7 +329,7 @@ struct sunxi_ccm_reg {
 #define AHB_GATE_OFFSET_DE		12
 #define AHB_GATE_OFFSET_HDMI		11
 #define AHB_GATE_OFFSET_TVE		9
-#ifndef CONFIG_SUNXI_DE2
+#if !defined(CONFIG_SUNXI_DE2) || defined(CONFIG_MACH_SUN8I_V3S)
 #define AHB_GATE_OFFSET_LCD1		5
 #define AHB_GATE_OFFSET_LCD0		4
 #else
@@ -476,7 +476,7 @@ struct sunxi_ccm_reg {
 #define AHB_RESET_OFFSET_HDMI		11
 #define AHB_RESET_OFFSET_HDMI2		10
 #define AHB_RESET_OFFSET_TVE		9
-#ifndef CONFIG_SUNXI_DE2
+#if !defined(CONFIG_SUNXI_DE2) || defined(CONFIG_MACH_SUN8I_V3S)
 #define AHB_RESET_OFFSET_LCD1		5
 #define AHB_RESET_OFFSET_LCD0		4
 #else
@@ -508,6 +508,7 @@ struct sunxi_ccm_reg {
 /* CCM bits common to all Display Engine 2.0 clock ctrl regs */
 #define CCM_DE2_CTRL_M(n)		((((n) - 1) & 0xf) << 0)
 #define CCM_DE2_CTRL_PLL_MASK		(3 << 24)
+#define CCM_DE2_CTRL_PLL3_V3S		(0 << 24)
 #define CCM_DE2_CTRL_PLL6_2X		(0 << 24)
 #define CCM_DE2_CTRL_PLL10		(1 << 24)
 #define CCM_DE2_CTRL_GATE		(0x1 << 31)
