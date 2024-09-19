$NetBSD$

Patches from FreeBSD ports / DragonFly dports x11-drivers/xf86-input-mouse 1.9.2.

--- src/mouse.c.orig	2018-06-19 04:36:21.000000000 +0000
+++ src/mouse.c
@@ -304,13 +304,45 @@ MouseCommonOptions(InputInfoPtr pInfo)
 
     pMse = pInfo->private;
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    i = xf86SetIntOption(pInfo->options, "Buttons", 0);
+    if (i != 0)
+        pMse->buttons = i;
+#else
     pMse->buttons = xf86SetIntOption(pInfo->options, "Buttons", 0);
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
     if (!pMse->buttons) {
         pMse->buttons = MSE_DFLTBUTTONS;
         buttons_from = X_DEFAULT;
     }
     origButtons = pMse->buttons;
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
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
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
+
     pMse->emulate3Buttons = xf86SetBoolOption(pInfo->options,
                                               "Emulate3Buttons", FALSE);
     if (!xf86FindOptionValue(pInfo->options,"Emulate3Buttons")) {
@@ -322,6 +354,10 @@ MouseCommonOptions(InputInfoPtr pInfo)
                                              "Emulate3Timeout", 50);
     if (pMse->emulate3Buttons || pMse->emulate3ButtonsSoft) {
         MessageType from = X_CONFIG;
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+	if (pMse->buttons < 3)
+            pMse->buttons = 3;
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
         if (pMse->emulate3ButtonsSoft)
             from = X_DEFAULT;
         xf86Msg(from, "%s: Emulate3Buttons, Emulate3Timeout: %d\n",
@@ -329,6 +365,10 @@ MouseCommonOptions(InputInfoPtr pInfo)
     }
 
     pMse->chordMiddle = xf86SetBoolOption(pInfo->options, "ChordMiddle", FALSE);
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    if (pMse->chordMiddle && pMse->buttons < 3)
+	    pMse->buttons = 3;
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
     pMse->flipXY = xf86SetBoolOption(pInfo->options, "FlipXY", FALSE);
     if (xf86SetBoolOption(pInfo->options, "InvX", FALSE)) {
         pMse->invX = -1;
@@ -339,7 +379,9 @@ MouseCommonOptions(InputInfoPtr pInfo)
     } else
         pMse->invY = 1;
     pMse->angleOffset = xf86SetIntOption(pInfo->options, "AngleOffset", 0);
-
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    pMse->sensitivity = xf86SetRealOption(pInfo->options, "Sensitivity", 1.0);
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
 
     if (pMse->pDragLock)
         free(pMse->pDragLock);
@@ -449,14 +491,25 @@ MouseCommonOptions(InputInfoPtr pInfo)
         free(s);
     }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    s = xf86SetStrOption(pInfo->options, "ZAxisMapping",
+        pMse->hasZ ? ( pMse->hasW ? "4 5 6 7" : "4 5" ) : "off");
+#else
     s = xf86SetStrOption(pInfo->options, "ZAxisMapping", "4 5");
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
     if (s) {
         int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
         char *msg = NULL;
 
         pMse->negativeZ = pMse->positiveZ = MSE_NOAXISMAP;
         pMse->negativeW = pMse->positiveW = MSE_NOAXISMAP;
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+        if (!xf86NameCmp(s, "off")) {
+            msg = xstrdup("off");
+	} else if (!xf86NameCmp(s, "x")) {
+#else
         if (!xf86NameCmp(s, "x")) {
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
             pMse->negativeZ = pMse->positiveZ = MSE_MAPTOX;
             msg = xstrdup("X axis");
         } else if (!xf86NameCmp(s, "y")) {
@@ -605,6 +658,7 @@ MouseCommonOptions(InputInfoPtr pInfo)
                 pInfo->name, wheelButton, pMse->wheelInertia,
                 pMse->wheelButtonTimeout);
     }
+#if !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__DragonFly__)
     s = xf86SetStrOption(pInfo->options, "ButtonMapping", NULL);
     if (s) {
        int b, n = 0;
@@ -628,6 +682,7 @@ MouseCommonOptions(InputInfoPtr pInfo)
         if (f > pMse->buttons)
             pMse->buttons = f;
     }
+#endif /* !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__DragonFly__) */
     if (origButtons != pMse->buttons)
         buttons_from = X_CONFIG;
     xf86Msg(buttons_from, "%s: Buttons: %d\n", pInfo->name, pMse->buttons);
@@ -709,7 +764,9 @@ MouseHWOptions(InputInfoPtr pInfo)
     }
     pMse->sampleRate = xf86SetIntOption(pInfo->options, "SampleRate", 0);
     pMse->resolution = xf86SetIntOption(pInfo->options, "Resolution", 0);
+#if !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__DragonFly__)
     mPriv->sensitivity = xf86SetRealOption(pInfo->options, "Sensitivity", 1.0);
+#endif /* !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__DragonFly__) */
 }
 
 static void
@@ -996,6 +1053,10 @@ MousePreInit(InputDriverPtr drv, InputIn
     /* Default Mapping: 1 2 3 8 9 10 11 ... */
     for (i = 0; i < MSE_MAXBUTTONS; i++)
         pMse->buttonMap[i] = 1 << (i > 2 && i < MSE_MAXBUTTONS-4 ? i+4 : i);
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    pMse->hasZ = 1;
+    pMse->hasW = 0;
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
 
     protocol = MousePickProtocol(pInfo, device, protocol, &protocolID);
 
@@ -2197,7 +2258,11 @@ MouseDoPostEvent(InputInfoPtr pInfo, int
 
     if (pMse->emulateWheel) {
         /* Emulate wheel button handling */
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+        if (pMse->wheelButton == 0)
+#else
         if(pMse->wheelButton == 0)
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
             wheelButtonMask = 0;
         else
             wheelButtonMask = 1 << (pMse->wheelButton - 1);
@@ -2287,6 +2352,11 @@ MouseDoPostEvent(InputInfoPtr pInfo, int
                         }
                     }
                 }
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+            } else {
+                pMse->wheelXDistance = 0;
+                pMse->wheelYDistance = 0;
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
             }
 
             /* Absorb the mouse movement while the wheel button is pressed. */
@@ -2304,7 +2374,11 @@ MouseDoPostEvent(InputInfoPtr pInfo, int
     if (pMse->emulate3ButtonsSoft && pMse->emulate3Pending && (dx || dy))
         buttonTimer(pInfo);
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    if ((dx || dy) && !pMse->disableXY)
+#else
     if (dx || dy)
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
         xf86PostMotionEvent(pInfo->dev, 0, 0, 2, dx, dy);
 
     if (change) {
@@ -2417,12 +2491,16 @@ MousePostEvent(InputInfoPtr pInfo, int t
                int dx, int dy, int dz, int dw)
 {
     MouseDevPtr pMse;
+#if !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__DragonFly__)
     mousePrivPtr mousepriv;
+#endif /* !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__DragonFly__) */
     int zbutton = 0, wbutton = 0, zbuttoncount = 0, wbuttoncount = 0;
     int i, b, buttons = 0;
 
     pMse = pInfo->private;
+#if !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__DragonFly__)
     mousepriv = (mousePrivPtr)pMse->mousePriv;
+#endif /* !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__DragonFly__) */
 
     if (pMse->protocolID == PROT_MMHIT)
         b = reverseBits(hitachMap, truebuttons);
@@ -2515,11 +2593,19 @@ MousePostEvent(InputInfoPtr pInfo, int t
 
     /* Accumulate the scaled dx, dy in the private variables
        fracdx,fracdy and return the integer number part */
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+    if (pMse->sensitivity != 0) {
+        pMse->fracdx += pMse->sensitivity*dx;
+        pMse->fracdy += pMse->sensitivity*dy;
+        pMse->fracdx -= ( dx=(int)(pMse->fracdx) );
+        pMse->fracdy -= ( dy=(int)(pMse->fracdy) );
+#else
     if (mousepriv) {
         mousepriv->fracdx += mousepriv->sensitivity*dx;
         mousepriv->fracdy += mousepriv->sensitivity*dy;
         mousepriv->fracdx -= ( dx=(int)(mousepriv->fracdx) );
         mousepriv->fracdy -= ( dy=(int)(mousepriv->fracdy) );
+#endif /* defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) */
     }
 
     /* If mouse wheel movement has to be mapped on a button, we need to
