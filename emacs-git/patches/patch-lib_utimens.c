$NetBSD$

NetBSD utimens fix from gnulib

--- lib/utimens.c.orig	2024-06-24 08:03:06.000000000 +0000
+++ lib/utimens.c
@@ -516,6 +516,7 @@ fdutimens (int fd, char const *file, str
   }
 }
 
+#if !HAVE_UTIMENS
 /* Set the access and modification timestamps of FILE to be
    TIMESPEC[0] and TIMESPEC[1], respectively.  */
 int
@@ -523,7 +524,9 @@ utimens (char const *file, struct timesp
 {
   return fdutimens (-1, file, timespec);
 }
+#endif
 
+#if !HAVE_LUTIMENS
 /* Set the access and modification timestamps of FILE to be
    TIMESPEC[0] and TIMESPEC[1], respectively, without dereferencing
    symlinks.  Fail with ENOSYS if the platform does not support
@@ -646,3 +649,4 @@ lutimens (char const *file, struct times
   errno = ENOSYS;
   return -1;
 }
+#endif
