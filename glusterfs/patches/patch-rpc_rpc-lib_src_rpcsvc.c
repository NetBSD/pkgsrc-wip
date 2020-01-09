$NetBSD$

--- rpc/rpc-lib/src/rpcsvc.c.orig	2019-12-23 05:13:32.107572504 +0000
+++ rpc/rpc-lib/src/rpcsvc.c
@@ -2288,11 +2288,21 @@ rpcsvc_program_register(rpcsvc_t *svc, r
 
     INIT_LIST_HEAD(&newprog->program);
     pthread_mutexattr_init(&thr_attr);
+
+#if defined(__NetBSD__)
+    pthread_mutexattr_settype(&thr_attr, PTHREAD_MUTEX_NORMAL);
+#else
     pthread_mutexattr_settype(&thr_attr, PTHREAD_MUTEX_ADAPTIVE_NP);
+#endif
 
     for (i = 0; i < EVENT_MAX_THREADS; i++) {
         pthread_mutexattr_init(&attr[i]);
+
+#if defined(__NetBSD__)
+        pthread_mutexattr_settype(&attr[i], PTHREAD_MUTEX_NORMAL);
+#else
         pthread_mutexattr_settype(&attr[i], PTHREAD_MUTEX_ADAPTIVE_NP);
+#endif 
         INIT_LIST_HEAD(&newprog->request_queue[i].request_queue);
         pthread_mutex_init(&newprog->request_queue[i].queue_lock, &attr[i]);
         pthread_cond_init(&newprog->request_queue[i].queue_cond, NULL);
