$NetBSD: patch-gnuradio_runtime_lib_high__res__timer.cc,v 1.1 2014/08/31 14:20:09 makoto Exp $

This patch is kind of joke, but better than nothing for packaging

--- gnuradio-runtime/lib/high_res_timer.cc~	2013-08-29 03:27:03.000000000 +0900
+++ gnuradio-runtime/lib/high_res_timer.cc	2014-08-31 21:42:54.000000000 +0900
@@ -1,6 +1,7 @@
 #include <gnuradio/high_res_timer.h>
 
 #ifdef GNURADIO_HRT_USE_CLOCK_GETTIME
+#define CLOCK_THREAD_CPUTIME_ID 3
 clockid_t gr::high_res_timer_source = CLOCK_THREAD_CPUTIME_ID;
 #endif
 
