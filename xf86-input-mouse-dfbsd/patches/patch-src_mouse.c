$NetBSD$

Patches from FreeBSD ports / DragonFly dports with include guards.
Support for different versions of system libusb headers.

--- src/mouse.c.orig	2016-09-06 03:53:31.000000000 +0000
+++ src/mouse.c
@@ -43,6 +43,13 @@
  * and to help limited dexterity persons
  */
 
+/* PKGSRC note: To support newer versions of DragonFly and FreeBSD,
+ * this file is patched using DragonFly dports
+ * x11-drivers/xf86-input-mouse/files/patch-src_mouse.c
+ * as of master commit 4f04bfe0ea83 ... Tue Jul 14 22:56:44 2015 -0700
+ * The patch's code is enclosed in include defined(FREEBSD_USB) while the
+ * original code is enclosed in include !defined(FREEBSD_USB).
+ */
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
@@ -304,13 +311,45 @@ MouseCommonOptions(InputInfoPtr pInfo)
 
     pMse = pInfo->private;
 
+#if !defined(FREEBSD_USB)
     pMse->buttons = xf86SetIntOption(pInfo->options, "Buttons", 0);
+#else
+    i = xf86SetIntOption(pInfo->options, "Buttons", 0);
+    if (i != 0)
+        pMse->buttons = i;
+#endif
     if (!pMse->buttons) {
         pMse->buttons = MSE_DFLTBUTTONS;
         buttons_from = X_DEFAULT;
     }
     origButtons = pMse->buttons;
 
+#if defined(FREEBSD_USB)
+    s = xf86SetStrOption(pInfo->options, "ButtonMapping", NULL);
+    if (s) {
+        int b, n = 0;
+        char *s1 = s;
+        /* keep getting numbers which are buttons */
+        while (s1 && n < MSE_MAXBUTTONS && (b = strtol(s1, &s1, 10)) != 0) {
+            /* check sanity for a button */
+            if (b < 0 || b > MSE_MAXBUTTONS) {
+                xf86Msg(X_WARNING,
+                        "ButtonMapping: Invalid button number = %d\n", b);
+                break;
+           };
+           pMse->buttonMap[n++] = 1 << (b-1);
+           if (b > pMse->buttons) pMse->buttons = b;
+        }
+        free(s);
+    }
+    /* get maximum of mapped buttons */
+    for (i = pMse->buttons-1; i >= 0; i--) {
+        int f = ffs (pMse->buttonMap[i]);
+        if (f > pMse->buttons)
+            pMse->buttons = f;
+    }
+#endif
+
     pMse->emulate3Buttons = xf86SetBoolOption(pInfo->options,
                                               "Emulate3Buttons", FALSE);
     if (!xf86FindOptionValue(pInfo->options,"Emulate3Buttons")) {
@@ -322,6 +361,10 @@ MouseCommonOptions(InputInfoPtr pInfo)
                                              "Emulate3Timeout", 50);
     if (pMse->emulate3Buttons || pMse->emulate3ButtonsSoft) {
         MessageType from = X_CONFIG;
+#if defined(FREEBSD_USB)
+       if (pMse->buttons < 3)
+            pMse->buttons = 3;
+#endif
         if (pMse->emulate3ButtonsSoft)
             from = X_DEFAULT;
         xf86Msg(from, "%s: Emulate3Buttons, Emulate3Timeout: %d\n",
@@ -329,6 +372,10 @@ MouseCommonOptions(InputInfoPtr pInfo)
     }
 
     pMse->chordMiddle = xf86SetBoolOption(pInfo->options, "ChordMiddle", FALSE);
+#if defined(FREEBSD_USB)
+    if (pMse->chordMiddle && pMse->buttons < 3)
+           pMse->buttons = 3;
+#endif
     pMse->flipXY = xf86SetBoolOption(pInfo->options, "FlipXY", FALSE);
     if (xf86SetBoolOption(pInfo->options, "InvX", FALSE)) {
         pMse->invX = -1;
@@ -339,7 +386,9 @@ MouseCommonOptions(InputInfoPtr pInfo)
     } else
         pMse->invY = 1;
     pMse->angleOffset = xf86SetIntOption(pInfo->options, "AngleOffset", 0);
-
+#if defined(FREEBSD_USB)
+    pMse->sensitivity = xf86SetRealOption(pInfo->options, "Sensitivity", 1.0);
+#endif
 
     if (pMse->pDragLock)
         free(pMse->pDragLock);
@@ -449,14 +498,25 @@ MouseCommonOptions(InputInfoPtr pInfo)
         free(s);
     }
 
+#if !defined(FREEBSD_USB)
     s = xf86SetStrOption(pInfo->options, "ZAxisMapping", "4 5");
+#else
+    s = xf86SetStrOption(pInfo->options, "ZAxisMapping",
+        pMse->hasZ ? ( pMse->hasW ? "4 5 6 7" : "4 5" ) : "off");
+#endif
     if (s) {
         int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
         char *msg = NULL;
 
         pMse->negativeZ = pMse->positiveZ = MSE_NOAXISMAP;
         pMse->negativeW = pMse->positiveW = MSE_NOAXISMAP;
+#if !defined(FREEBSD_USB)
         if (!xf86NameCmp(s, "x")) {
+#else
+        if (!xf86NameCmp(s, "off")) {
+            msg = xstrdup("off");
+        } else if (!xf86NameCmp(s, "x")) {
+#endif
             pMse->negativeZ = pMse->positiveZ = MSE_MAPTOX;
             msg = xstrdup("X axis");
         } else if (!xf86NameCmp(s, "y")) {
@@ -605,6 +665,7 @@ MouseCommonOptions(InputInfoPtr pInfo)
                 pInfo->name, wheelButton, pMse->wheelInertia,
                 pMse->wheelButtonTimeout);
     }
+#if !defined(FREEBSD_USB)
     s = xf86SetStrOption(pInfo->options, "ButtonMapping", NULL);
     if (s) {
        int b, n = 0;
@@ -628,6 +689,7 @@ MouseCommonOptions(InputInfoPtr pInfo)
         if (f > pMse->buttons)
             pMse->buttons = f;
     }
+#endif
     if (origButtons != pMse->buttons)
         buttons_from = X_CONFIG;
     xf86Msg(buttons_from, "%s: Buttons: %d\n", pInfo->name, pMse->buttons);
@@ -709,7 +771,9 @@ MouseHWOptions(InputInfoPtr pInfo)
     }
     pMse->sampleRate = xf86SetIntOption(pInfo->options, "SampleRate", 0);
     pMse->resolution = xf86SetIntOption(pInfo->options, "Resolution", 0);
+#if !defined(FREEBSD_USB)
     mPriv->sensitivity = xf86SetRealOption(pInfo->options, "Sensitivity", 1.0);
+#endif
 }
 
 static void
@@ -998,6 +1062,11 @@ MousePreInit(InputDriverPtr drv, InputIn
     for (i = 0; i < MSE_MAXBUTTONS; i++)
         pMse->buttonMap[i] = 1 << (i > 2 && i < MSE_MAXBUTTONS-4 ? i+4 : i);
 
+#if defined(FREEBSD_USB)
+    pMse->hasZ = 1;
+    pMse->hasW = 0;
+#endif
+
     protocol = MousePickProtocol(pInfo, device, protocol, &protocolID);
 
     if (!device)
@@ -2288,6 +2357,11 @@ MouseDoPostEvent(InputInfoPtr pInfo, int
                         }
                     }
                 }
+#if defined (FREEBSD_USB)
+            } else {
+                pMse->wheelXDistance = 0;
+                pMse->wheelYDistance = 0;
+#endif
             }
 
             /* Absorb the mouse movement while the wheel button is pressed. */
@@ -2305,7 +2379,11 @@ MouseDoPostEvent(InputInfoPtr pInfo, int
     if (pMse->emulate3ButtonsSoft && pMse->emulate3Pending && (dx || dy))
         buttonTimer(pInfo);
 
+#if !defined(FREEBSD_USB)
     if (dx || dy)
+#else
+    if ((dx || dy) && !pMse->disableXY)
+#endif
         xf86PostMotionEvent(pInfo->dev, 0, 0, 2, dx, dy);
 
     if (change) {
@@ -2418,12 +2496,16 @@ MousePostEvent(InputInfoPtr pInfo, int t
                int dx, int dy, int dz, int dw)
 {
     MouseDevPtr pMse;
+#if !defined(FREEBSD_USB)
     mousePrivPtr mousepriv;
+#endif
     int zbutton = 0, wbutton = 0, zbuttoncount = 0, wbuttoncount = 0;
     int i, b, buttons = 0;
 
     pMse = pInfo->private;
+#if !defined(FREEBSD_USB)
     mousepriv = (mousePrivPtr)pMse->mousePriv;
+#endif
 
     if (pMse->protocolID == PROT_MMHIT)
         b = reverseBits(hitachMap, truebuttons);
@@ -2516,12 +2598,21 @@ MousePostEvent(InputInfoPtr pInfo, int t
 
     /* Accumulate the scaled dx, dy in the private variables
        fracdx,fracdy and return the integer number part */
+#if !defined(FREEBSD_USB)
     if (mousepriv) {
         mousepriv->fracdx += mousepriv->sensitivity*dx;
         mousepriv->fracdy += mousepriv->sensitivity*dy;
         mousepriv->fracdx -= ( dx=(int)(mousepriv->fracdx) );
         mousepriv->fracdy -= ( dy=(int)(mousepriv->fracdy) );
     }
+#else
+    if (pMse->sensitivity != 0) {
+        pMse->fracdx += pMse->sensitivity*dx;
+        pMse->fracdy += pMse->sensitivity*dy;
+        pMse->fracdx -= ( dx=(int)(pMse->fracdx) );
+        pMse->fracdy -= ( dy=(int)(pMse->fracdy) );
+    }
+#endif
 
     /* If mouse wheel movement has to be mapped on a button, we need to
      * loop for button press and release events. */
