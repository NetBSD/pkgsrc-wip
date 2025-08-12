$NetBSD$

--- src/modules/module-rt.c.orig	2025-07-23 15:42:58.000000000 +0000
+++ src/modules/module-rt.c
@@ -38,6 +38,9 @@
 #if defined(__GNU__)
 #include <hurd.h>
 #endif
+#if defined(__NetBSD__)
+#include <lwp.h>
+#endif
 #include <fcntl.h>
 #include <unistd.h>
 #include <pthread.h>
@@ -259,6 +262,8 @@ static pid_t _gettid(void)
 #elif defined(__GNU__)
        mach_port_t thread = hurd_thread_self();
        return (pid_t)thread;
+#elif defined(__NetBSD__)
+       return (pid_t)_lwp_self();
 #else
 #error "No gettid impl"
 #endif
