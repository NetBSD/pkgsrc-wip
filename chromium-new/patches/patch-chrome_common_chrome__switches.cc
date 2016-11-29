$NetBSD$

--- chrome/common/chrome_switches.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/common/chrome_switches.cc
@@ -1277,7 +1277,7 @@ const char kAllowNaClSocketAPI[]        
 const char kEnableWaylandServer[] = "enable-wayland-server";
 #endif
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kDisableInputImeAPI[] = "disable-input-ime-api";
 extern const char kEnableInputImeAPI[] = "enable-input-ime-api";
 #endif
