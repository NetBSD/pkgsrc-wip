$NetBSD$

Build fix for NetBSD

--- src/platform/posix/posix_thread.c.orig	2021-02-08 01:38:21.000000000 +0000
+++ src/platform/posix/posix_thread.c
@@ -262,6 +262,12 @@ nni_plat_thr_set_name(nni_plat_thr *thr,
 	if ((thr == NULL) || (pthread_self() == thr->tid)) {
         	pthread_setname_np(name);
 	}
+#elif defined(__NetBSD__)
+	if (thr == NULL) {
+		pthread_setname_np(pthread_self(), "%s", name);
+	} else {
+		pthread_setname_np(thr->tid, "%s", name);
+	}
 #else
 	if (thr == NULL) {
 		pthread_setname_np(pthread_self(), name);
