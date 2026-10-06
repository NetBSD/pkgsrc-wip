$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/gtk/gtk_compat.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/gtk/gtk_compat.h
@@ -41,6 +41,9 @@ using SkColor = uint32_t;
 
 namespace gtk {
 
+// Get handle to the currently loaded gdk_pixbuf library in the process.
+void* GetLibGdkPixbuf();
+
 // Loads libgtk and related libraries and returns true on success.
 bool LoadGtk();
 
