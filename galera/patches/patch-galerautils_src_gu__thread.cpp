$NetBSD$

Improve NetBSD support.

--- galerautils/src/gu_thread.cpp.orig	2022-11-02 06:09:14.000000000 +0000
+++ galerautils/src/gu_thread.cpp
@@ -89,6 +89,13 @@ void gu::thread_set_schedparam(pthread_t
 #else
     struct sched_param spstr = { sp.prio() };
 #endif
+#if defined(__NetBSD__)
+    if (sp.policy() == SCHED_OTHER)
+    {
+        /* NetBSD does not allow setting priorities for SCHED_OTHER */
+        return;
+    }
+#endif
     int err;
     if ((err = pthread_setschedparam(thd, sp.policy(), &spstr)) != 0)
     {
