$NetBSD: patch-libgfortran_io_io.h,v 1.1 2024/03/08 12:02:34 wiz Exp $

Don't declare old_locale* an internal_proto to avoid linking problems

--- libgfortran/io/io.h.orig	2024-05-21 10:47:41.000000000 +0300
+++ libgfortran/io/io.h
@@ -62,11 +62,8 @@
 internal_proto(c_locale);
 #else
 extern char* old_locale;
-internal_proto(old_locale);
 extern int old_locale_ctr;
-internal_proto(old_locale_ctr);
 extern __gthread_mutex_t old_locale_lock;
-internal_proto(old_locale_lock);
 #endif
 
 
