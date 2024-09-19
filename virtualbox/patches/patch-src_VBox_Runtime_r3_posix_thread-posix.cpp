$NetBSD$

--- src/VBox/Runtime/r3/posix/thread-posix.cpp.orig	2016-03-04 19:30:04.000000000 +0000
+++ src/VBox/Runtime/r3/posix/thread-posix.cpp
@@ -414,7 +414,7 @@ RTR3DECL(int) RTThreadGetExecutionTimeMi
     *pUserTime   = ts.ru_utime.tv_sec * 1000 + ts.ru_utime.tv_usec / 1000;
     return VINF_SUCCESS;
 
-#elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /* on Linux, getrusage(RUSAGE_THREAD, ...) is available since 2.6.26 */
     struct timespec ts;
     int rc = clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
@@ -448,4 +448,3 @@ RTR3DECL(int) RTThreadGetExecutionTimeMi
     return VERR_NOT_IMPLEMENTED;
 #endif
 }
-
