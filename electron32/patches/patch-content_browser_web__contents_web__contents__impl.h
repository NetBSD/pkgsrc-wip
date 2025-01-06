$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/web_contents/web_contents_impl.h.orig	2024-10-18 12:34:14.018587400 +0000
+++ content/browser/web_contents/web_contents_impl.h
@@ -1100,6 +1100,7 @@ class CONTENT_EXPORT WebContentsImpl
   void SendScreenRects() override;
   void SendActiveState(bool active) override;
   TextInputManager* GetTextInputManager() override;
+  void OnCursorChanged(const ui::Cursor& cursor) override;
   bool IsWidgetForPrimaryMainFrame(
       RenderWidgetHostImpl* render_widget_host) override;
   bool IsShowingContextMenuOnPage() const override;
