$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/devtools/features.h.orig	2025-05-30 19:50:32.000000000 +0000
+++ chrome/browser/devtools/features.h
@@ -92,7 +92,7 @@ BASE_DECLARE_FEATURE(kDevToolsAiGenerate
 
 BASE_DECLARE_FEATURE(kDevToolsNewPermissionDialog);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDevToolsDebuggingRestrictions);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
