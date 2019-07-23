$NetBSD: patch-src_emuwheel.c,v 1.1 2015/12/18 11:19:12 taca Exp $

* Fix build problem NetBSD 7.0_STABLE.

OpenBSD xenocara:

Jun 18 20:07:30 2018 UTC
* Improve the wheel emulation logic.  Make the axis filtering symmetrical,
and less restrictive for vertical scrolling.

--- src/emuwheel.c.orig	2012-07-08 13:51:11.000000000 +0000
+++ src/emuwheel.c
@@ -36,6 +36,8 @@
 #include "config.h"
 #endif
 
+#include <sys/time.h>
+
 #include <xorg-server.h>
 #include <X11/Xatom.h>
 #include <xf86.h>
@@ -113,7 +115,11 @@ wsWheelEmuFilterMotion(InputInfoPtr pInf
 				return TRUE;
 		}
 
+#if defined(STRICT_XENOCARA_OPENBSD)
+		if (abs(dx) > abs(dy)) {
+#else
 		if (dx) {
+#endif
 			pAxis = &(priv->emulateWheel.X);
 			pOtherAxis = &(priv->emulateWheel.Y);
 			value = dx;
