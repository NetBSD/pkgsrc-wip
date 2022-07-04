$NetBSD$

--- src/hre/hre_pthread.c.orig	2018-07-03 19:28:10.000000000 +0000
+++ src/hre/hre_pthread.c
@@ -255,12 +255,20 @@ create_shared_region(size_t size, bool p
     }
     int flag = public ? PTHREAD_PROCESS_SHARED : PTHREAD_PROCESS_PRIVATE;
     pthread_mutexattr_init(&shared->mutexattr);
+#ifndef __NetBSD__
     if (pthread_mutexattr_setpshared(&shared->mutexattr, flag)){
+#else
+    if (1) {
+#endif
         AbortCall("pthread_mutexattr_setpshared");
     }
     pthread_mutex_init(&shared->mutex,&shared->mutexattr);
     pthread_condattr_init(&shared->condattr);
+#ifndef __NetBSD__
     if (pthread_condattr_setpshared(&shared->condattr, flag)){
+#else
+    if (1) {
+#endif
         AbortCall("pthread_condattr_setpshared");
     }
     return shared;
@@ -583,7 +591,11 @@ void HREenableFork(int procs, bool selec
     Debug("Enabling process runtime environment.");
     pthread_condattr_t attr;
     pthread_condattr_init(&attr);
+#ifndef __NetBSD__
     int res=pthread_condattr_setpshared(&attr,PTHREAD_PROCESS_SHARED);
+#else
+    int res = 1;
+#endif
     pthread_condattr_destroy(&attr);
     if (res){
         Warning(infoLong,"multi-process disabled: inter process locks are not supported");
