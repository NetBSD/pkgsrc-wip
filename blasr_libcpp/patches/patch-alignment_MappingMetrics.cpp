$NetBSD: patch-alignment_MappingMetrics.cpp,v 1.1 2015/09/16 02:36:53 outpaddling Exp $

--- alignment/MappingMetrics.cpp.orig	2015-08-12 17:41:23.000000000 +0000
+++ alignment/MappingMetrics.cpp
@@ -34,6 +34,7 @@ int clock_gettime(clockid_t clk_id, stru
                 retval = -1;
             }
             break;
+#ifndef __NetBSD__
         case CLOCK_PROCESS_CPUTIME_ID:
         case CLOCK_THREAD_CPUTIME_ID:
             start = mach_absolute_time();
@@ -52,6 +53,7 @@ int clock_gettime(clockid_t clk_id, stru
             tp->tv_nsec = nano - (tp->tv_sec * 1e9);
             retval = 0;
             break;
+#endif
         default:
             errno = EINVAL;
             retval = -1;
