$NetBSD: patch-chrome_common_chrome__switches.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/common/chrome_switches.h.orig	2011-04-13 08:01:58.000000000 +0000
+++ chrome/common/chrome_switches.h
@@ -369,7 +369,7 @@ extern const char kEnableMediaPlayer[];
 extern const char kEnableAdvancedFileSystem[];
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kScrollPixels[];
 #endif
 
