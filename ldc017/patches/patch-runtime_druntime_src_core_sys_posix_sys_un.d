$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/un.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/un.d
@@ -60,6 +60,15 @@ else version( FreeBSD )
         byte[104]   sun_path;
     }
 }
+else version( NetBSD )
+{
+    struct sockaddr_un
+    {
+        ubyte       sun_len;
+        sa_family_t sun_family;
+        byte[104]   sun_path;
+    }
+}
 else version( Solaris )
 {
     struct sockaddr_un
