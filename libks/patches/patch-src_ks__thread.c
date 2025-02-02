$NetBSD$

Add extra field required by pthread_setname_np.

--- src/ks_thread.c.orig	2024-07-23 20:48:07.000000000 +0000
+++ src/ks_thread.c
@@ -169,7 +169,7 @@ static void *KS_THREAD_CALLING_CONVENTIO
 		pthread_setname_np(thread->tag);
 #else
 	if (thread->tag && pthread_setname_np)
-		pthread_setname_np(pthread_self(), thread->tag);
+		pthread_setname_np(pthread_self(), thread->tag, NULL);
 #endif
 
 	ks_log(KS_LOG_DEBUG, "START call user thread callback with address: %p, tid: %8.8x\n", (void *)thread, thread->id);
