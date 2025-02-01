$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/event_fd.cc.orig	2025-01-27 17:37:37.000000000 +0000
+++ third_party/perfetto/src/base/event_fd.cc
@@ -22,7 +22,8 @@
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
 #include <Windows.h>
 #include <synchapi.h>
-#elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#elif (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/eventfd.h>
 #include <unistd.h>
@@ -57,7 +58,8 @@ void EventFd::Clear() {
     PERFETTO_DFATAL("EventFd::Clear()");
 }
 
-#elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#elif (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 
 EventFd::EventFd() {
