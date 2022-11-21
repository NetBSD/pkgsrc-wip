$NetBSD$

--- otherlibs/systhreads/st_stubs.c.orig	2022-10-12 13:53:13.000000000 +0000
+++ otherlibs/systhreads/st_stubs.c
@@ -15,6 +15,9 @@
 
 #define CAML_INTERNALS
 
+/* Needed for sigwait */
+#define _POSIX_PTHREAD_SEMANTICS
+
 #if defined(_WIN32) && !defined(NATIVE_CODE)
 /* Ensure that pthread.h marks symbols __declspec(dllimport) so that they can be
    picked up from the runtime (which will have linked winpthreads statically) */
