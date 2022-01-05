$NetBSD$

Fix the build for NetBSD

--- src/folder.c.orig	2022-01-05 22:09:38.453961988 +0000
+++ src/folder.c
@@ -13,6 +13,9 @@
 
 #if defined (__APPLE__)
 #include "event.h"
+#elif defined (__FreeBSD__) || defined (__NetBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
 #endif
 
 static int get_exec_path (char *exec_path, const size_t exec_path_sz)
@@ -43,9 +46,7 @@ static int get_exec_path (char *exec_pat
 
   const size_t len = strlen (exec_path);
 
-  #elif defined (__FreeBSD__)
-
-  #include <sys/sysctl.h>
+  #elif defined (__FreeBSD__) || defined (__NetBSD__)
 
   int mib[4];
 
