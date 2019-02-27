$NetBSD$

Option to revert effects of upstream:

2018-02-27	Add RandR leases with modesetting driver support [v6]

commit	e4e3447603b5fd3a38a92c3f972396d1f81168ad

--- hw/xfree86/modes/xf86Cursors.c.orig	2018-10-15 15:59:33.000000000 +0000
+++ hw/xfree86/modes/xf86Cursors.c
@@ -348,7 +348,9 @@ Bool
 xf86_crtc_show_cursor(xf86CrtcPtr crtc)
 {
     if (!crtc->cursor_in_range) {
+#if !defined(REVERT_RANDR_LEASE)
         crtc->funcs->hide_cursor(crtc);
+#endif
         return TRUE;
     }
 
