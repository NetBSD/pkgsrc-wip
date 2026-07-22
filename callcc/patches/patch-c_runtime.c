$NetBSD$

Only use CLOCK_TAI (International Atomic Time) if it is available,
otherwise fall back to CLOCK_REALTIME.

--- c/runtime.c.orig	2026-07-21 21:08:06.697230118 +0000
+++ c/runtime.c
@@ -2088,7 +2088,11 @@ gc_obj SCM_CURRENT_SECOND() {
 
 gc_obj SCM_CURRENT_SECOND() {
   struct timespec ts;
+#ifdef CLOCK_TAI
   clock_gettime(CLOCK_TAI, &ts);
+#else
+  clock_gettime(CLOCK_REALTIME, &ts);
+#endif
   double offset = 37; // TODO should be based on leap seconds.
   double f = (double)ts.tv_sec + ((double)ts.tv_nsec / 1000000000.0) + offset;
   return double_to_gc_slow(f);
