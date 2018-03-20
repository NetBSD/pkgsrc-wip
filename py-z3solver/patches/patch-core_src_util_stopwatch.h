$NetBSD$

Add support for NetBSD.

--- core/src/util/stopwatch.h.orig	2017-01-26 02:18:17.000000000 +0000
+++ core/src/util/stopwatch.h
@@ -130,6 +130,11 @@ public:
 
 #include<ctime>
 
+#ifndef CLOCK_PROCESS_CPUTIME_ID
+/* BSD */
+# define CLOCK_PROCESS_CPUTIME_ID CLOCK_MONOTONIC
+#endif
+
 class stopwatch {
     unsigned long long m_time; // elapsed time in ns
     bool               m_running;
