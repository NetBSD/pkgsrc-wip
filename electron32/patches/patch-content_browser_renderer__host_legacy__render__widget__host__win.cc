$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/legacy_render_widget_host_win.cc.orig	2024-10-18 12:34:13.258980300 +0000
+++ content/browser/renderer_host/legacy_render_widget_host_win.cc
@@ -321,12 +321,12 @@ LRESULT LegacyRenderWidgetHostHWND::OnMo
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
@@ -357,7 +357,10 @@ LRESULT LegacyRenderWidgetHostHWND::OnMo
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
