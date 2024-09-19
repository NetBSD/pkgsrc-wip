$NetBSD$

From NetBSD xsrc:

Jul 9 22:19:34 2016 UTC

Avoid legacy VGA I/O port access on MIPS.  Xorg converts the I/O port
address to a pointer and dereferences it, and then seg faults.

--- hw/xfree86/vgahw/vgaHW.h.orig	2019-05-30 18:27:34.000000000 +0000
+++ hw/xfree86/vgahw/vgaHW.h
@@ -168,11 +168,15 @@ typedef struct _vgaHWRec {
 #define BITS_PER_GUN 6
 #define COLORMAP_SIZE 256
 
+#if defined(__NetBSD__) && (defined(__powerpc__) || defined(__arm__) || defined(__mips__) || defined(__s390__) || defined(__nds32__))
+#define DACDelay(hw) /* No legacy VGA support */
+#else
 #define DACDelay(hw) \
 	do { \
 	    (hw)->readST01((hw)); \
 	    (hw)->readST01((hw)); \
 	} while (0)
+#endif
 
 /* Function Prototypes */
 
