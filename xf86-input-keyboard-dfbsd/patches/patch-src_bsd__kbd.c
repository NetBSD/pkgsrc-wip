$NetBSD$

* DragonFly has on a specific machine some timing problem at SetKbdLeds.
Try a random sleep before calling it.

Patch from FreeBSD ports / DragonFly dports x11-drivers/xf86-input-keyboard.

* Switch keyboards which are not attached to console to RAW mode.

Patches from NetBSD xsrc:
Scancode translation table for wskbd on Amiga keyboards.

--- src/bsd_kbd.c.orig	2013-10-28 00:44:23.000000000 +0000
+++ src/bsd_kbd.c
@@ -27,6 +27,11 @@
 #include "atKeynames.h"
 #include "bsd_kbd.h"
 
+#if defined(DELAY_KDSETLED)
+#include <unistd.h>
+#include <stdlib.h>
+#endif
+
 static KbdProtocolRec protocols[] = {
    {"standard", PROT_STD },
 #ifdef WSCONS_SUPPORT
@@ -104,7 +109,13 @@ SetKbdLeds(InputInfoPtr pInfo, int leds)
 #if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
 	case SYSCONS:
 	case PCVT:
+#if defined(DELAY_KDSETLED)
+             sleep(1 + (unsigned int)(0x03L && random()));
+#endif
 	     ioctl(pInfo->fd, KDSETLED, real_leds);
+#if defined(DELAY_KDSETLED)
+             sleep(1);
+#endif
 	     break;
 #endif
 #if defined(WSCONS_SUPPORT)
@@ -236,6 +247,14 @@ KbdOn(InputInfoPtr pInfo, int what)
 		break;
 #endif
 	}
+#if (defined(__FreeBSD__) && __FreeBSD__ >= 11) || defined(__DragonFly__)
+/*
+ * Switch keyboards which are not attached to console in RAW mode
+ */
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
+	ioctl(pInfo->fd, KDSKBMODE, K_RAW);
+#endif
+#endif
     }
     return Success;
 }
@@ -459,6 +478,11 @@ OpenKeyboard(InputInfoPtr pInfo)
                printWsType("ADB", pInfo->name);
                break;
 #endif
+#ifdef WSKBD_TYPE_AMIGA
+           case WSKBD_TYPE_AMIGA:
+               printWsType("Amiga", pInfo->name);
+               break;
+#endif
 #ifdef WSKBD_TYPE_LK201
            case WSKBD_TYPE_LK201:
                printWsType("LK201", pInfo->name);
