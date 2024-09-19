$NetBSD$

FreeBSD ports / DragonFly dports x11-drivers/xf86-input-keyboard.
Close device file for keyboards which are not attached
to console, otherwise they can't be opened again after
relogin when using session manager like xdm.

--- src/kbd.c.orig	2016-05-30 21:35:35.000000000 +0000
+++ src/kbd.c
@@ -25,6 +25,9 @@
 
 #include "xf86.h"
 #include "atKeynames.h"
+#if (defined(__FreeBSD__) && __FreeBSD__ >= 11) || defined(__DragonFly__)
+#include "xf86Priv.h"
+#endif
 #include "xf86Privstr.h"
 
 #include <X11/extensions/XI.h>
@@ -382,6 +385,16 @@ KbdProc(DeviceIntPtr device, int what)
     }
     pKbd->KbdOff(pInfo, what);
     device->public.on = FALSE;
+#if (defined(__FreeBSD__) && __FreeBSD__ >= 11) || defined(__DragonFly__)
+	/*
+	 * Close device file for keyboards which are not attached
+	 * to console, otherwise they can't be opened again after
+	 * relogin when using session manager like xdm.
+	 * X server will take care about console attached keyboards.
+	 */
+	if (pInfo->fd != xf86Info.consoleFd)
+		close(pInfo->fd);
+#endif
     break;
 
   default:
