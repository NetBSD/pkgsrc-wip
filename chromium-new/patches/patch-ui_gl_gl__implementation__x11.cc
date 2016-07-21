$NetBSD$

--- ui/gl/gl_implementation_x11.cc.orig	2016-06-24 01:02:53.000000000 +0000
+++ ui/gl/gl_implementation_x11.cc
@@ -33,7 +33,7 @@ void GL_BINDING_CALL MarshalDepthRangeTo
   glDepthRangef(static_cast<GLclampf>(z_near), static_cast<GLclampf>(z_far));
 }
 
-#if defined(OS_OPENBSD)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
 const char kGLLibraryName[] = "libGL.so";
 #else
 const char kGLLibraryName[] = "libGL.so.1";
