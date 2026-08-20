$NetBSD: patch-hw_xfree86_common_xf86AutoConfig.c,v 1.4 2019/12/10 17:27:05 nia Exp $

https://github.com/NetBSD/xsrc/commit/38ac2ddeea11ea3a612c616447d191f685781f88.patch
https://github.com/NetBSD/xsrc/commit/38ac2ddeea11ea3a612c616447d191f685781f88.patch

--- hw/xfree86/common/xf86AutoConfig.c.orig	2026-08-20 01:02:10.000000000 +0000
+++ hw/xfree86/common/xf86AutoConfig.c
@@ -306,12 +306,22 @@ listPossibleVideoDrivers(XF86MatchedDrivers *md)
     xf86AddMatchedDriver(md, "scfb");
 #endif
 
+#if defined(__NetBSD__) && \
+    (defined(__aarch64__) || defined(__arm__) || \
+     defined(__i386__) || defined(__amd64__))
+    xf86AddMatchedDriver(md, "modesetting");
+#endif
+
     /* Fallback to platform default hardware */
 #if defined(__i386__) || defined(__amd64__) || defined(__hurd__)
     xf86AddMatchedDriver(md, "vesa");
 #elif defined(__sparc__) && !defined(__sun)
     xf86AddMatchedDriver(md, "sunffb");
 #endif
+#if defined(__NetBSD__)
+    xf86AddMatchedDriver(md, "wsfb");
+#endif
+
 
 #if defined(__NetBSD__) || defined(__OpenBSD__)
     xf86AddMatchedDriver(md, "wsfb");
