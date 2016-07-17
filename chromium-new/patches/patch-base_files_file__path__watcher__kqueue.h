$NetBSD$

--- base/files/file_path_watcher_kqueue.h.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/files/file_path_watcher_kqueue.h
@@ -5,7 +5,12 @@
 #ifndef BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 #define BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 
+#ifdef __FreeBSD__
+#include <sys/stdint.h>
+#include <sys/types.h>
+#endif
 #include <sys/event.h>
+#include <sys/time.h>
 #include <vector>
 
 #include "base/files/file_path.h"
