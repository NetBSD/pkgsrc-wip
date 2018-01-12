$NetBSD$

--- lib/sanitizer_common/sanitizer_linux.cc.orig	2017-12-21 18:53:10.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux.cc
@@ -89,6 +89,7 @@ extern char **environ;  // provided by c
 
 #if SANITIZER_NETBSD
 #include <limits.h>  // For NAME_MAX
+#define sysctl _sysctl
 #include <sys/sysctl.h>
 extern char **environ;  // provided by crt1
 #include <sys/exec.h>
@@ -1898,4 +1899,3 @@ bool GetRandom(void *buffer, uptr length
 
 #endif  // SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD ||
         // SANITIZER_SOLARIS
-
