$NetBSD$

CLOCK_MONOTONIC_RAW is not portable.

--- src/panfrost/perf/pan_perf.h.orig	2026-09-07 03:49:04.002533916 +0000
+++ src/panfrost/perf/pan_perf.h
@@ -48,7 +48,11 @@ pan_perf_gpu_clock_id(const struct pan_perf *perf)
 static inline clockid_t
 pan_perf_gpu_clock_id(const struct pan_perf *perf)
 {
+#ifdef CLOCK_MONOTONIC_RAW
    return CLOCK_MONOTONIC_RAW;
+#else
+   return CLOCK_MONOTONIC;
+#endif
 }
 
 static inline uint64_t
