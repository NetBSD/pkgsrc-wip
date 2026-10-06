$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/linux/linux_ui.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/linux/linux_ui.h
@@ -306,7 +306,8 @@ class COMPONENT_EXPORT(LINUX_UI) LinuxUi
   // The returned object is not owned by the caller and will remain alive until
   // the process ends.
   virtual WindowFrameProvider* GetWindowFrameProvider(bool solid_frame,
-                                                      bool tiled) = 0;
+                                                      bool tiled,
+                                                      bool maximized) = 0;
 
  protected:
   LinuxUiTheme();
