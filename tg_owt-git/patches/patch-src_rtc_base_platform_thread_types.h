$NetBSD$

--- src/rtc_base/platform_thread_types.h.orig	2021-02-25 16:41:57.499459681 +0000
+++ src/rtc_base/platform_thread_types.h
@@ -39,7 +39,7 @@ typedef DWORD PlatformThreadRef;
 typedef zx_handle_t PlatformThreadId;
 typedef zx_handle_t PlatformThreadRef;
 #elif defined(WEBRTC_POSIX)
-typedef pid_t PlatformThreadId;
+typedef long PlatformThreadId;
 typedef pthread_t PlatformThreadRef;
 #endif
 
