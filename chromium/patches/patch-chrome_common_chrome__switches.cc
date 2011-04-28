$NetBSD: patch-chrome_common_chrome__switches.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/common/chrome_switches.cc.orig	2011-04-13 08:01:58.000000000 +0000
+++ chrome/common/chrome_switches.cc
@@ -1302,7 +1302,7 @@ const char kEnableMediaPlayer[]         
 const char kEnableAdvancedFileSystem[]      = "enable-advanced-fs";
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Specify the amount the trackpad should scroll by.
 const char kScrollPixels[]                  = "scroll-pixels";
 #endif
