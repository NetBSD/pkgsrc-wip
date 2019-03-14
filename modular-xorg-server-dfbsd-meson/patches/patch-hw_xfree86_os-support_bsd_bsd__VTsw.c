$NetBSD: patch-hw_xfree86_os-support_bsd_bsd__VTsw.c,v 1.1 2015/10/11 18:28:53 tnn Exp $

VT switching support. From xsrc.

--- hw/xfree86/os-support/bsd/bsd_VTsw.c.orig	2019-03-05 16:34:21.000000000 +0000
+++ hw/xfree86/os-support/bsd/bsd_VTsw.c
@@ -44,30 +44,69 @@
 void
 xf86VTRequest(int sig)
 {
+#if defined(USL_VT_SWITCHING)
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT) \
+    || defined(WSCONS_SUPPORT)
+    if (xf86Info.consType == SYSCONS || xf86Info.consType == PCVT ||
+        xf86Info.consType == WSCONS) {
+        xf86Info.vtRequestsPending = TRUE;
+    }
+#endif
+#else /* !USL_VT_SWITCHING */
 #if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
     if (xf86Info.consType == SYSCONS || xf86Info.consType == PCVT) {
         xf86Info.vtRequestsPending = TRUE;
     }
 #endif
+#endif /* USL_VT_SWITCHING */
     return;
 }
 
 Bool
 xf86VTSwitchPending()
 {
+#if defined(USL_VT_SWITCHING)
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT) \
+    || defined(WSCONS_SUPPORT)
+    if (xf86Info.consType == SYSCONS || xf86Info.consType == PCVT ||
+        xf86Info.consType == WSCONS) {
+        return xf86Info.vtRequestsPending ? TRUE : FALSE;
+    }
+#endif
+#else /* !USL_VT_SWITCHING */
 #if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
     if (xf86Info.consType == SYSCONS || xf86Info.consType == PCVT) {
         return xf86Info.vtRequestsPending ? TRUE : FALSE;
     }
 #endif
+#endif /* USL_VT_SWITCHING */
     return FALSE;
 }
 
 Bool
 xf86VTSwitchAway()
 {
+#if defined(USL_VT_SWITCHING)
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT) \
+    || defined(WSCONS_SUPPORT)
+    if (xf86Info.consType == SYSCONS || xf86Info.consType == PCVT ||
+        xf86Info.consType == WSCONS) {
+#ifdef WSCONS_SUPPORT
+	ioctl(xf86Info.consoleFd, KDSETMODE, KD_TEXT);
+#endif
+        xf86Info.vtRequestsPending = FALSE;
+        if (ioctl(xf86Info.consoleFd, VT_RELDISP, 1) < 0)
+            return FALSE;
+        else
+            return TRUE;
+    }
+#endif
+#else /* !USL_VT_SWITCHING */
 #if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
     if (xf86Info.consType == SYSCONS || xf86Info.consType == PCVT) {
+#ifdef WSCONS_SUPPORT
+	ioctl(xf86Info.consoleFd, KDSETMODE, KD_TEXT);
+#endif
         xf86Info.vtRequestsPending = FALSE;
         if (ioctl(xf86Info.consoleFd, VT_RELDISP, 1) < 0)
             return FALSE;
@@ -75,14 +114,34 @@ xf86VTSwitchAway()
             return TRUE;
     }
 #endif
+#endif /* USL_VT_SWITCHING */
     return FALSE;
 }
 
 Bool
 xf86VTSwitchTo()
 {
+#if defined(USL_VT_SWITCHING)
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT) \
+    || defined(WSCONS_SUPPORT)
+    if (xf86Info.consType == SYSCONS || xf86Info.consType == PCVT ||
+        xf86Info.consType == WSCONS) {
+#ifdef WSCONS_SUPPORT
+	ioctl(xf86Info.consoleFd, KDSETMODE, KD_GRAPHICS);
+#endif
+        xf86Info.vtRequestsPending = FALSE;
+        if (ioctl(xf86Info.consoleFd, VT_RELDISP, VT_ACKACQ) < 0)
+            return FALSE;
+        else
+            return TRUE;
+    }
+#endif
+#else /* !USL_VT_SWITCHING */
 #if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
     if (xf86Info.consType == SYSCONS || xf86Info.consType == PCVT) {
+#ifdef WSCONS_SUPPORT
+	ioctl(xf86Info.consoleFd, KDSETMODE, KD_GRAPHICS);
+#endif
         xf86Info.vtRequestsPending = FALSE;
         if (ioctl(xf86Info.consoleFd, VT_RELDISP, VT_ACKACQ) < 0)
             return FALSE;
@@ -90,14 +149,26 @@ xf86VTSwitchTo()
             return TRUE;
     }
 #endif
+#endif /* USL_VT_SWITCHING */
     return TRUE;
 }
 
 Bool
 xf86VTActivate(int vtno)
 {
+#if defined(USL_VT_SWITCHING)
+#if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT) \
+    || defined(WSCONS_SUPPORT)
+    if (xf86Info.consType == SYSCONS || xf86Info.consType == PCVT
+        || xf86Info.consType == WSCONS) {
+        if (ioctl(xf86Info.consoleFd, VT_ACTIVATE, vtno) < 0)
+            return FALSE;
+    }
+#endif
+#else /* !USL_VT_SWITCHING */
     if (ioctl(xf86Info.consoleFd, VT_ACTIVATE, vtno) < 0) {
         return FALSE;
     }
+#endif /* USL_VT_SWITCHING */
     return TRUE;
 }
