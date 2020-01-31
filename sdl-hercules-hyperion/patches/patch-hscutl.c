$NetBSD$

Wrong number of arguments to pthread_setname_np:
pthread_setname_np(pthread_t thread, const char *name, void *arg);

--- hscutl.c.orig	2019-09-10 18:06:20.000000000 +0000
+++ hscutl.c
@@ -1660,7 +1660,7 @@ DLL_EXPORT int nix_set_thread_name( pthr
         return EINVAL;
     rc = pthread_setname_np( threadname );
 #else
-    rc = pthread_setname_np( tid, threadname );
+    rc = pthread_setname_np( tid, threadname, 0 );
 #endif
 
     /* Ignore any error; it either worked or it didn't */
