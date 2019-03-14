$NetBSD: patch-hw_xfree86_common_xf86AutoConfig.c,v 1.3 2018/10/26 10:20:12 maya Exp $

Patches from FreeBSD ports /DragonFly dports for x11-servers/xorg-server 1.18.4.

Add option for modesetting driver.

Add option for scfb driver.

Look for wsfb on netbsd (needed by genfb)

--- hw/xfree86/common/xf86AutoConfig.c.orig	2019-03-05 16:34:21.000000000 +0000
+++ hw/xfree86/common/xf86AutoConfig.c
@@ -294,7 +294,7 @@ listPossibleVideoDrivers(XF86MatchedDriv
     xf86PciMatchDriver(md);
 #endif
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(ADD_MODESETTING_DRIVER)
     xf86AddMatchedDriver(md, "modesetting");
 #endif
 
@@ -302,8 +302,10 @@ listPossibleVideoDrivers(XF86MatchedDriv
     /* Fallback to platform default frame buffer driver */
 #if !defined(__linux__) && defined(__sparc__)
     xf86AddMatchedDriver(md, "wsfb");
-#else
+#elif defined(__linux__)
     xf86AddMatchedDriver(md, "fbdev");
+#elif defined(ADD_SCFB_DRIVER)
+    xf86AddMatchedDriver(md, "scfb");
 #endif
 #endif                          /* !__sun */
 
@@ -313,6 +315,9 @@ listPossibleVideoDrivers(XF86MatchedDriv
 #elif defined(__sparc__) && !defined(__sun)
     xf86AddMatchedDriver(md, "sunffb");
 #endif
+#if defined(__NetBSD__)
+    xf86AddMatchedDriver(md, "wsfb");
+#endif
 }
 
 /* copy a screen section and enter the desired driver
