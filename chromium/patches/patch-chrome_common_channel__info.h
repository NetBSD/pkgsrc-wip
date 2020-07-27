$NetBSD$

--- chrome/common/channel_info.h.orig	2020-07-08 21:40:36.000000000 +0000
+++ chrome/common/channel_info.h
@@ -61,7 +61,7 @@ bool IsSideBySideCapable();
 std::string GetChannelSuffixForDataDir();
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Returns the channel-specific filename of the desktop shortcut used to launch
 // the browser.
 std::string GetDesktopName(base::Environment* env);
