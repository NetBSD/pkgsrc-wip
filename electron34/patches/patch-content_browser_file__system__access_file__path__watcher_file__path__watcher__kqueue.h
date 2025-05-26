$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/file_system_access/file_path_watcher/file_path_watcher_kqueue.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/file_system_access/file_path_watcher/file_path_watcher_kqueue.h
@@ -5,6 +5,7 @@
 #ifndef CONTENT_BROWSER_FILE_SYSTEM_ACCESS_FILE_PATH_WATCHER_FILE_PATH_WATCHER_KQUEUE_H_
 #define CONTENT_BROWSER_FILE_SYSTEM_ACCESS_FILE_PATH_WATCHER_FILE_PATH_WATCHER_KQUEUE_H_
 
+#include <sys/time.h>
 #include <sys/event.h>
 
 #include <memory>
