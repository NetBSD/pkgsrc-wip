$NetBSD$

--- src/VBox/Runtime/r3/posix/fileaio-posix.cpp.orig	2016-03-04 19:30:03.000000000 +0000
+++ src/VBox/Runtime/r3/posix/fileaio-posix.cpp
@@ -40,11 +40,11 @@
 #include <iprt/semaphore.h>
 #include "internal/fileaio.h"
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <sys/types.h>
 # include <sys/sysctl.h> /* for sysctlbyname */
 #endif
-#if defined(RT_OS_FREEBSD)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <fcntl.h> /* O_SYNC */
 #endif
 #include <aio.h>
@@ -316,7 +316,7 @@ RTR3DECL(int) RTFileAioGetLimits(PRTFILE
 
     pAioLimits->cReqsOutstandingMax = cReqsOutstandingMax;
     pAioLimits->cbBufferAlignment   = 0;
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     /*
      * The AIO API is implemented in a kernel module which is not
      * loaded by default.
@@ -710,7 +710,7 @@ RTDECL(int) RTFileAioCtxSubmit(RTFILEAIO
                     {
                         cReqsSubmitted--;
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
                         if (errno == EINVAL)
 #else
                         if (rcPosix == EINVAL)
@@ -729,7 +729,7 @@ RTDECL(int) RTFileAioCtxSubmit(RTFILEAIO
                              * glibc returns the error code which would be in errno but Apple returns
                              * -1 and sets errno to the appropriate value
                              */
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
                             Assert(rcPosix == -1);
                             pReqInt->Rc = RTErrConvertFromErrno(errno);
 #elif defined(RT_OS_LINUX)
@@ -957,7 +957,7 @@ RTDECL(int) RTFileAioCtxWait(RTFILEAIOCT
                     }
                     else
                     {
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
                         pReq->Rc = RTErrConvertFromErrno(errno);
 #else
                         pReq->Rc = RTErrConvertFromErrno(rcReq);
@@ -1059,4 +1059,3 @@ RTDECL(int) RTFileAioCtxWakeup(RTFILEAIO
 
     return VINF_SUCCESS;
 }
-
