$NetBSD$

* Support NetBSD

--- src/main.c.orig	2014-10-16 13:17:48.000000000 +0000
+++ src/main.c
@@ -150,7 +150,7 @@ static void set_signal_handlers(void)
 	sigaction(SIGUSR2, &sa, NULL);
 }
 
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 static int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *timeout, const sigset_t *sigmask)
 {
 	int ready;
