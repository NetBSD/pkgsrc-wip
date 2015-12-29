$NetBSD$

Adjust usage of pthread_setname_np(3).

--- common/threads.c.orig	2015-12-10 12:45:30.000000000 +0000
+++ common/threads.c
@@ -497,7 +497,9 @@ extern inline void alcall_once(alonce_fl
 void althrd_setname(althrd_t thr, const char *name)
 {
 #if defined(HAVE_PTHREAD_SETNAME_NP)
-#if defined(__GNUC__)
+#if defined(__NetBSD__)
+    pthread_setname_np(thr, "%s", name);
+#elif defined(__GNUC__)
     pthread_setname_np(thr, name);
 #elif defined(__APPLE__)
     if(althrd_equal(thr, althrd_current())
