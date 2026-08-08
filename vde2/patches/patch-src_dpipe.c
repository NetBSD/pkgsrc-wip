$NetBSD$

setpgrp() without args is System V-style.

--- src/dpipe.c.orig	2026-08-03 10:48:09.000000000 +0000
+++ src/dpipe.c
@@ -201,7 +201,11 @@ int main(int argc, char *argv[]) 
 
 	if (daemonize != 0)
 		daemon(0,0);
+#if VDE_NETBSD
+	else if (setpgid(0, 0) == -1) {
+#else
 	else if (setpgrp() == -1) {
+#endif
 		fprintf(stderr,"Err: cannot create pgrp\n");
 		perror("setpgrp");
 		exit(1);
