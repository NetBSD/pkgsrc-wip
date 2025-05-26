$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/deps/uvwasi/src/uvwasi.c.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/deps/uvwasi/src/uvwasi.c
@@ -1,4 +1,8 @@
 #include <stdlib.h>
+#if defined(__NetBSD__)
+// strnlen, telldir, seekdir
+#define _NETBSD_SOURCE
+#endif
 #include <string.h>
 
 #ifndef _WIN32
@@ -803,7 +807,7 @@ uvwasi_errno_t uvwasi_fd_close(uvwasi_t*
     uv_mutex_unlock(&wrap->mutex);
     if (err != UVWASI_ESUCCESS) {
       goto exit;
-    }   
+    }
   }
 
   if (r != 0) {
@@ -2793,7 +2797,7 @@ uvwasi_errno_t uvwasi_sock_shutdown(uvwa
 
   uv_mutex_unlock(&wrap->mutex);
 
-  if (shutdown_data.status != 0) 
+  if (shutdown_data.status != 0)
     return uvwasi__translate_uv_error(shutdown_data.status);
 
   return UVWASI_ESUCCESS;
