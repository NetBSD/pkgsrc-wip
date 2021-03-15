$NetBSD$

--- src/3rdparty/chromium/chrome/common/chrome_switches.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/chrome_switches.cc
@@ -834,7 +834,7 @@ const char kAllowNaClFileHandleAPI[]    
 const char kAllowNaClSocketAPI[]            = "allow-nacl-socket-api";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 
 // Causes the browser to launch directly in guest mode.
