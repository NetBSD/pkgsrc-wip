$NetBSD$

--- src/timer_clockgettime.c.orig	2019-01-21 13:50:43.000000000 +0000
+++ src/timer_clockgettime.c
@@ -75,16 +75,24 @@ static struct fakeclock* clkid_to_fakecl
 	switch(clk_id) {
 	case CLOCK_REALTIME:
 		return &realtime;
+#ifdef CLOCK_REALTIME_COARSE
 	case CLOCK_REALTIME_COARSE:
 		return &realtime_coarse;
+#endif
 	case CLOCK_MONOTONIC:
 		return &mono;
+#ifdef CLOCK_REALTIME_COARSE
 	case CLOCK_MONOTONIC_COARSE:
 		return &mono_coarse;
+#endif
+#ifdef CLOCK_MONOTONIC_RAW
 	case CLOCK_MONOTONIC_RAW:
 		return &mono_raw;
+#endif
+#ifdef CLOCK_BOOTTIME
 	case CLOCK_BOOTTIME:
 		return &boottime;
+#endif
 	case CLOCK_PROCESS_CPUTIME_ID:
 		return &proc_cputime_id;
 	case CLOCK_THREAD_CPUTIME_ID:
