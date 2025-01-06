$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- remoting/client/display/sys_opengl.h.orig	2024-10-18 12:34:31.753878800 +0000
+++ remoting/client/display/sys_opengl.h
@@ -9,7 +9,7 @@
 
 #if BUILDFLAG(IS_IOS)
 #include <OpenGLES/ES3/gl.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define GL_GLEXT_PROTOTYPES
 #include <GL/gl.h>
 #include <GL/glext.h>
