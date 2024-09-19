$NetBSD$

"sched_setscheduler: Operation not permitted"

--- realtime.c.orig	2018-01-19 20:40:49.000000000 +0000
+++ realtime.c
@@ -38,6 +38,7 @@
 
 static int raise_priority(int priority)
 {
+#ifndef __NetBSD__
     int max_pri;
     struct sched_param sp;
 
@@ -60,7 +61,7 @@ static int raise_priority(int priority)
         fprintf(stderr, "Failed to get realtime priorities\n");
         return -1;
     }
-
+#endif
     return 0;
 }
 
