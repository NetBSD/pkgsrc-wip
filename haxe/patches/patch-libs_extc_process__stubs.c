$NetBSD$

NetBSD support

--- libs/extc/process_stubs.c.orig	2019-10-25 23:09:16.000000000 +0000
+++ libs/extc/process_stubs.c
@@ -37,7 +37,8 @@
 #	include <errno.h>
 #	include <string.h>
 #	ifndef __APPLE__
-#		if defined(__FreeBSD__) || defined(__DragonFly__)
+#		if defined(__FreeBSD__) || defined(__DragonFly__) \
+		|| defined(__NetBSD__)
 #			include <sys/wait.h>
 #		else
 #			include <wait.h>
