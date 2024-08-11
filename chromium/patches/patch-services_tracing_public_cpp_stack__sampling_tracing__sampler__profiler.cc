$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc.orig	2024-07-24 02:44:43.873482500 +0000
+++ services/tracing/public/cpp/stack_sampling/tracing_sampler_profiler.cc
@@ -38,7 +38,7 @@
 #include "third_party/perfetto/protos/perfetto/trace/track_event/process_descriptor.pbzero.h"
 #include "third_party/perfetto/protos/perfetto/trace/track_event/thread_descriptor.pbzero.h"
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 #include "base/profiler/thread_delegate_posix.h"
 #define INITIALIZE_THREAD_DELEGATE_POSIX 1
 #else  // BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_APPLE)
