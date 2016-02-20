$NetBSD$

--- src/pal/src/thread/thread.cpp.orig	2016-02-17 20:49:34.000000000 +0000
+++ src/pal/src/thread/thread.cpp
@@ -1168,7 +1168,7 @@ CorUnix::InternalSetThreadPriority(
     {
         goto InternalSetThreadPriorityExit;
     }
-        
+
     pTargetThread->Lock(pThread);
 
     /* validate the requested priority */
@@ -1219,6 +1219,17 @@ CorUnix::InternalSetThreadPriority(
         goto InternalSetThreadPriorityExit;
     }
 
+#if !HAVE_SCHED_OTHER_ASSIGNABLE
+    /* Defining thread priority for SCHED_OTHER is implementation defined.
+       Some platforms like NetBSD cannot reassign it as they are dynamic.
+    */
+    if (policy == SCHED_OTHER)
+    {
+        TRACE("Pthread priority levels for SCHED_OTHER cannot be reassigned on this platform\n");
+        goto InternalSetThreadPriorityExit;
+    }
+#endif
+
 #if HAVE_SCHED_GET_PRIORITY
     max_priority = sched_get_priority_max(policy);
     min_priority = sched_get_priority_min(policy);
