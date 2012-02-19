$NetBSD: patch-src_main.c,v 1.1.1.1 2012/02/19 19:25:49 khorben Exp $

--- src/main.c.orig	2012-02-14 19:36:01.000000000 +0000
+++ src/main.c
@@ -31,6 +31,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <fcntl.h>
+#include <signal.h>
 
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
@@ -315,6 +316,12 @@ void SetupEnvironment(WScreen * scr)
 {
 	char *tmp, *ptr;
 	char buf[16];
+	struct sigaction sa;
+
+	sa.sa_handler = SIG_DFL;
+	sigemptyset(&sa.sa_mask);
+	/* sa.sa_mask = 0; */
+	sigaction(SIGPIPE, &sa, NULL);
 
 	if (multiHead) {
 		int len = strlen(DisplayName) + 64;
