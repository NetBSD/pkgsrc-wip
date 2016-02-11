$NetBSD$

--- runtime/druntime/src/core/sys/posix/sys/select.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/sys/posix/sys/select.d
@@ -218,6 +218,43 @@ else version( FreeBSD )
     int pselect(int, fd_set*, fd_set*, fd_set*, in timespec*, in sigset_t*);
     int select(int, fd_set*, fd_set*, fd_set*, timeval*);
 }
+else version ( NetBSD )
+{
+    alias uint __fd_mask;
+
+    enum __NFDBITS = 32;
+    /* Note: FD_SETSIZE may be defined by the user.
+       This is the default value. */
+    enum FD_SETSIZE = 256;
+
+    pure auto __NFD_LEN(long a) {
+        return (a + __NFDBITS - 1) / __NFDBITS;
+    }
+    enum __NFD_SIZE = __NFD_LEN(FD_SETSIZE);
+
+    struct fd_set {
+        __fd_mask[__NFD_SIZE] fds_bits;
+    }
+
+//
+// Required
+//
+/*
+NOTE: This module requires timeval from core.sys.posix.sys.time, but timeval
+      is supposedly an XOpen extension.  As a result, this header will not
+      compile on platforms that are not XSI-compliant.  This must be resolved
+      on a per-platform basis.
+
+void FD_CLR(int fd, fd_set* fdset);
+int FD_ISSET(int fd, const(fd_set)* fdset);
+void FD_SET(int fd, fd_set* fdset);
+void FD_ZERO(fd_set* fdset);
+
+int  pselect(int, fd_set*, fd_set*, fd_set*, in timespec*, in sigset_t*);
+int  select(int, fd_set*, fd_set*, fd_set*, timeval*);
+*/
+
+}
 else version (Solaris)
 {
     private
