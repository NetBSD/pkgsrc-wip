$NetBSD$

Don't know how to do this so bail if actually called
on NetBSD

--- src/timerfd.c.orig	2016-12-20 21:20:05.000000000 +0000
+++ src/timerfd.c
@@ -9,7 +9,9 @@
 #include <sys/time.h>
 
 #include <pthread.h>
+#ifndef __NetBSD__
 #include <pthread_np.h>
+#endif
 
 #include <errno.h>
 #include <signal.h>
@@ -53,6 +55,7 @@ get_timerfd_context(int fd, bool create_
 	return NULL;
 }
 
+#ifndef __NetBSD__
 static void *
 worker_function(void *arg)
 {
@@ -81,6 +84,7 @@ worker_function(void *arg)
 
 	return NULL;
 }
+#endif
 
 static int
 timerfd_create_impl(int clockid, int flags)
@@ -104,6 +108,9 @@ timerfd_create_impl(int clockid, int fla
 		return -1;
 	}
 
+#ifdef __NetBSD__
+	abort();
+#else
 	ctx->flags = flags;
 
 	struct kevent kev;
@@ -142,6 +149,7 @@ timerfd_create_impl(int clockid, int fla
 		ctx->fd = -1;
 		return -1;
 	}
+#endif
 
 	return ctx->fd;
 }
