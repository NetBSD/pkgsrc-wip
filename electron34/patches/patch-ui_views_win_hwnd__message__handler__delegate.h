$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/views/win/hwnd_message_handler_delegate.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/views/win/hwnd_message_handler_delegate.h
@@ -255,6 +255,10 @@ class VIEWS_EXPORT HWNDMessageHandlerDel
   // Called when the headless window bounds has changed.
   virtual void HandleHeadlessWindowBoundsChanged(const gfx::Rect& bounds) = 0;
 
+  // Called when synthetic mouse event is generated for touch event on
+  // caption buttons.
+  virtual bool HandleMouseEventForCaption(UINT message) const = 0;
+
  protected:
   virtual ~HWNDMessageHandlerDelegate() = default;
 };
