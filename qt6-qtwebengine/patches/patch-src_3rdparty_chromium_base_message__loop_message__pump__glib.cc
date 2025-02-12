$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/message_loop/message_pump_glib.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/base/message_loop/message_pump_glib.cc
@@ -8,6 +8,15 @@
 #include <glib.h>
 #include <math.h>
 
+#if BUILDFLAG(IS_BSD)
+#if BUILDFLAG(IS_NETBSD)
+#include <lwp.h>
+#else
+#include <pthread.h>
+#include <pthread_np.h>
+#endif
+#endif
+
 #include "base/logging.h"
 #include "base/memory/raw_ptr.h"
 #include "base/notreached.h"
@@ -51,9 +60,19 @@ int GetTimeIntervalMilliseconds(TimeTick
 }
 
 bool RunningOnMainThread() {
+#if BUILDFLAG(IS_BSD)
+#if BUILDFLAG(IS_NETBSD)
+  auto pid = getpid();
+  auto tid = _lwp_self();
+  return pid > 0 && tid > 0 && pid == tid;
+#else
+  return pthread_main_np();
+#endif
+#else
   auto pid = getpid();
   auto tid = PlatformThread::CurrentId();
   return pid > 0 && tid > 0 && pid == tid;
+#endif
 }
 
 // A brief refresher on GLib:
