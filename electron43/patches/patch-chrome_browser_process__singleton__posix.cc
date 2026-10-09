$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/process_singleton_posix.cc.orig	2026-08-17 18:32:36.000000000 +0000
+++ chrome/browser/process_singleton_posix.cc
@@ -102,7 +102,7 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/resource/scoped_startup_resource_bundle.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+#if 0
 #include "chrome/browser/ui/process_singleton_dialog_linux.h"
 #endif
 
