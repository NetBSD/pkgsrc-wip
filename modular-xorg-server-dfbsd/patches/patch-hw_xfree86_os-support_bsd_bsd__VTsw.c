$NetBSD: patch-hw_xfree86_os-support_bsd_bsd__VTsw.c,v 1.1 2015/10/11 18:28:53 tnn Exp $

VT switching support. From xsrc.

--- hw/xfree86/os-support/bsd/bsd_VTsw.c.orig	2019-05-30 18:27:34.000000000 +0000
+++ hw/xfree86/os-support/bsd/bsd_VTsw.c
@@ -68,6 +68,9 @@ xf86VTSwitchAway()
 {
 #if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
     if (xf86Info.consType == SYSCONS || xf86Info.consType == PCVT) {
+#if defined(WSCONS_SUPPORT) && defined(VTSW_KDSETMODE_XSRC)
+	ioctl(xf86Info.consoleFd, KDSETMODE, KD_TEXT);
+#endif
         xf86Info.vtRequestsPending = FALSE;
         if (ioctl(xf86Info.consoleFd, VT_RELDISP, 1) < 0)
             return FALSE;
@@ -83,6 +86,9 @@ xf86VTSwitchTo()
 {
 #if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
     if (xf86Info.consType == SYSCONS || xf86Info.consType == PCVT) {
+#if defined(WSCONS_SUPPORT) && defined(VTSW_KDSETMODE_XSRC)
+	ioctl(xf86Info.consoleFd, KDSETMODE, KD_GRAPHICS);
+#endif
         xf86Info.vtRequestsPending = FALSE;
         if (ioctl(xf86Info.consoleFd, VT_RELDISP, VT_ACKACQ) < 0)
             return FALSE;
