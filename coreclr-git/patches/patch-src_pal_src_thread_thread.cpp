$NetBSD$

--- src/pal/src/thread/thread.cpp.orig	2016-02-01 01:51:45.000000000 +0000
+++ src/pal/src/thread/thread.cpp
@@ -1413,7 +1413,9 @@ CorUnix::GetThreadTimesInternal(
 
     pTargetThread->Lock(pThread);
 
+#if 0
     if (pthread_getcpuclockid(pTargetThread->GetPThreadSelf(), &cid) != 0)
+#endif
     {
         ASSERT("Unable to get clock from thread\n", hThread);
         SetLastError(ERROR_INTERNAL_ERROR);
