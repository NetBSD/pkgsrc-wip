$NetBSD$

* Fix warning: `noreturn function does return' in devpubd_eventloop().
* Fix uninitialized variable. 

--- devpubd.c.orig	2025-08-19 18:13:10.000000000 +0000
+++ devpubd.c
@@ -285,14 +285,15 @@ devpubd_eventhandler(const char *event, 
 	free(argv);
 }
 
-__dead static void
+static void
 devpubd_eventloop(void)
 {
 	const char *event, *device[2], *parent;
 	prop_dictionary_t ev;
-	int res, max_fd, rv, a = 0;
+	int res, rv, a = 0;
 	struct timeval tv;
 	fd_set fds;
+	int max_fd = 0;
 	int reported = 0;
 	int reject = 0;
 
