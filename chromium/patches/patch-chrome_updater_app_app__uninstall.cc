$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/updater/app/app_uninstall.cc.orig	2025-05-30 19:50:32.000000000 +0000
+++ chrome/updater/app/app_uninstall.cc
@@ -172,7 +172,7 @@ void UninstallInThreadPool(UpdaterScope 
             }
             if (int result = UninstallOtherVersions(scope);
                 result != kErrorOk) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
               // TODO(crbug.com/366249606): Ignores the errors when uninstalls
               // the other versions, because currently older Linux updater on
               // CIPD exits with error `kErrorFailedToDeleteFolder`.
