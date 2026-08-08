$NetBSD$

Add NetBSD.

--- src/vde_switch/datasock.c.orig	2026-08-03 10:48:09.000000000 +0000
+++ src/vde_switch/datasock.c
@@ -90,7 +90,7 @@ static int send_datasock(int fd_ctl, int
 {
 	while (send(fd_data, packet, len, 0) < 0) {
 		int rv=errno;
-#if defined(VDE_DARWIN) || defined(VDE_FREEBSD)
+#if defined(VDE_DARWIN) || defined(VDE_FREEBSD) || defined(VDE_NETBSD)
 		if(rv == ENOBUFS) {
 			sched_yield();
 			continue;
