$NetBSD$

F_SETSIG is not portable, add hacky workaround.

--- sys.c.orig	2026-02-11 21:09:41.513072679 +0000
+++ sys.c
@@ -322,7 +322,11 @@ static int sys_setsig(int fd, int sig)
 {
 	int rc;
 
+#ifdef F_SETSIG
 	rc = fcntl(fd, F_SETSIG, sig);
+#else
+	rc = -1;
+#endif
 	if (rc == -1) {
 		sys_errno("fcntl(%d, F_SETSIG, %d (%s))", fd, sig,
 			  strsignal(sig));
