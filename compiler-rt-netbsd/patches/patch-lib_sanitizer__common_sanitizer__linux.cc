$NetBSD$

--- lib/sanitizer_common/sanitizer_linux.cc.orig	2018-02-25 10:48:27.592535426 +0000
+++ lib/sanitizer_common/sanitizer_linux.cc
@@ -89,6 +89,7 @@ extern char **environ;  // provided by c
 
 #if SANITIZER_NETBSD
 #include <limits.h>  // For NAME_MAX
+#define sysctl _sysctl
 #include <sys/sysctl.h>
 extern char **environ;  // provided by crt1
 #include <sys/exec.h>
