$NetBSD$

--- src/VBox/HostDrivers/Support/SUPDrvTracer.cpp.orig	2016-03-04 19:29:24.000000000 +0000
+++ src/VBox/HostDrivers/Support/SUPDrvTracer.cpp
@@ -1466,7 +1466,7 @@ SUPR0DECL(int) SUPR0TracerDeregisterImpl
  * rebuilding of the kernel module from scratch at install time, we have to
  * deploy some ugly gcc inline assembly here.
  */
-#if defined(__GNUC__) && (defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX))
+#if defined(__GNUC__) && (defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_NETBSD))
 __asm__("\
         .section .text                                                  \n\
                                                                         \n\
@@ -2468,4 +2468,3 @@ void VBOXCALL supdrvTracerTerm(PSUPDRVDE
     pDevExt->mtxTracer = NIL_RTSEMFASTMUTEX;
     LOG_TRACER(("supdrvTracerTerm: Done\n"));
 }
-
