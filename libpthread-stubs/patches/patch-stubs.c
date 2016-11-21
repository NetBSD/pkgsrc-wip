$NetBSD$

--- stubs.c.orig	2009-10-14 09:13:09.000000000 +0000
+++ stubs.c
@@ -31,7 +31,7 @@
 #ifndef HAVE_PTHREAD_SELF
 #define NEED_ZERO_STUB
 # ifdef SUPPORT_ATTRIBUTE_ALIAS
-int pthread_self() __attribute__ ((weak, alias ("__pthread_zero_stub")));
+pthread_t pthread_self() __attribute__ ((weak, alias ("__pthread_zero_stub")));
 # else
 #  pragma weak pthread_self = __pthread_zero_stub
 # endif
@@ -157,7 +157,7 @@ int pthread_equal() __attribute__ ((weak
 #ifndef HAVE_PTHREAD_EXIT
 #define NEED_EXIT_STUB
 # ifdef SUPPORT_ATTRIBUTE_ALIAS
-int pthread_exit() __attribute__ ((weak, alias ("__pthread_exit_stub")));
+void pthread_exit(void*) __attribute__ ((weak, alias ("__pthread_exit_stub")));
 # else
 #  pragma weak pthread_exit = __pthread_exit_stub
 # endif
