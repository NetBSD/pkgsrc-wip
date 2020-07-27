$NetBSD$

--- remoting/host/switches.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ remoting/host/switches.cc
@@ -21,7 +21,7 @@ const char kProcessTypeHost[] = "host";
 const char kProcessTypeRdpDesktopSession[] = "rdp_desktop_session";
 const char kProcessTypeEvaluateCapability[] = "evaluate_capability";
 const char kProcessTypeFileChooser[] = "file_chooser";
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char kProcessTypeXSessionChooser[] = "xsession_chooser";
 #endif  // defined(OS_LINUX)
 
