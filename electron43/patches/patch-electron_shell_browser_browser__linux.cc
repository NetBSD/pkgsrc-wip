$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/browser_linux.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/browser/browser_linux.cc
@@ -9,7 +9,7 @@
 
 #include <string_view>
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <gio/gdesktopappinfo.h>
 #include <gio/gio.h>
 #include <gtk/gtk.h>
@@ -37,7 +37,7 @@
 #include "ui/gtk/gtk_compat.h"  // nogncheck
 #include "ui/gtk/gtk_util.h"    // nogncheck
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/linux/unity_service.h"
 #endif
 
