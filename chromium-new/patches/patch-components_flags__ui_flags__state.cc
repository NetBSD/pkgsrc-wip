$NetBSD$

--- components/flags_ui/flags_state.cc.orig	2016-06-24 01:02:17.000000000 +0000
+++ components/flags_ui/flags_state.cc
@@ -450,7 +450,7 @@ int FlagsState::GetCurrentPlatform() {
   return kOsWin;
 #elif defined(OS_CHROMEOS)  // Needs to be before the OS_LINUX check.
   return kOsCrOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_FREEBSD) || defined(OS_NETBSD)
   return kOsLinux;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
