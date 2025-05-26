$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/legacy_render_widget_host_win.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/legacy_render_widget_host_win.h
@@ -103,6 +103,7 @@ class CONTENT_EXPORT LegacyRenderWidgetH
     MESSAGE_HANDLER_EX(WM_VSCROLL, OnScroll)
     MESSAGE_HANDLER_EX(WM_NCHITTEST, OnNCHitTest)
     MESSAGE_RANGE_HANDLER(WM_NCMOUSEMOVE, WM_NCXBUTTONDBLCLK, OnMouseRange)
+    MESSAGE_HANDLER_EX(WM_NCMOUSELEAVE, OnMouseLeave)
     MESSAGE_HANDLER_EX(WM_NCCALCSIZE, OnNCCalcSize)
     MESSAGE_HANDLER_EX(WM_SIZE, OnSize)
     MESSAGE_HANDLER_EX(WM_DESTROY, OnDestroy)
