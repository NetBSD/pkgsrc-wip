$NetBSD$

--- hw/xfree86/modes/xf86RandR12.c.orig	2019-03-05 16:34:21.000000000 +0000
+++ hw/xfree86/modes/xf86RandR12.c
@@ -825,6 +825,9 @@ xf86RandR12CreateScreenResources(ScreenP
         pScreen->width = width;
         pScreen->height = height;
         xf86RandR12ScreenSetSize(pScreen, width, height, mmWidth, mmHeight);
+#if defined(OPENBSD_MORE_CALLS)
+        xf86ReconfigureLayout();
+#endif
     }
 
     if (randrp->virtualX == -1 || randrp->virtualY == -1) {
