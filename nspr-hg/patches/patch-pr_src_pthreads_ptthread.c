$NetBSD: patch-pr_src_pthreads_ptthread.c,v 1.2 2014/10/04 11:54:48 thomasklausner Exp $

pthread_t is too big for PRUint32.
https://bugzilla.mozilla.org/show_bug.cgi?id=953413

Use appropriate thread naming function on FreeBSD, NetBSD, and OpenBSD.

--- pr/src/pthreads/ptthread.c.orig	2014-09-28 14:07:42.000000000 +0000
+++ pr/src/pthreads/ptthread.c
@@ -21,6 +21,10 @@
 #include <signal.h>
 #include <dlfcn.h>
 
+#if defined(OPENBSD) || defined(FREEBSD) || defined(DRAGONFLY)
+#include <pthread_np.h>
+#endif
+
 #ifdef SYMBIAN
 /* In Open C sched_get_priority_min/max do not work properly, so we undefine
  * _POSIX_THREAD_PRIORITY_SCHEDULING here.
@@ -1153,12 +1157,12 @@ PR_IMPLEMENT(void) PR_ProcessExit(PRIntn
     _exit(status);
 }
 
-PR_IMPLEMENT(PRUint32) PR_GetThreadID(PRThread *thred)
+PR_IMPLEMENT(pthread_t) PR_GetThreadID(PRThread *thred)
 {
 #if defined(_PR_DCETHREADS)
     return (PRUint32)&thred->id;  /* this is really a sham! */
 #else
-    return (PRUint32)thred->id;  /* and I don't know what they will do with it */
+    return thred->id;  /* and I don't know what they will do with it */
 #endif
 }
 
@@ -1731,7 +1735,7 @@ PR_IMPLEMENT(PRStatus) PR_SetCurrentThre
 {
     PRThread *thread;
     size_t nameLen;
-    int result;
+    int result = 0;
 
     if (!name) {
         PR_SetError(PR_INVALID_ARGUMENT_ERROR, 0);
@@ -1749,8 +1753,10 @@ PR_IMPLEMENT(PRStatus) PR_SetCurrentThre
         return PR_FAILURE;
     memcpy(thread->name, name, nameLen + 1);
 
-#if defined(OPENBSD) || defined(FREEBSD)
-    result = pthread_set_name_np(thread->id, name);
+#if defined(OPENBSD) || defined(FREEBSD) || defined(DRAGONFLY)
+    pthread_set_name_np(thread->id, name);
+#elif defined(NETBSD)
+    pthread_setname_np(thread->id, "%s", (void *)name);
 #else /* not BSD */
     /*
      * On OSX, pthread_setname_np is only available in 10.6 or later, so test
