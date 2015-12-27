$NetBSD$

--- cherokee/main_admin.c.orig	2014-10-17 17:20:36.000000000 +0000
+++ cherokee/main_admin.c
@@ -556,7 +556,7 @@ check_for_python (void)
 	int         re;
 	pid_t       pid;
 	int         exitcode = -1;
-	char const *args[]   = {"env", "python2", "-c", "raise SystemExit", NULL};
+	char const *args[]   = {"env", "python", "-c", "raise SystemExit", NULL};
 
 	pid = fork();
 	if (pid == -1) {
