$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/netinet/tcp.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/netinet/tcp.d
@@ -38,6 +38,10 @@ else version( FreeBSD )
 {
     enum TCP_NODELAY = 1;
 }
+else version( NetBSD )
+{
+    enum TCP_NODELAY = 1;
+}
 else version( Solaris )
 {
     enum TCP_NODELAY = 1;
