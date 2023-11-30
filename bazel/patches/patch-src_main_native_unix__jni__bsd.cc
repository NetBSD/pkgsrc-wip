$NetBSD$

--- src/main/native/unix_jni_bsd.cc.orig	2023-11-28 16:43:12.878427212 +0000
+++ src/main/native/unix_jni_bsd.cc
@@ -15,6 +15,8 @@
 #if defined(__FreeBSD__)
 # define HAVE_EXTATTR
 # define HAVE_SYSCTLBYNAME
+#elif defined(__NetBSD__)
+// XXX
 #elif defined(__OpenBSD__)
 // No sys/extattr.h or sysctlbyname on this platform.
 #else
