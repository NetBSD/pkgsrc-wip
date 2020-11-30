$NetBSD$

Adapt to NetBSD.

--- quickjs-libc.c.orig	2019-08-10 10:58:42.000000000 +0000
+++ quickjs-libc.c
@@ -675,6 +675,10 @@ static JSValue js_std_unsetenv(JSContext
     return JS_UNDEFINED;
 }
 
+#ifdef __NetBSD__
+extern char **environ;
+#endif
+
 /* return an object containing the list of the available environment
    variables. */
 static JSValue js_std_getenviron(JSContext *ctx, JSValueConst this_val,
@@ -1892,7 +1896,7 @@ static void os_signal_handler(int sig_nu
     os_pending_signals |= ((uint64_t)1 << sig_num);
 }
 
-#if defined(_WIN32)
+#if defined(_WIN32) || defined(__NetBSD__)
 typedef void (*sighandler_t)(int sig_num);
 #endif
 
@@ -3526,6 +3530,8 @@ void js_std_set_worker_new_context_func(
 #define OS_PLATFORM "darwin"
 #elif defined(EMSCRIPTEN)
 #define OS_PLATFORM "js"
+#elif defined(__NetBSD__)
+#define OS_PLATFORM "NetBSD"
 #else
 #define OS_PLATFORM "linux"
 #endif
