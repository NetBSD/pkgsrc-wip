$NetBSD$

* Check _REENTRANT, too.

--- include/freetds/thread.h.orig	2025-08-21 04:59:54.464580072 +0000
+++ include/freetds/thread.h
@@ -24,7 +24,7 @@
 
 #undef TDS_HAVE_MUTEX
 
-#if defined(_THREAD_SAFE) && defined(TDS_HAVE_PTHREAD_MUTEX)
+#if (defined(_REENTRANT) || defined(_THREAD_SAFE)) && defined(TDS_HAVE_PTHREAD_MUTEX)
 
 #include <tds_sysdep_public.h>
 #include <freetds/sysdep_private.h>
