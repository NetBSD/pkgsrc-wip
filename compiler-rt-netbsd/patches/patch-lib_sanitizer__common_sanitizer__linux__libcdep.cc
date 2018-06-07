$NetBSD$

--- lib/sanitizer_common/sanitizer_linux_libcdep.cc.orig	2018-05-10 23:16:36.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux_libcdep.cc
@@ -47,6 +47,7 @@
 #endif
 
 #if SANITIZER_NETBSD
+#define sysctl _sysctl
 #include <sys/sysctl.h>
 #include <sys/tls.h>
 #endif
