$NetBSD$

--- ui/gl/gl_gl_api_implementation.cc.orig	2016-06-24 01:02:53.000000000 +0000
+++ ui/gl/gl_gl_api_implementation.cc
@@ -555,7 +555,11 @@ bool VirtualGLApi::MakeCurrent(GLContext
     // context loss handling in virtual context mode.
     // There should be no other errors from the previous context leaking into
     // the new context.
+#if defined(OS_NETBSD)
+    DCHECK(error == GL_NO_ERROR) <<
+#else
     DCHECK(error == GL_NO_ERROR || error == GL_CONTEXT_LOST_KHR) <<
+#endif
         "GL error was: " << error;
 #endif
 
