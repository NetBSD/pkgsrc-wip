$NetBSD: patch-app_gfx_gl_gl__implementation__linux.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- app/gfx/gl/gl_implementation_linux.cc.orig	2011-04-13 08:01:07.000000000 +0000
+++ app/gfx/gl/gl_implementation_linux.cc
@@ -71,7 +71,7 @@ bool InitializeGLBindings(GLImplementati
     }
     case kGLImplementationDesktopGL: {
       base::NativeLibrary library = base::LoadNativeLibrary(
-          FilePath("libGL.so.1"));
+          FilePath("libGL.so"));
       if (!library) {
         VLOG(1) << "libGL.so.1 not found.";
         return false;
