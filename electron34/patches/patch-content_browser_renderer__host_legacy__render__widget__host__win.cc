$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/legacy_render_widget_host_win.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/legacy_render_widget_host_win.cc
@@ -325,12 +325,12 @@ LRESULT LegacyRenderWidgetHostHWND::OnMo
                                                  WPARAM w_param,
                                                  LPARAM l_param,
                                                  BOOL& handled) {
-  if (message == WM_MOUSEMOVE) {
+  if (message == WM_MOUSEMOVE || message == WM_NCMOUSEMOVE) {
     if (!mouse_tracking_enabled_) {
       mouse_tracking_enabled_ = true;
       TRACKMOUSEEVENT tme;
       tme.cbSize = sizeof(tme);
-      tme.dwFlags = TME_LEAVE;
+      tme.dwFlags = message == WM_NCMOUSEMOVE ? TME_NONCLIENT | TME_LEAVE : TME_LEAVE;
       tme.hwndTrack = hwnd();
       tme.dwHoverTime = 0;
       TrackMouseEvent(&tme);
@@ -361,7 +361,10 @@ LRESULT LegacyRenderWidgetHostHWND::OnMo
     // out of the picture.
     if (!handled &&
         (message >= WM_NCMOUSEMOVE && message <= WM_NCXBUTTONDBLCLK)) {
-      ret = ::DefWindowProc(GetParent(), message, w_param, l_param);
+      // Send WM_NCMOUSEMOVE messages using the LegacyRenderWidgetHostHWND's
+      // handle so mouse tracking on non-client areas doesn't break.
+      HWND target = message == WM_NCMOUSEMOVE ? hwnd() : GetParent();
+      ret = ::DefWindowProc(target, message, w_param, l_param);
       handled = TRUE;
     }
   }
