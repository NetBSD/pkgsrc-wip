$NetBSD: patch-pr_src_pthreads_ptthread.c,v 1.2 2014/10/04 11:54:48 thomasklausner Exp $

pthread_t is too big for PRUint32.
https://bugzilla.mozilla.org/show_bug.cgi?id=953413

Use appropriate thread naming function on FreeBSD, NetBSD, and OpenBSD.

--- pr/src/pthreads/ptthread.c.orig	2016-02-02 13:10:25.000000000 +0000
+++ pr/src/pthreads/ptthread.c
@@ -1159,12 +1159,12 @@ PR_IMPLEMENT(void) PR_ProcessExit(PRIntn
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
 
