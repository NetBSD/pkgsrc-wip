$NetBSD$

--- src/libs/xpcom18a4/nsprpub/pr/include/md/_pth.h.orig	2018-12-18 13:01:23.000000000 +0000
+++ src/libs/xpcom18a4/nsprpub/pr/include/md/_pth.h
@@ -231,7 +231,7 @@
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #endif /* defined(_PR_DCETHREADS) */
 
-#elif defined(LINUX) || defined(FREEBSD)
+#elif defined(LINUX) || defined(FREEBSD) || defined(NETBSD)
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #elif defined(NTO)
