$NetBSD$

--- hw/xfree86/os-support/bus/bsd_pci.c.orig	2019-03-05 16:34:21.000000000 +0000
+++ hw/xfree86/os-support/bus/bsd_pci.c
@@ -51,5 +51,8 @@
 void
 osPciInit(void)
 {
+#if defined(OPENBSD_MORE_CALLS)
+    xf86OpenConsole();
+#endif
     xf86InitVidMem();
 }
