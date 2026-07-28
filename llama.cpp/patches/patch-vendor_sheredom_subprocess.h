$NetBSD$

Fix build on NetBSD.
https://github.com/sheredom/subprocess.h/pull/102

--- vendor/sheredom/subprocess.h.orig	2026-07-28 08:10:28.544619500 +0000
+++ vendor/sheredom/subprocess.h
@@ -1205,7 +1205,7 @@ cleanup:
 
   // Set working directory
   if (process_cwd) {
-#if defined(__APPLE__) && MAC_OS_X_VERSION_MIN_REQUIRED >= 260000
+#if defined(__NetBSD__) || (defined(__APPLE__) && MAC_OS_X_VERSION_MIN_REQUIRED >= 260000)
     posix_error = posix_spawn_file_actions_addchdir(&actions, process_cwd);
 #else
 #if defined(__APPLE__) && defined(__clang__)
