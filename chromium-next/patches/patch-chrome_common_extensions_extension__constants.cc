$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/extensions/extension_constants.cc.orig	2025-03-20 19:11:33.000000000 +0000
+++ chrome/common/extensions/extension_constants.cc
@@ -46,7 +46,7 @@ const char* const kBuiltInFirstPartyExte
 #if !BUILDFLAG(IS_CHROMEOS_LACROS)
     kReadingModeGDocsHelperExtensionId,
 #endif        // !BUILDFLAG(IS_CHROMEOS_LACROS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     kTTSEngineExtensionId,
     kComponentUpdaterTTSEngineExtensionId,
 #endif        // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
