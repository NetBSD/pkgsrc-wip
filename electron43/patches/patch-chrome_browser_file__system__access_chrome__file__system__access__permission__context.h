$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- chrome/browser/file_system_access/chrome_file_system_access_permission_context.h.orig	2026-10-20 14:58:48.371136345 +0000
+++ chrome/browser/file_system_access/chrome_file_system_access_permission_context.h
@@ -603,7 +603,7 @@ class ChromeFileSystemAccessPermissionCo
             FILE_PATH_LITERAL("Library/Mobile Documents/com~apple~CloudDocs"),
             BlockType::kDontBlockChildren),
   #endif
-  #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+  #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
         // On Linux also block access to devices via /dev.
         BlockPath::CreateAbsolute(FILE_PATH_LITERAL("/dev"),
                                   BlockType::kBlockAllChildren),
