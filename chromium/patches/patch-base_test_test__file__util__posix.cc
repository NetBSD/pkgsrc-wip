$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/test/test_file_util_posix.cc.orig	2024-08-21 22:46:04.859046200 +0000
+++ base/test/test_file_util_posix.cc
@@ -91,7 +91,7 @@ void SyncPageCacheToDisk() {
 }
 
 #if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_APPLE) && \
-    !BUILDFLAG(IS_ANDROID)
+    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
 bool EvictFileFromSystemCache(const FilePath& file) {
   // There doesn't seem to be a POSIX way to cool the disk cache.
   NOTIMPLEMENTED();
