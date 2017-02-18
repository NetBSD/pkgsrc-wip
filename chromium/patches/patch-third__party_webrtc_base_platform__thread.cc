$NetBSD$

--- third_party/webrtc/base/platform_thread.cc.orig	2016-11-10 20:03:05.000000000 +0000
+++ third_party/webrtc/base/platform_thread.cc
@@ -12,11 +12,20 @@
 
 #include "webrtc/base/checks.h"
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <sys/prctl.h>
 #include <sys/syscall.h>
 #endif
 
+#if defined(WEBRTC_BSD)
+#include <pthread.h>
+#if !defined(__NetBSD__)
+#include <pthread_np.h>
+#include <sys/thr.h>
+#endif
+#include <sys/syscall.h>
+#endif
+
 namespace rtc {
 
 PlatformThreadId CurrentThreadId() {
@@ -26,6 +35,10 @@ PlatformThreadId CurrentThreadId() {
 #elif defined(WEBRTC_POSIX)
 #if defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   ret = pthread_mach_thread_np(pthread_self());
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
+  ret = reinterpret_cast<uint64_t>(pthread_self());
+#elif defined(WEBRTC_BSD)
+  ret = static_cast<int>(pthread_getthreadid_np());
 #elif defined(WEBRTC_LINUX)
   ret =  syscall(__NR_gettid);
 #elif defined(WEBRTC_ANDROID)
@@ -69,7 +82,11 @@ void SetCurrentThreadName(const char* na
                      reinterpret_cast<ULONG_PTR*>(&threadname_info));
   } __except (EXCEPTION_EXECUTE_HANDLER) {
   }
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)
+#elif defined(__NetBSD__)
+  pthread_setname_np(pthread_self(), "%s", const_cast<void*>(reinterpret_cast<const void*>(name)));
+#elif defined(WEBRTC_BSD)
+  pthread_set_name_np(pthread_self(), name);
+#elif (defined(WEBRTC_LINUX) || defined(WEBRTC_ANDROID)) && !defined(WEBRTC_BSD)
   prctl(PR_SET_NAME, reinterpret_cast<unsigned long>(name));
 #elif defined(WEBRTC_MAC) || defined(WEBRTC_IOS)
   pthread_setname_np(name);
