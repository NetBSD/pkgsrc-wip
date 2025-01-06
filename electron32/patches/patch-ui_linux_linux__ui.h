$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/linux/linux_ui.h.orig	2024-10-18 12:35:12.728268900 +0000
+++ ui/linux/linux_ui.h
@@ -307,7 +307,8 @@ class COMPONENT_EXPORT(LINUX_UI) LinuxUi
   // The returned object is not owned by the caller and will remain alive until
   // the process ends.
   virtual WindowFrameProvider* GetWindowFrameProvider(bool solid_frame,
-                                                      bool tiled) = 0;
+                                                      bool tiled,
+                                                      bool maximized) = 0;
 
  protected:
   LinuxUiTheme();
