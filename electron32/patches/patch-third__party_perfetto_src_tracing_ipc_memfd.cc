$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/perfetto/src/tracing/ipc/memfd.cc.orig	2024-10-18 12:40:29.062311200 +0000
+++ third_party/perfetto/src/tracing/ipc/memfd.cc
@@ -20,7 +20,8 @@
 
 #define PERFETTO_MEMFD_ENABLED()             \
   PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-      PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
+      (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && \
+      !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD))
 
 #if PERFETTO_MEMFD_ENABLED()
 
