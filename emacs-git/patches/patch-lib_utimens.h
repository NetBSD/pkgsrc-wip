$NetBSD$

NetBSD utimens fix from gnulib

--- lib/utimens.h.orig	2024-06-24 08:03:06.000000000 +0000
+++ lib/utimens.h
@@ -24,13 +24,21 @@
 
 #include <time.h>
 
+#if HAVE_UTIMENS || HAVE_LUTIMENS
+# include <sys/time.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
 
 int fdutimens (int, char const *, struct timespec const [2]);
+#if !HAVE_UTIMENS
 int utimens (char const *, struct timespec const [2]);
+#endif
+#if !HAVE_LUTIMENS
 int lutimens (char const *, struct timespec const [2]);
+#endif
 
 #ifdef __cplusplus
 }
