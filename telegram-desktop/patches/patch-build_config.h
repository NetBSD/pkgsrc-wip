$NetBSD$

Add NetBSD support for Telegram

--- Telegram/lib_base/base/build_config.h	2020-01-21 15:35:25.000000000 +0000
+++ Telegram/lib_base/base/build_config.h
@@ -12,7 +12,7 @@
 
 #if defined(__APPLE__)
 #define OS_MAC 1
-#elif defined(__linux__) // __APPLE__
+#elif defined(__linux__) || defined(__NetBSD__) // __APPLE__
 #define OS_LINUX 1
 #elif defined(_WIN32) // __APPLE__ || __linux__
 #define OS_WIN 1
