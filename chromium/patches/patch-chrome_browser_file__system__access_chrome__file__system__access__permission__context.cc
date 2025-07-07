$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.cc
@@ -341,7 +341,7 @@ GenerateBlockedPath() {
        FILE_PATH_LITERAL("Library/Mobile Documents/com~apple~CloudDocs"),
        BlockType::kDontBlockChildren},
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
       // On Linux also block access to devices via /dev.
       {kNoBasePathKey, FILE_PATH_LITERAL("/dev"), BlockType::kBlockAllChildren},
       // And security sensitive data in /proc and /sys.
