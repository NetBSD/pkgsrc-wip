$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/wtf/stack_util.cc.orig	2024-07-24 02:44:47.021787400 +0000
+++ third_party/blink/renderer/platform/wtf/stack_util.cc
@@ -19,6 +19,13 @@
 extern "C" void* __libc_stack_end;  // NOLINT
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include <sys/signal.h>
+#if !BUILDFLAG(IS_NETBSD)
+#include <pthread_np.h>
+#endif
+#endif
+
 namespace WTF {
 
 size_t GetUnderestimatedStackSize() {
@@ -31,7 +38,8 @@ size_t GetUnderestimatedStackSize() {
 // correctly for the main thread.
 
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_NETBSD)
   // pthread_getattr_np() can fail if the thread is not invoked by
   // pthread_create() (e.g., the main thread of blink_unittests).
   // If so, a conservative size estimate is returned.
@@ -52,7 +60,7 @@ size_t GetUnderestimatedStackSize() {
     pthread_attr_destroy(&attr);
     return size;
   }
-#if BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   pthread_attr_destroy(&attr);
 #endif
 
@@ -63,6 +71,8 @@ size_t GetUnderestimatedStackSize() {
   //    low as 512k.
   //
   return 512 * 1024;
+#elif BUILDFLAG(IS_OPENBSD)
+  return 512 * 1024;
 #elif BUILDFLAG(IS_APPLE)
   // pthread_get_stacksize_np() returns too low a value for the main thread on
   // OSX 10.9,
@@ -99,7 +109,7 @@ size_t GetUnderestimatedStackSize() {
 
 void* GetStackStart() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_NETBSD)
   pthread_attr_t attr;
   int error;
 #if BUILDFLAG(IS_FREEBSD)
@@ -116,7 +126,7 @@ void* GetStackStart() {
     pthread_attr_destroy(&attr);
     return reinterpret_cast<uint8_t*>(base) + size;
   }
-#if BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   pthread_attr_destroy(&attr);
 #endif
 #if defined(__GLIBC__)
@@ -150,6 +160,13 @@ void* GetStackStart() {
   ::GetCurrentThreadStackLimits(&lowLimit, &highLimit);
   return reinterpret_cast<void*>(highLimit);
 #endif
+#elif BUILDFLAG(IS_OPENBSD)
+  stack_t ss;
+  void *base;
+  int error = pthread_stackseg_np(pthread_self(), &ss);
+  CHECK(!error);
+  base = (void*)((size_t) ss.ss_sp - ss.ss_size);
+  return reinterpret_cast<uint8_t*>(base) + ss.ss_size;
 #else
 #error Unsupported getStackStart on this platform.
 #endif
