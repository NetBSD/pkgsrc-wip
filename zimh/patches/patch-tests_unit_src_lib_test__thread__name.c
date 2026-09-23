$NetBSD$

--- tests/unit/src/lib/test_thread_name.c.orig	2026-07-28 16:35:57.482722295 +0000
+++ tests/unit/src/lib/test_thread_name.c
@@ -20,7 +20,7 @@
 #    include <pthread.h>
 #    if defined(__linux__)
 #        include <sys/prctl.h>
-#    elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#    elif defined(__FreeBSD__) || defined(__OpenBSD__) /*|| defined(__NetBSD__)*/
 #        include <pthread_np.h>
 #    endif
 #endif
