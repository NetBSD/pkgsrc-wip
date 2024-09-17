$NetBSD$

Unavailable header file on NetBSD...

--- ./lib/src/clixon_proc.c.orig	2024-09-17 11:46:41.479459341 +0000
+++ ./lib/src/clixon_proc.c
@@ -105,7 +105,9 @@
 #include <sys/socket.h>
 #include <sys/wait.h>
 #include <sys/param.h>
+#ifndef __NetBSD__
 #include <sys/user.h>
+#endif
 #include <sys/time.h>
 #include <sys/resource.h>
 
