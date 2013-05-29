$NetBSD: patch-src_i830__debug.c,v 1.1 2013/05/29 03:38:09 makoto Exp $

git clone git://cgit.freedesktop.org/xorg/driver/xf86-video-intel/
git checkout e4cd9de2933ada3e2a4b43552729ae3a370128bf
and make diff

--- src/i830_debug.c.orig	2009-05-13 00:12:11.000000000 +0000
+++ src/i830_debug.c
@@ -53,6 +53,33 @@ DEBUGSTRING(i830_16bit_func)
     return XNFprintf("0x%04x", (uint16_t)val);
 }
 
+DEBUGSTRING(i830_debug_dcc)
+{
+    char *addressing = NULL;
+
+    if (!IS_MOBILE(pI830))
+	return NULL;
+
+    if (IS_I965G(pI830)) {
+	if (val & (1 << 1))
+	    addressing = "dual channel interleaved";
+	else
+	    addressing = "single or dual channel asymmetric";
+    } else {
+	switch (val & 3) {
+	case 0: addressing = "single channel"; break;
+	case 1: addressing = "dual channel asymmetric"; break;
+	case 2: addressing = "dual channel interleaved"; break;
+	case 3: addressing = "unknown channel layout"; break;
+	}
+    }
+
+    return XNFprintf("%s, XOR randomization: %sabled, XOR bit: %d",
+		     addressing,
+		     (val & (1 << 10)) ? "dis" : "en",
+		     (val & (1 << 9)) ? 17 : 11);
+}
+
 DEBUGSTRING(i830_debug_chdecmisc)
 {
     char *enhmodesel = NULL;
@@ -503,24 +530,48 @@ DEBUGSTRING(i830_debug_dspclk_gate_d)
 		      OVLUNIT);
 }
 
-#if 1
-DEBUGSTRING(i810_debug_fence_start)
+
+DEBUGSTRING(i810_debug_915_fence)
+{
+    char *enable = (val & 1) ? " enabled" : "disabled";
+    char format = (val & 1 << 12) ? 'Y' : 'X';
+    int pitch = 1 << (((val & 0x70) >> 4) - 1);
+    unsigned int offset = val & 0x0ff00000;
+    int size = (1024 * 1024) << (((val & 0x700) >> 8) - 1);
+
+    if (IS_I965G(pI830) || ((IS_I915G(pI830) || IS_I915GM(pI830)) && reg >= FENCE_NEW))
+	return NULL;
+
+    if (format == 'X')
+      pitch *= 4;
+
+    return XNFprintf("%s, %c tiled, %4d pitch, 0x%08x - 0x%08x (%dkb)",
+		     enable, format, pitch, offset, offset + size, size / 1024);
+}
+
+DEBUGSTRING(i810_debug_965_fence_start)
 {
     char *enable = (val & FENCE_VALID) ? " enabled" : "disabled";
     char format = (val & I965_FENCE_Y_MAJOR) ? 'Y' : 'X';
     int pitch = ((val & 0xffc) >> 2) * 128;
     unsigned int offset = val & 0xfffff000;
 
+    if (!IS_I965G(pI830))
+	return NULL;
+
     return XNFprintf("%s, %c tile walk, %4d pitch, 0x%08x start",
 		     enable, format, pitch, offset);
 }
-DEBUGSTRING(i810_debug_fence_end)
+
+DEBUGSTRING(i810_debug_965_fence_end)
 {
     unsigned int end = val & 0xfffff000;
 
+    if (!IS_I965G(pI830))
+	return NULL;
+
     return XNFprintf("                                   0x%08x end", end);
 }
-#endif
 
 #define DEFINEREG(reg) \
 	{ reg, #reg, NULL, 0 }
@@ -535,6 +586,7 @@ static struct i830SnapshotRec {
     char *(*debug_output)(I830Ptr pI830, int reg, uint32_t val);
     uint32_t val;
 } i830_snapshot[] = {
+    DEFINEREG2(DCC, i830_debug_dcc),
     DEFINEREG2(CHDECMISC, i830_debug_chdecmisc),
     DEFINEREG_16BIT(C0DRB0),
     DEFINEREG_16BIT(C0DRB1),
@@ -549,6 +601,8 @@ static struct i830SnapshotRec {
     DEFINEREG_16BIT(C1DRA01),
     DEFINEREG_16BIT(C1DRA23),
 
+    DEFINEREG(PGETBL_CTL),
+
     DEFINEREG2(VCLK_DIVISOR_VGA0, i830_debug_fp),
     DEFINEREG2(VCLK_DIVISOR_VGA1, i830_debug_fp),
     DEFINEREG2(VCLK_POST_DIV, i830_debug_vga_pd),
@@ -715,27 +769,48 @@ static struct i830SnapshotRec {
     DEFINEREG(DPD_AUX_CH_DATA4),
     DEFINEREG(DPD_AUX_CH_DATA5),
 
-#define DEFINEFENCE(i) \
-	{ FENCE_NEW+i*8, "FENCE START " #i, i810_debug_fence_start, 0 }, \
-	{ FENCE_NEW+i*8+4, "FENCE END " #i, i810_debug_fence_end, 0 }
-#if 1
-    DEFINEFENCE(0),
-    DEFINEFENCE(1),
-    DEFINEFENCE(2),
-    DEFINEFENCE(3),
-    DEFINEFENCE(4),
-    DEFINEFENCE(5),
-    DEFINEFENCE(6),
-    DEFINEFENCE(7),
-    DEFINEFENCE(8),
-    DEFINEFENCE(9),
-    DEFINEFENCE(10),
-    DEFINEFENCE(11),
-    DEFINEFENCE(12),
-    DEFINEFENCE(13),
-    DEFINEFENCE(14),
-    DEFINEFENCE(15),
-#endif
+#define DEFINEFENCE_915(i) \
+	{ FENCE+i*4, "FENCE  " #i, i810_debug_915_fence, 0 }
+#define DEFINEFENCE_945(i)						\
+	{ FENCE_NEW+(i - 8) * 4, "FENCE  " #i, i810_debug_915_fence, 0 }
+
+    DEFINEFENCE_915(0),
+    DEFINEFENCE_915(1),
+    DEFINEFENCE_915(2),
+    DEFINEFENCE_915(3),
+    DEFINEFENCE_915(4),
+    DEFINEFENCE_915(5),
+    DEFINEFENCE_915(6),
+    DEFINEFENCE_915(7),
+    DEFINEFENCE_945(8),
+    DEFINEFENCE_945(9),
+    DEFINEFENCE_945(10),
+    DEFINEFENCE_945(11),
+    DEFINEFENCE_945(12),
+    DEFINEFENCE_945(13),
+    DEFINEFENCE_945(14),
+    DEFINEFENCE_945(15),
+
+#define DEFINEFENCE_965(i) \
+	{ FENCE_NEW+i*8, "FENCE START " #i, i810_debug_965_fence_start, 0 }, \
+	{ FENCE_NEW+i*8+4, "FENCE END " #i, i810_debug_965_fence_end, 0 }
+
+    DEFINEFENCE_965(0),
+    DEFINEFENCE_965(1),
+    DEFINEFENCE_965(2),
+    DEFINEFENCE_965(3),
+    DEFINEFENCE_965(4),
+    DEFINEFENCE_965(5),
+    DEFINEFENCE_965(6),
+    DEFINEFENCE_965(7),
+    DEFINEFENCE_965(8),
+    DEFINEFENCE_965(9),
+    DEFINEFENCE_965(10),
+    DEFINEFENCE_965(11),
+    DEFINEFENCE_965(12),
+    DEFINEFENCE_965(13),
+    DEFINEFENCE_965(14),
+    DEFINEFENCE_965(15),
 };
 #undef DEFINEREG
 #define NUM_I830_SNAPSHOTREGS (sizeof(i830_snapshot) / sizeof(i830_snapshot[0]))
@@ -853,9 +928,11 @@ void i830DumpRegs (ScrnInfoPtr pScrn)
 	    char *debug = i830_snapshot[i].debug_output(pI830,
 							i830_snapshot[i].reg,
 							val);
-	    xf86DrvMsg (pScrn->scrnIndex, X_INFO, "%20.20s: 0x%08x (%s)\n",
-			i830_snapshot[i].name, (unsigned int)val, debug);
-	    xfree(debug);
+	    if (debug != NULL) {
+		xf86DrvMsg (pScrn->scrnIndex, X_INFO, "%20.20s: 0x%08x (%s)\n",
+			    i830_snapshot[i].name, (unsigned int)val, debug);
+		xfree(debug);
+	    }
 	} else {
 	    xf86DrvMsg (pScrn->scrnIndex, X_INFO, "%20.20s: 0x%08x\n",
 			i830_snapshot[i].name, (unsigned int)val);
