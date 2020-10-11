$NetBSD$

	As NetBSD currently (2020) implements
	posix_fallocate() but no file system supports it
	we need to stay away from posix_fallocate.
	Additionally the present frr code relies on
	negative errnos (as found e.g. in Linux) and
	also did not find in the manual that
	posix_fallocate() return the errno and does not set 
	errno.

--- lib/zlog.c.orig	2020-06-30 11:08:57.000000000 +0000
+++ lib/zlog.c
@@ -245,7 +246,7 @@ void zlog_tls_buffer_init(void)
 	}
 	fchown(mmfd, zlog_uid, zlog_gid);
 
-#ifdef HAVE_POSIX_FALLOCATE
+#if defined(HAVE_POSIX_FALLOCATE) && !defined(__NetBSD__)
 	if (posix_fallocate(mmfd, 0, TLS_LOG_BUF_SIZE) < 0) {
 #else
 	if (ftruncate(mmfd, TLS_LOG_BUF_SIZE) < 0) {
