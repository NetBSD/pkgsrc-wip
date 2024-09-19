$NetBSD$

--- src/VBox/Runtime/r3/posix/semevent-posix.cpp.orig	2016-03-04 19:30:03.000000000 +0000
+++ src/VBox/Runtime/r3/posix/semevent-posix.cpp
@@ -49,7 +49,7 @@
 # define pthread_yield() pthread_yield_np()
 #endif
 
-#if defined(RT_OS_SOLARIS) || defined(RT_OS_HAIKU)
+#if defined(RT_OS_SOLARIS) || defined(RT_OS_HAIKU) || defined(RT_OS_NETBSD)
 # include <sched.h>
 # define pthread_yield() sched_yield()
 #endif
@@ -544,4 +544,3 @@ RTDECL(void) RTSemEventRemoveSignaller(R
     RTLockValidatorRecSharedRemoveOwner(&pThis->Signallers, hThread);
 #endif
 }
-
