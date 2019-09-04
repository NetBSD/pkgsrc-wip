$NetBSD$

This patch makes calls to setfdlimit() behave as NOP, setrlimit() is not
called, if the new limit is lower than the current limit.

--- lib/fdlimit.c.orig	2019-02-07 15:02:22.000000000 +0000
+++ lib/fdlimit.c
@@ -60,6 +60,10 @@ setfdlimit(unsigned int limit)
     }
 #endif
 
+    /* will we mind if the limit is higher? I think not. */
+    if (rl.rlim_cur >= limit)
+	return 0;
+
     rl.rlim_cur = limit;
     if (limit > rl.rlim_max)
         rl.rlim_max = limit;
