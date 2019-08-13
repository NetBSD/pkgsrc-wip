$NetBSD$

Adapt to NetBSD.

--- quickjs-libc.c.orig	2019-08-10 10:58:42.000000000 +0000
+++ quickjs-libc.c
@@ -1496,7 +1496,7 @@ static void os_signal_handler(int sig_nu
     os_pending_signals |= ((uint64_t)1 << sig_num);
 }
 
-#if defined(_WIN32)
+#if defined(_WIN32) || defined(__NetBSD__)
 typedef void (*sighandler_t)(int sig_num);
 #endif
 
@@ -1821,6 +1821,8 @@ static int js_os_poll(JSContext *ctx)
 #define OS_PLATFORM "darwin"
 #elif defined(EMSCRIPTEN)
 #define OS_PLATFORM "js"
+#elif defined(__NetBSD__)
+#define OS_PLATFORM "NetBSD"
 #else
 #define OS_PLATFORM "linux"
 #endif
