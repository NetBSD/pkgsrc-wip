$NetBSD$

Workaround EGL initialisation failure.
See discussions at, eg:
https://github.com/nigels-com/glew/issues/273

Allow running on machines with OpenGL 3.0 & 3.1.
Discussion in:
https://github.com/prusa3d/PrusaSlicer/issues/12334

--- src/slic3r/GUI/OpenGLManager.cpp.orig	2024-06-14 21:54:48.000000000 +0000
+++ src/slic3r/GUI/OpenGLManager.cpp
@@ -346,7 +346,7 @@ bool OpenGLManager::init_gl()
     if (!m_gl_initialized) {
       glewExperimental = true;
       GLenum err = glewInit();
-        if (err != GLEW_OK) {
+        if (err != GLEW_OK && err != GLEW_ERROR_NO_GLX_DISPLAY) {
             BOOST_LOG_TRIVIAL(error) << "Unable to init glew library: " << glewGetErrorString(err);
             return false;
         }
@@ -373,7 +373,7 @@ bool OpenGLManager::init_gl()
 #if SLIC3R_OPENGL_ES
         bool valid_version = s_gl_info.is_version_greater_or_equal_to(3, 0);
 #else
-        const bool valid_version = s_gl_info.is_version_greater_or_equal_to(3, 2);
+        const bool valid_version = s_gl_info.is_version_greater_or_equal_to(3, 0);
 #endif // SLIC3R_OPENGL_ES
 
         if (!valid_version) {
