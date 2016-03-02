$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/ioctl.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/ioctl.d
@@ -359,6 +359,18 @@ else version (FreeBSD)
 
     int ioctl(int, c_ulong, ...);
 }
+else version (NetBSD)
+{
+    struct winsize
+    {
+        ushort ws_row;
+        ushort ws_col;
+        ushort ws_xpixel;
+        ushort ws_ypixel;
+    }
+
+    int ioctl(int, c_ulong, ...);
+}
 else version (Solaris)
 {
     int ioctl(int fildes, int request, ...);
