$NetBSD$

--- src/pal/src/thread/thread.cpp.orig	2016-01-31 18:28:53.000000000 +0000
+++ src/pal/src/thread/thread.cpp
@@ -621,11 +621,13 @@ CorUnix::InternalCreateThread(
         dwStackSize = CPalThread::s_dwDefaultThreadStackSize;
     }
 
+#ifdef PTHREAD_STACK_MIN
     if (PTHREAD_STACK_MIN > pthreadStackSize)
     {
         WARN("default stack size is reported as %d, but PTHREAD_STACK_MIN is "
              "%d\n", pthreadStackSize, PTHREAD_STACK_MIN);
     }
+#endif
     
     if (pthreadStackSize < dwStackSize)
     {
