$NetBSD$

--- chrome/common/chrome_switches.cc.orig	2016-06-24 01:02:14.000000000 +0000
+++ chrome/common/chrome_switches.cc
@@ -1298,7 +1298,7 @@ const char kTabManagementExperimentTypeE
     "tab-management-experiment-type-elderberry";
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kEnableInputImeAPI[] = "enable-input-ime-api";
 extern const char kDisableInputImeAPI[] = "disable-input-ime-api";
 #endif
