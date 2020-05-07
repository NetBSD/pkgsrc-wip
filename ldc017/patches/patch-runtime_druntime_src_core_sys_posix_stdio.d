$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/stdio.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/stdio.d
@@ -272,6 +272,10 @@ version( FreeBSD )
 {
     enum P_tmpdir  = "/var/tmp/";
 }
+version( NetBSD )
+{
+    enum P_tmpdir  = "/var/tmp/";
+}
 version( Solaris )
 {
     enum P_tmpdir  = "/var/tmp/";
