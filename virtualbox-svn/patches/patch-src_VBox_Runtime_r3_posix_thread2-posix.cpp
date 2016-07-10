$NetBSD$

--- src/VBox/Runtime/r3/posix/thread2-posix.cpp.orig	2016-03-04 19:30:04.000000000 +0000
+++ src/VBox/Runtime/r3/posix/thread2-posix.cpp
@@ -62,7 +62,7 @@ RTDECL(int) RTThreadSleep(RTMSINTERVAL c
         pthread_yield_np();
 #elif defined(RT_OS_FREEBSD) /* void pthread_yield */
         pthread_yield();
-#elif defined(RT_OS_SOLARIS) || defined(RT_OS_HAIKU)
+#elif defined(RT_OS_SOLARIS) || defined(RT_OS_HAIKU) || defined(RT_OS_NETBSD)
         sched_yield();
 #else
         if (!pthread_yield())
@@ -101,7 +101,7 @@ RTDECL(int) RTThreadSleepNoLog(RTMSINTER
         pthread_yield_np();
 #elif defined(RT_OS_FREEBSD) /* void pthread_yield */
         pthread_yield();
-#elif defined(RT_OS_SOLARIS) || defined(RT_OS_HAIKU)
+#elif defined(RT_OS_SOLARIS) || defined(RT_OS_HAIKU) || defined(RT_OS_NETBSD)
         sched_yield();
 #else
         if (!pthread_yield())
@@ -130,7 +130,7 @@ RTDECL(bool) RTThreadYield(void)
 #endif
 #ifdef RT_OS_DARWIN
     pthread_yield_np();
-#elif defined(RT_OS_SOLARIS) || defined(RT_OS_HAIKU)
+#elif defined(RT_OS_SOLARIS) || defined(RT_OS_HAIKU) || defined(RT_OS_NETBSD)
     sched_yield();
 #else
     pthread_yield();
@@ -144,4 +144,3 @@ RTDECL(bool) RTThreadYield(void)
 #endif
     return fRc;
 }
-
