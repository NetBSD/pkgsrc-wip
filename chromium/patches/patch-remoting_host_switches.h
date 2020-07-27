$NetBSD$

--- remoting/host/switches.h.orig	2020-07-15 18:56:01.000000000 +0000
+++ remoting/host/switches.h
@@ -34,7 +34,7 @@ extern const char kProcessTypeHost[];
 extern const char kProcessTypeRdpDesktopSession[];
 extern const char kProcessTypeEvaluateCapability[];
 extern const char kProcessTypeFileChooser[];
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kProcessTypeXSessionChooser[];
 #endif  // defined(OS_LINUX)
 
