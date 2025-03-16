$NetBSD: patch-content_browser_file__system__access_file__path__watcher_file__path__watcher.h,v 1.1 2025/02/06 09:58:05 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/file_system_access/file_path_watcher/file_path_watcher.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/file_system_access/file_path_watcher/file_path_watcher.h
@@ -125,7 +125,7 @@ class CONTENT_EXPORT FilePathWatcher {
     Type type = Type::kNonRecursive;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     // The callback will return the full path to a changed file instead of
     // the watched path supplied as |path| when Watch is called.
     // So the full path can be different from the watched path when a folder is
