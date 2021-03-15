$NetBSD$

--- src/3rdparty/chromium/services/tracing/public/cpp/perfetto/trace_time.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/services/tracing/public/cpp/perfetto/trace_time.h
@@ -10,7 +10,7 @@
 
 namespace tracing {
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Linux, Android, and Fuchsia all use CLOCK_MONOTONIC. See crbug.com/166153
 // about efforts to unify base::TimeTicks across all platforms.
 constexpr perfetto::protos::pbzero::ClockSnapshot::Clock::BuiltinClocks
