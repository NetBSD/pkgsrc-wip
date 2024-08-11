$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/wtf/thread_specific.h.orig	2024-07-24 02:44:47.033788400 +0000
+++ third_party/blink/renderer/platform/wtf/thread_specific.h
@@ -104,7 +104,8 @@ inline bool ThreadSpecific<T>::IsSet() {
 template <typename T>
 inline ThreadSpecific<T>::operator T*() {
   T* off_thread_ptr;
-#if defined(__GLIBC__) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD)
+#if defined(__GLIBC__) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD) || \
+    BUILDFLAG(IS_NETBSD)
   // TLS is fast on these platforms.
   // TODO(csharrison): Qualify this statement for Android.
   const bool kMainThreadAlwaysChecksTLS = true;
