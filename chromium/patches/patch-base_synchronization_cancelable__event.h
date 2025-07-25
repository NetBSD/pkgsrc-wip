$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/synchronization/cancelable_event.h.orig	2025-07-21 19:32:31.000000000 +0000
+++ base/synchronization/cancelable_event.h
@@ -11,7 +11,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include <windows.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <semaphore.h>
 #else
 #include "base/synchronization/waitable_event.h"
@@ -49,7 +49,7 @@ class BASE_EXPORT CancelableEvent {
 
 #if BUILDFLAG(IS_WIN)
   using NativeHandle = HANDLE;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   using NativeHandle = sem_t;
 #else
   using NativeHandle = WaitableEvent;
