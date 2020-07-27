$NetBSD$

--- remoting/host/host_main.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ remoting/host/host_main.cc
@@ -48,7 +48,7 @@ int DesktopProcessMain();
 int FileChooserMain();
 int RdpDesktopSessionMain();
 #endif  // defined(OS_WIN)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 int XSessionChooserMain();
 #endif  // defined(OS_LINUX)
 
@@ -143,7 +143,7 @@ MainRoutineFn SelectMainRoutine(const st
   } else if (process_type == kProcessTypeRdpDesktopSession) {
     main_routine = &RdpDesktopSessionMain;
 #endif  // defined(OS_WIN)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
 #endif  // defined(OS_LINUX)
