$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/data_controls/core/browser/features.h.orig	2025-09-29 17:05:47.000000000 +0000
+++ components/enterprise/data_controls/core/browser/features.h
@@ -16,7 +16,7 @@ BASE_DECLARE_FEATURE(kEnableClipboardDat
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Controls enabling Data Controls rules for downloads on desktop
 BASE_DECLARE_FEATURE(kEnableDownloadDataControlsDesktop);
 #endif
