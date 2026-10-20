$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- chrome/browser/process_singleton_posix.cc.orig	2026-10-20 08:24:51.695835326 +0000
+++ chrome/browser/process_singleton_posix.cc
@@ -105,7 +105,7 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/resource/scoped_startup_resource_bundle.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+#if 0
 #include "chrome/browser/ui/process_singleton_dialog_linux.h"
 #endif
 
