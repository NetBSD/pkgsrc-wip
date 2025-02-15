$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/printing/printing_utils.cc.orig	2025-01-21 17:36:55.000000000 +0000
+++ electron/shell/browser/printing/printing_utils.cc
@@ -28,7 +28,7 @@
 #include <ApplicationServices/ApplicationServices.h>
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <gtk/gtk.h>
 #endif
 
