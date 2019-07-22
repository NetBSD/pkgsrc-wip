$NetBSD$

--- vm/src/unix/os/sig_unix.hh.orig	2019-07-22 01:11:46.000000000 +0000
+++ vm/src/unix/os/sig_unix.hh
@@ -42,7 +42,8 @@
 // So we use common code for both platforms as much as possible. -mabdelmalek 10/02
 # if  TARGET_OS_VERSION == SOLARIS_VERSION  \
   ||  TARGET_OS_VERSION ==  MACOSX_VERSION  \
-  ||  TARGET_OS_VERSION ==   LINUX_VERSION
+  ||  TARGET_OS_VERSION ==   LINUX_VERSION  \
+  ||  TARGET_OS_VERSION ==  NETBSD_VERSION
    static int install_flags() { return SA_ONSTACK | SA_SIGINFO | SA_RESTART; }
 # elif TARGET_OS_VERSION == SUNOS_VERSION
    static int install_flags() { return SA_ONSTACK; /* ! SA_INTERRUPT */ }
