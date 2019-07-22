$NetBSD$

--- vm/src/unix/runtime/monitorPieces_unix.cpp.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/unix/runtime/monitorPieces_unix.cpp
@@ -57,7 +57,8 @@ ProcessTime ProcessInfo::system_time(){
 } 
 
 # elif  TARGET_OS_VERSION == SUNOS_VERSION  \
-  ||  TARGET_OS_VERSION ==   LINUX_VERSION
+  ||  TARGET_OS_VERSION ==   LINUX_VERSION \
+  ||  TARGET_OS_VERSION ==   NETBSD_VERSION
 
 static struct rusage process_info_ru;
 
@@ -189,4 +190,3 @@ void InterruptedFrameMonitor::get_frame_
   f  = InterruptedContext::the_interrupted_context->sp();
   pc = InterruptedContext::the_interrupted_context->pc();
 }
-
