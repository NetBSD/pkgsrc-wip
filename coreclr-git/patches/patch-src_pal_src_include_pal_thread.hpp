$NetBSD$

--- src/pal/src/include/pal/thread.hpp.orig	2016-04-08 23:29:23.000000000 +0000
+++ src/pal/src/include/pal/thread.hpp
@@ -828,6 +828,9 @@ inline SIZE_T THREADSilentGetCurrentThre
     pthread_threadid_np(pthread_self(), &tid);
     return (SIZE_T)tid;
 }
+#elif defined(__NetBSD__)
+#include <lwp.h>
+#define THREADSilentGetCurrentThreadId() (SIZE_T)_lwp_self()
 #else
 #define THREADSilentGetCurrentThreadId() (SIZE_T)pthread_self()
 #endif
