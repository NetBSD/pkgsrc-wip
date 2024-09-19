$NetBSD$

Add NetBSD support.

--- src/other/openscenegraph/src/OpenThreads/pthreads/PThread.cpp.orig	2016-08-09 06:51:54.000000000 +0000
+++ src/other/openscenegraph/src/OpenThreads/pthreads/PThread.cpp
@@ -31,7 +31,7 @@
     #include <sys/unistd.h>
 #endif
 #endif
-#if defined(__sgi)
+#if defined(__sgi) || defined(__NetBSD__)
 #include <unistd.h>
 #endif
 #if defined(__hpux)
@@ -1008,7 +1008,7 @@ int Thread::microSleep(unsigned int micr
 //
 int OpenThreads::GetNumberOfProcessors()
 {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
    long ret = sysconf(_SC_NPROCESSORS_ONLN);
    if (ret == -1)
       return 0;
