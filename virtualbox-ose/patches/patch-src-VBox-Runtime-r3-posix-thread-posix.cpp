$NetBSD$

Add FreeBSD and NetBSD

--- src/VBox/Runtime/r3/posix/thread-posix.cpp~	2015-07-10 23:31:55.000000000 +0900
+++ src/VBox/Runtime/r3/posix/thread-posix.cpp	2015-09-22 21:41:19.000000000 +0900
@@ -414,7 +414,7 @@ RTR3DECL(int) RTThreadGetExecutionTimeMi
     *pUserTime   = ts.ru_utime.tv_sec * 1000 + ts.ru_utime.tv_usec / 1000;
     return VINF_SUCCESS;
 
-#elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /* on Linux, getrusage(RUSAGE_THREAD, ...) is available since 2.6.26 */
     struct timespec ts;
     int rc = clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
