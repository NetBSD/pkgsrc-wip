$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/utime.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/utime.d
@@ -65,6 +65,16 @@ else version( FreeBSD )
 
     int utime(in char*, in utimbuf*);
 }
+else version( NetBSD )
+{
+    struct utimbuf
+    {
+        time_t  actime;
+        time_t  modtime;
+    }
+
+    int utime(in char*, in utimbuf*);
+}
 else version( Solaris )
 {
     struct utimbuf
