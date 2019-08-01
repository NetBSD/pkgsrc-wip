$NetBSD$

If sched_get_priority_{min,max} error, don't try to set a priority.
NetBSD doesn't like SCHED_OTHER + 0 priority, and will error here.

https://github.com/mono/mono/pull/15898

--- mono/metadata/threads.c.orig	2019-07-18 07:46:08.000000000 +0000
+++ mono/metadata/threads.c
@@ -740,6 +740,10 @@ mono_thread_internal_set_priority (MonoI
 #else
 	min = sched_get_priority_min (policy);
 	max = sched_get_priority_max (policy);
+
+	/* Not tunable. Bail out */
+	if ((min == -1) || (max == -1))
+		return;
 #endif
 	MONO_EXIT_GC_SAFE;
 
