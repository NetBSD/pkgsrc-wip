$NetBSD: patch-pr_include_private_pprthred.h,v 1.1 2014/09/28 14:14:58 thomasklausner Exp $

--- pr/include/private/pprthred.h.orig	2014-09-28 14:07:42.000000000 +0000
+++ pr/include/private/pprthred.h
@@ -19,6 +19,8 @@
 #include <os2.h>
 #endif
 
+#include <pthread.h>
+
 PR_BEGIN_EXTERN_C
 
 /*---------------------------------------------------------------------------
@@ -59,7 +61,7 @@ NSPR_API(void) PR_DetachThread(void);
 ** Get the id of the named thread. Each thread is assigned a unique id
 ** when it is created or attached.
 */
-NSPR_API(PRUint32) PR_GetThreadID(PRThread *thread);
+NSPR_API(pthread_t) PR_GetThreadID(PRThread *thread);
 
 /*
 ** Set the procedure that is called when a thread is dumped. The procedure
