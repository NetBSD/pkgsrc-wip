$NetBSD: patch-programs_dtsearchpath_libCliSrv_UnixEnv.C,v 1.2 2014/07/23 10:07:43 obache Exp $

--- programs/dtsearchpath/libCliSrv/UnixEnv.C.orig	2014-03-01 22:48:49.000000000 +0000
+++ programs/dtsearchpath/libCliSrv/UnixEnv.C
@@ -85,7 +85,7 @@ UnixEnvironment::UnixEnvironment()
 #elif defined(__FreeBSD__)
 	manpath = "/usr/share/man:/usr/local/man";
 #elif defined(__NetBSD__)
-	manpath = "/usr/share/man:/usr/X11R6/man:/usr/X11R7/man";
+	manpath = "/usr/share/man:/usr/X11R6/man:/usr/X11R7/man:/usr/local/man:/usr/pkg/man";
 #endif
     else
 	manpath = temp;
