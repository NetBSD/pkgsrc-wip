$NetBSD$

Handle NetBSD's signature for pthread_setname_np().
--- sophia/std/ss_thread.c.orig	2021-05-11 22:17:18.146851368 -0700
+++ sophia/std/ss_thread.c	2021-05-11 22:19:13.344406344 -0700
@@ -59,6 +59,8 @@
 	#if defined(__APPLE__)
 		(void)t;
 		return pthread_setname_np(name);
+	#elif defined(__NetBSD__)
+		return pthread_setname_np(t->id, name, NULL);
 	#else
 		return pthread_setname_np(t->id, name);
 	#endif
