$NetBSD$

--- hw/xfree86/common/xf86str.h.orig	2019-05-30 18:27:34.000000000 +0000
+++ hw/xfree86/common/xf86str.h
@@ -261,6 +261,9 @@ typedef enum {
     BUS_NONE,
     BUS_PCI,
     BUS_SBUS,
+#if defined(__NetBSD__)
+    BUS_ISA,
+#endif
     BUS_PLATFORM,
     BUS_last                    /* Keep last */
 } BusType;
