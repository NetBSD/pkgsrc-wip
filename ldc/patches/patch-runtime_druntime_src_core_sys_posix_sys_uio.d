$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/sys/uio.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/uio.d
@@ -70,6 +70,17 @@ else version( FreeBSD )
     ssize_t readv(int, in iovec*, int);
     ssize_t writev(int, in iovec*, int);
 }
+else version( NetBSD )
+{
+    struct iovec
+    {
+        void*  iov_base;
+        size_t iov_len;
+    }
+
+    ssize_t readv(int, in iovec*, int);
+    ssize_t writev(int, in iovec*, int);
+}
 else version (Solaris)
 {
     struct iovec
