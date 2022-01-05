$NetBSD$

Tentatively fix the build for NetBSD

--- src/folder.c.orig	2022-01-05 22:09:38.453961988 +0000
+++ src/folder.c
@@ -43,8 +43,9 @@ static int get_exec_path (char *exec_pat
 
   const size_t len = strlen (exec_path);
 
-  #elif defined (__FreeBSD__)
+  #elif defined (__FreeBSD__) || defined (__NetBSD__)
 
+  #include <sys/param.h>
   #include <sys/sysctl.h>
 
   int mib[4];
