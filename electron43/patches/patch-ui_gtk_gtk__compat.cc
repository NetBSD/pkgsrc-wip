$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- ui/gtk/gtk_compat.cc.orig	2026-10-20 14:58:48.273571016 +0000
+++ ui/gtk/gtk_compat.cc
@@ -82,15 +82,6 @@ void* GetLibGio() {
   return libgio;
 }
 
-void* GetLibGdkPixbuf() {
-#if BUILDFLAG(IS_BSD)
-  static void* libgdk_pixbuf = DlOpen("libgdk_pixbuf-2.0.so");
-#else
-  static void* libgdk_pixbuf = DlOpen("libgdk_pixbuf-2.0.so.0");
-#endif
-  return libgdk_pixbuf;
-}
-
 void* GetLibGdk3() {
 #if BUILDFLAG(IS_BSD)
   static void* libgdk3 = DlOpen("libgdk-3.so");
