$NetBSD$

--- content/public/common/content_switches.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ content/public/common/content_switches.cc
@@ -975,7 +975,7 @@ const char kEnableAggressiveDOMStorageFl
 // Enable indication that browser is controlled by automation.
 const char kEnableAutomation[] = "enable-automation";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
