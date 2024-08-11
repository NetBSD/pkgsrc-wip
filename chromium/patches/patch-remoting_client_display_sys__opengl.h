$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/client/display/sys_opengl.h.orig	2024-07-24 02:44:43.361432800 +0000
+++ remoting/client/display/sys_opengl.h
@@ -9,7 +9,7 @@
 
 #if BUILDFLAG(IS_IOS)
 #include <OpenGLES/ES3/gl.h>
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define GL_GLEXT_PROTOTYPES
 #include <GL/gl.h>
 #include <GL/glext.h>
