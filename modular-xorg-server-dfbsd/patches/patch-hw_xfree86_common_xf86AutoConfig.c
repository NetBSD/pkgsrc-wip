$NetBSD: patch-hw_xfree86_common_xf86AutoConfig.c,v 1.3 2018/10/26 10:20:12 maya Exp $

Patches from NetBSD xsrc 1.20.5:

Apr 13 16:00:38 2011 UTC

- get platform #ifdefs in a slightly more sane order
- look for SBus and UPA devices on sparc(64)
- add default drivers for shark and sgimips
- only try wsfb if we can't find any other usable device
With this Xorg without config file works fine on shark, sparc(74) and amd64
should work on other archs as well.

Jan 28 11:50:00 2019

Try the modesetting driver before wsfb on NetBSD arm and aarch64

Patches from FreeBSD ports /DragonFly dports for x11-servers/xorg-server 1.18.4.

Add option for modesetting driver.

Add option for scfb driver.

NetBSD pkgsrc:
Look for wsfb on netbsd (needed by genfb)

--- hw/xfree86/common/xf86AutoConfig.c.orig	2019-05-30 18:27:34.000000000 +0000
+++ hw/xfree86/common/xf86AutoConfig.c
@@ -51,6 +51,13 @@
 #include <ctype.h>
 #endif
 
+#ifdef __NetBSD__
+#if defined(__sparc__) || defined(__sparc64__)
+#include <dev/sun/fbio.h>
+extern struct sbus_devtable sbusDeviceTable[];
+#endif /* sparc / sparc64 */
+#endif /* NetBSD */
+
 /* Sections for the default built-in configuration. */
 
 #define BUILTIN_DEVICE_NAME \
@@ -229,6 +236,46 @@ listPossibleVideoDrivers(XF86MatchedDriv
 {
     md->nmatches = 0;
 
+/* XXXMRG:  xorg-server 1.10/1.18 -- merge into xf86PlatformMatchDriver()? */
+#ifdef __NetBSD__
+#if defined(__shark)
+    xf86AddMatchedDriver(md, "chips");
+    xf86AddMatchedDriver(md, "igs");
+#elif defined(__sgimips)
+    xf86AddMatchedDriver(md, "crime");
+    xf86AddMatchedDriver(md, "newport");
+#elif defined(__sparc) || defined(__sparc64)
+    /* dig through /dev/fb* */
+    {
+    	struct fbtype fbt;
+	int j = 0, fd = 0, dev;
+	char fbpath[32];
+
+	for (j = 0; j < 10; j++) {
+	    snprintf(fbpath, 31, "/dev/fb%d", j);
+	    xf86Msg(X_ERROR,"%s: trying %s\n", __func__, fbpath);
+	    fd = open(fbpath, O_RDONLY, 0);
+	    if (fd == -1) continue;
+	    memset(&fbt, 0, sizeof(fbt));
+	    if (ioctl(fd, FBIOGTYPE, &fbt) == -1) {
+	    	close(fd);
+		continue;
+	    }
+	    close(fd);
+	    dev = 0;
+	    while ((sbusDeviceTable[dev].fbType != 0) &&
+	           (sbusDeviceTable[dev].fbType != fbt.fb_type))
+		dev++;
+	    if (sbusDeviceTable[dev].fbType == fbt.fb_type) {
+		xf86Msg(X_ERROR,"%s: found %s\n", __func__,
+		    sbusDeviceTable[dev].driverName);
+	        xf86AddMatchedDriver(md, sbusDeviceTable[dev].driverName);
+	    }
+	}
+    }
+#endif
+
+#else /* !NetBSD */
 #ifdef XSERVER_PLATFORM_BUS
     xf86PlatformMatchDriver(md);
 #endif
@@ -290,20 +337,27 @@ listPossibleVideoDrivers(XF86MatchedDriv
     if (sbusDriver)
         xf86AddMatchedDriver(md, sbusDriver);
 #endif
+#endif /* NetBSD */
 #ifdef XSERVER_LIBPCIACCESS
     xf86PciMatchDriver(md);
 #endif
 
 #if defined(__linux__)
     xf86AddMatchedDriver(md, "modesetting");
+#elif defined(__NetBSD__) && (defined(__aarch64__) || defined(__arm__))
+    xf86AddMatchedDriver(md, "modesetting");
+#elif defined(ADD_MODESETTING_DRIVER)
+    xf86AddMatchedDriver(md, "modesetting");
 #endif
 
 #if !defined(__sun)
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
 
@@ -312,6 +366,11 @@ listPossibleVideoDrivers(XF86MatchedDriv
     xf86AddMatchedDriver(md, "vesa");
 #elif defined(__sparc__) && !defined(__sun)
     xf86AddMatchedDriver(md, "sunffb");
+#elif defined(__NetBSD__) && !defined(ALWAYS_ADD_WSFB)
+    xf86AddMatchedDriver(md, "wsfb");
+#endif
+#if defined(__NetBSD__) && defined(ALWAYS_ADD_WSFB)
+    xf86AddMatchedDriver(md, "wsfb");
 #endif
 }
 
