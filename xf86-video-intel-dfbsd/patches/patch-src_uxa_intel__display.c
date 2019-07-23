$NetBSD: patch-src_uxa_intel__display.c,v 1.1 2016/12/07 21:59:54 wiz Exp $

Upstream patches for xorg-server-1.19.

Patches from NetBSD xsrc xf86-video-intel-2014

--- src/uxa/intel_display.c.orig	2019-03-01 18:22:07.000000000 +0000
+++ src/uxa/intel_display.c
@@ -394,7 +394,11 @@ intel_crtc_apply(xf86CrtcPtr crtc)
 	}
 
 	if (scrn->pScreen)
+#if defined(HAVE_XF86_CURSOR_RESET_CURSOR) && defined(RESET_CURSOR_XSRC_NETBSD)
+		xf86CursorResetCursor(scrn->pScreen);
+#else
 		xf86_reload_cursors(scrn->pScreen);
+#endif
 
 done:
 	free(output_ids);
