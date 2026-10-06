$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/web_contents/web_contents_impl.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/web_contents/web_contents_impl.h
@@ -1130,6 +1130,7 @@ class CONTENT_EXPORT WebContentsImpl
   void SendScreenRects() override;
   void SendActiveState(bool active) override;
   TextInputManager* GetTextInputManager() override;
+  void OnCursorChanged(const ui::Cursor& cursor) override;
   bool IsWidgetForPrimaryMainFrame(
       RenderWidgetHostImpl* render_widget_host) override;
   bool IsShowingContextMenuOnPage() const override;
