$NetBSD: patch-xbmc_system__gl.h,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

NetBSD needs GL includes, too.

--- xbmc/system_gl.h.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/system_gl.h
@@ -30,7 +30,7 @@
   #if defined(TARGET_WINDOWS)
     #include <GL/gl.h>
     #include <GL/glu.h>
-  #elif defined(TARGET_LINUX)
+  #elif defined(TARGET_LINUX) || defined(TARGET_NETBSD)
     #include <GL/gl.h>
     #include <GL/glu.h>
     #include <GL/glext.h>
