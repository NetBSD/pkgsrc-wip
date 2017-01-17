$NetBSD$

From FreeBSD ports / DragonFly dports

XXX This is a big hack as we cannot define pthread_condattr_{init,destroy}
here, or we will conflict with the weak symbols in libthr.  The way our linker
works, the weak symbols will be resolved here, and pthread_condattr functions
will not work even in threaded applications.

I am working to get these symbols added to libc, but in the meantime, this
is needed to avoid crashes in threaded applications which make use of
pthread_condattr*.

XXX Just comment out everything for tested platforms

--- stubs.c.orig	2009-10-14 09:13:09.000000000 +0000
+++ stubs.c
@@ -28,10 +28,12 @@
 #include <stdlib.h>
 #include "config.h"
 
+#if !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
+
 #ifndef HAVE_PTHREAD_SELF
 #define NEED_ZERO_STUB
 # ifdef SUPPORT_ATTRIBUTE_ALIAS
-int pthread_self() __attribute__ ((weak, alias ("__pthread_zero_stub")));
+pthread_t pthread_self() __attribute__ ((weak, alias ("__pthread_zero_stub")));
 # else
 #  pragma weak pthread_self = __pthread_zero_stub
 # endif
@@ -157,7 +159,7 @@ int pthread_equal() __attribute__ ((weak
 #ifndef HAVE_PTHREAD_EXIT
 #define NEED_EXIT_STUB
 # ifdef SUPPORT_ATTRIBUTE_ALIAS
-int pthread_exit() __attribute__ ((weak, alias ("__pthread_exit_stub")));
+void pthread_exit(void*) __attribute__ ((weak, alias ("__pthread_exit_stub")));
 # else
 #  pragma weak pthread_exit = __pthread_exit_stub
 # endif
@@ -190,3 +192,5 @@ static void __pthread_exit_stub(void *re
     exit(EXIT_SUCCESS);
 }
 #endif
+
+#endif /* !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__) */
