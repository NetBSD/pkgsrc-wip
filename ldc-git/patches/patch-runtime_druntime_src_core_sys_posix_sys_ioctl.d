$NetBSD$

--- runtime/druntime/src/core/sys/posix/sys/ioctl.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/ioctl.d
@@ -359,6 +359,10 @@ else version (FreeBSD)
 
     int ioctl(int, c_ulong, ...);
 }
+else version( NetBSD )
+{
+  //Nothing here yet.
+}
 else version (Solaris)
 {
     int ioctl(int fildes, int request, ...);
