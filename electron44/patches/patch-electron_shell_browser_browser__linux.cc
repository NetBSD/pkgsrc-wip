$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/shell/browser/browser_linux.cc.orig	2026-11-18 22:25:18.000000000 +0000
+++ electron/shell/browser/browser_linux.cc
@@ -9,7 +9,7 @@
 
 #include <string_view>
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <gio/gdesktopappinfo.h>
 #include <gio/gio.h>
 #include <gtk/gtk.h>
