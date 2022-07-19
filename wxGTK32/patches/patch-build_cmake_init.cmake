$NetBSD$

Not defined in NetBSD build, don't know what should be added instead.

--- build/cmake/init.cmake.orig	2022-07-06 14:19:50.000000000 +0000
+++ build/cmake/init.cmake
@@ -410,7 +410,6 @@ if(wxUSE_GUI)
         else()
             find_package(OpenGL)
             if(WXGTK3 AND OpenGL_EGL_FOUND AND wxUSE_GLCANVAS_EGL)
-                set(OPENGL_LIBRARIES OpenGL::OpenGL OpenGL::GLU OpenGL::EGL)
                 find_package(WAYLANDEGL)
                 if(WAYLANDEGL_FOUND AND wxHAVE_GDK_WAYLAND)
                     list(APPEND OPENGL_LIBRARIES ${WAYLANDEGL_LIBRARIES})
