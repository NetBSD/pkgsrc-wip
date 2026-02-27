$NetBSD$

--- drivers/video/sunxi/sunxi_de2.c.orig	2024-03-30 08:20:35.015895055 +0000
+++ drivers/video/sunxi/sunxi_de2.c
@@ -25,8 +25,13 @@ DECLARE_GLOBAL_DATA_PTR;
 
 enum {
 	/* Maximum LCD size we support */
+#ifdef CONFIG_MACH_SUN8I_V3S
+	LCD_MAX_WIDTH		= 1024,
+	LCD_MAX_HEIGHT		= 1024,
+#else
 	LCD_MAX_WIDTH		= 3840,
 	LCD_MAX_HEIGHT		= 2160,
+#endif
 	LCD_MAX_LOG2_BPP	= VIDEO_BPP32,
 };
 
@@ -44,11 +49,19 @@ static void sunxi_de2_composer_init(void
 	writel(reg_value, SUNXI_SRAMC_BASE + 0x04);
 #endif
 
+#ifdef CONFIG_MACH_SUN8I_V3S
+	clock_set_pll3(50000000);
+	/* pll3 is also used for pixelclock and speed will be recomputed */
+	/* Set DE parent to pll3 */
+	clrsetbits_le32(&ccm->de_clk_cfg, CCM_DE2_CTRL_PLL_MASK,
+			CCM_DE2_CTRL_PLL3_V3S);
+#else
 	clock_set_pll10(432000000);
 
 	/* Set DE parent to pll10 */
 	clrsetbits_le32(&ccm->de_clk_cfg, CCM_DE2_CTRL_PLL_MASK,
 			CCM_DE2_CTRL_PLL10);
+#endif
 
 	/* Set ahb gating to pass */
 	setbits_le32(&ccm->ahb_reset1_cfg, 1 << AHB_RESET_OFFSET_DE);
@@ -74,7 +87,8 @@ static void sunxi_de2_mode_set(int mux, 
 	struct de_ui * const de_ui_regs =
 		(struct de_ui *)(de_mux_base +
 				 SUNXI_DE2_MUX_CHAN_REGS +
-				 SUNXI_DE2_MUX_CHAN_SZ * 1);
+				 SUNXI_DE2_MUX_CHAN_SZ *
+				 (IS_ENABLED(CONFIG_MACH_SUN8I_V3S) ? 2 : 1));
 	struct de_csc * const de_csc_regs =
 		(struct de_csc *)(de_mux_base +
 				  SUNXI_DE2_MUX_DCSC_REGS);
@@ -101,14 +115,15 @@ static void sunxi_de2_mode_set(int mux, 
 	for (channel = 0; channel < 4; channel++) {
 		void *ch = (void *)(de_mux_base + SUNXI_DE2_MUX_CHAN_REGS +
 				    SUNXI_DE2_MUX_CHAN_SZ * channel);
-		memset(ch, 0, (channel == 0) ?
+		memset(ch, 0, (channel == 0 ||
+			       (IS_ENABLED(CONFIG_MACH_SUN8I_V3S) && channel == 1)) ?
 			sizeof(struct de_vi) : sizeof(struct de_ui));
 	}
 	memset(de_bld_regs, 0, sizeof(struct de_bld));
 
 	writel(0x00000101, &de_bld_regs->fcolor_ctl);
 
-	writel(1, &de_bld_regs->route);
+	writel(IS_ENABLED(CONFIG_MACH_SUN8I_V3S) ? 2 : 1, &de_bld_regs->route);
 
 	writel(0, &de_bld_regs->premultiply);
 	writel(0xff000000, &de_bld_regs->bkcolor);
