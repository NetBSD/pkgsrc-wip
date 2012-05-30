$NetBSD: patch-vfe_unix_platformbase.cpp,v 1.1.1.1 2012/05/30 11:42:50 thomasklausner Exp $

--- vfe/unix/platformbase.cpp.orig	2010-12-21 06:17:01.000000000 +0000
+++ vfe/unix/platformbase.cpp
@@ -104,6 +104,10 @@
 # include <sys/resource.h>
 #endif
 
+#ifndef CLOCK_THREAD_CPUTIME_ID
+#define CLOCK_THREAD_CPUTIME_ID 0
+#endif
+
 #include "vfe.h"
 
 // this must be the last file included
@@ -191,7 +195,7 @@ namespace pov_base
 	{
 #ifdef HAVE_CLOCK_GETTIME
 		struct timespec ts;
-#if defined (__FreeBSD__)
+#if defined (__FreeBSD__) || defined (__NetBSD__)
 		if (clock_gettime(m_ThreadTimeOnly ? CLOCK_THREAD_CPUTIME_ID : CLOCK_REALTIME, &ts) == 0)
 #else
 		if (clock_gettime(m_ThreadTimeOnly ? CLOCK_THREAD_CPUTIME_ID : CLOCK_PROCESS_CPUTIME_ID, &ts) == 0)
