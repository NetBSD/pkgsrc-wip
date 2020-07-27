$NetBSD$

--- chrome/common/channel_info_posix.cc.orig	2020-07-08 21:40:36.000000000 +0000
+++ chrome/common/channel_info_posix.cc
@@ -67,7 +67,7 @@ std::string GetChannelSuffixForDataDir()
   }
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 std::string GetDesktopName(base::Environment* env) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   // Google Chrome packaged as a snap is a special case: the application name
