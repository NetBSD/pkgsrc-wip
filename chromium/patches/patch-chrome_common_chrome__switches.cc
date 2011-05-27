$NetBSD: patch-chrome_common_chrome__switches.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/common/chrome_switches.cc.orig	2011-05-24 08:01:58.000000000 +0000
+++ chrome/common/chrome_switches.cc
@@ -1174,7 +1174,7 @@ const char kEnableMediaPlayer[]         
 const char kEnableAdvancedFileSystem[]      = "enable-advanced-fs";
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Specify the amount the trackpad should scroll by.
 const char kScrollPixels[]                  = "scroll-pixels";
 #endif
