$NetBSD$

--- src/3rdparty/chromium/chrome/common/chrome_switches.h.orig	2020-07-08 21:41:47.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/chrome_switches.h
@@ -255,7 +255,7 @@ extern const char kAllowNaClFileHandleAP
 extern const char kAllowNaClSocketAPI[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
 #endif
