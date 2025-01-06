$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/browser/browser_linux.cc.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/shell/browser/browser_linux.cc
@@ -19,7 +19,7 @@
 #include "shell/common/gin_converters/login_item_settings_converter.h"
 #include "shell/common/thread_restrictions.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "shell/browser/linux/unity_service.h"
 #include "ui/gtk/gtk_util.h"  // nogncheck
 #endif
