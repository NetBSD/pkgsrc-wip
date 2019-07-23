$NetBSD: patch-src_emumb.c,v 1.1 2015/12/18 11:19:12 taca Exp $

* Fix build problem NetBSD 7.0_STABLE.

* fix various errors and warnings with xorg-server 1.20:

Option to skip property if keyboard

--- src/emumb.c.orig	2012-07-08 14:22:03.000000000 +0000
+++ src/emumb.c
@@ -36,6 +36,11 @@
 #include "config.h"
 #endif
 
+#if defined(STRICT_XSRC_NETBSD)
+#include <sys/types.h>
+#endif
+#include <sys/time.h>
+
 #include <xorg-server.h>
 #include <X11/Xatom.h>
 #include <xf86.h>
@@ -273,7 +278,17 @@ wsmbEmuFilterEvent(InputInfoPtr pInfo, i
 }
 
 void
+#if defined(STRICT_XSRC_NETBSD)
+wsmbEmuWakeupHandler(pointer data,
+/* XXX compat-api.h */
+    int i
+#if ABI_VIDEODRV_VERSION < SET_ABI_VERSION(23, 0)
+    , pointer LastSelectMask
+#endif
+    )
+#else /* !STRICT_XSRC_NETBSD */
 wsmbEmuWakeupHandler(pointer data, int i, pointer LastSelectMask)
+#endif /* STRICT_XSRC_NETBSD */
 {
 	InputInfoPtr pInfo = (InputInfoPtr)data;
 	WSDevicePtr priv = (WSDevicePtr)pInfo->private;
@@ -287,8 +302,16 @@ wsmbEmuWakeupHandler(pointer data, int i
 }
 
 void
+#if defined(STRICT_XSRC_NETBSD)
+wsmbEmuBlockHandler(pointer data,
+#if ABI_VIDEODRV_VERSION < SET_ABI_VERSION(23, 0)
+    struct timeval **waitTime,
+#endif
+    pointer LastSelectMask)
+#else /* !STRICT_XSRC_NETBSD */
 wsmbEmuBlockHandler(pointer data, struct timeval **waitTime,
     pointer LastSelectMask)
+#endif /* STRICT_XSRC_NETBSD */
 {
 	InputInfoPtr pInfo = (InputInfoPtr)data;
 	WSDevicePtr priv = (WSDevicePtr)pInfo->private;
@@ -298,7 +321,11 @@ wsmbEmuBlockHandler(pointer data, struct
 		ms = priv->emulateMB.expires - GetTimeInMillis();
 		if (ms <= 0)
 			ms = 0;
+#if defined(STRICT_XSRC_NETBSD)
+#if ABI_VIDEODRV_VERSION < SET_ABI_VERSION(23, 0)
 		AdjustWaitForDelay(waitTime, ms);
+#endif
+#endif
 	}
 }
 
@@ -391,6 +418,11 @@ wsmbEmuInitProperty(DeviceIntPtr dev)
 
 	DBG(1, ErrorF("wsmbEmuInitProperty\n"));
 
+#if defined(KEYBOARD_BUTTON_XSRC_NETBSD)
+	if (!dev->button) /* don't init prop for keyboards */
+		return;
+#endif
+
 	prop_mbemu = MakeAtom(WS_PROP_MIDBUTTON,
 	    strlen(WS_PROP_MIDBUTTON), TRUE);
 	rc = XIChangeDeviceProperty(dev, prop_mbemu, XA_INTEGER, 8,
