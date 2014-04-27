$NetBSD: patch-Source_autotools_FindDependencies.m4,v 1.1 2014/04/27 10:05:23 leot1990 Exp $

NetBSD-6.* does not have shm_open().
https://bugs.webkit.org/show_bug.cgi?id=129973

--- Source/autotools/FindDependencies.m4.orig	2014-04-14 06:40:46.000000000 +0000
+++ Source/autotools/FindDependencies.m4
@@ -526,7 +526,7 @@ if test "$enable_webkit2" = "yes"; then
     AC_SUBST(GTK_UNIX_PRINTING_LIBS)
 
     # On some Linux/Unix platforms, shm_* may only be available if linking against librt
-    if test "$os_win32" = "no"; then
+    if test "$os_win32" = "no" && test "$os_openbsd" = "no" && test "$os_netbsd" = "no"; then
         AC_SEARCH_LIBS([shm_open], [rt], [SHM_LIBS="-lrt"])
         AC_SUBST(SHM_LIBS)
     fi
