$NetBSD$

--- server/red-worker.cpp.orig	2023-05-12 08:37:06.000000000 +0000
+++ server/red-worker.cpp
@@ -1049,7 +1049,9 @@ bool red_worker_run(RedWorker *worker)
 #ifndef _WIN32
     pthread_sigmask(SIG_SETMASK, &curr_sig_mask, nullptr);
 #endif
-#if !defined(__APPLE__)
+#if defined(__NetBSD__)
+    pthread_setname_np(worker->thread, "%s", (void *)"SPICE Worker");
+#elif !defined(__sun) && !defined(__APPLE__)
     pthread_setname_np(worker->thread, "SPICE Worker");
 #endif
 
