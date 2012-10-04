$NetBSD: patch-programs_dtsearchpath_libCliSrv_UnixEnv.C,v 1.1 2012/10/04 04:57:03 jellehermsen Exp $

--- programs/dtsearchpath/libCliSrv/UnixEnv.C.orig	2012-09-29 12:11:00.000000000 +0000
+++ programs/dtsearchpath/libCliSrv/UnixEnv.C
@@ -84,6 +84,8 @@ UnixEnvironment::UnixEnvironment()
 	manpath = "/usr/share/man:/usr/X11R6/man:/usr/local/man:/usr/ports/infrastructure/man";
 #elif defined(__FreeBSD__)
 	manpath = "/usr/share/man:/usr/local/man";
+#elif defined(__NetBSD__)
+    manpath = "/usr/share/man:/usr/X11R6/man:/usr/X11R7/man:/usr/local/man:/usr/pkg/man";
 #endif
     else
 	manpath = temp;
