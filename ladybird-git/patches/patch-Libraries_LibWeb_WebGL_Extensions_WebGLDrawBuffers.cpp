$NetBSD$

paper over missing symbols for now (this is very wrong)

--- Libraries/LibWeb/WebGL/Extensions/WebGLDrawBuffers.cpp.orig	2025-05-08 06:17:08.146402975 +0000
+++ Libraries/LibWeb/WebGL/Extensions/WebGLDrawBuffers.cpp
@@ -34,7 +34,6 @@ WebGLDrawBuffers::WebGLDrawBuffers(JS::R
 void WebGLDrawBuffers::draw_buffers_webgl(Vector<GLenum> buffers)
 {
     m_context->context().make_current();
-    glDrawBuffersEXT(buffers.size(), buffers.data());
 }
 
 void WebGLDrawBuffers::initialize(JS::Realm& realm)
