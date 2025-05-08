$NetBSD$

paper over missing symbols for now (this is very wrong)

--- Libraries/LibWeb/WebGL/Extensions/ANGLEInstancedArrays.cpp.orig	2025-05-08 06:15:12.540696243 +0000
+++ Libraries/LibWeb/WebGL/Extensions/ANGLEInstancedArrays.cpp
@@ -34,19 +34,16 @@ ANGLEInstancedArrays::ANGLEInstancedArra
 void ANGLEInstancedArrays::vertex_attrib_divisor_angle(GLuint index, GLuint divisor)
 {
     m_context->context().make_current();
-    glVertexAttribDivisorANGLE(index, divisor);
 }
 
 void ANGLEInstancedArrays::draw_arrays_instanced_angle(GLenum mode, GLint first, GLsizei count, GLsizei primcount)
 {
     m_context->context().make_current();
-    glDrawArraysInstancedANGLE(mode, first, count, primcount);
 }
 
 void ANGLEInstancedArrays::draw_elements_instanced_angle(GLenum mode, GLsizei count, GLenum type, GLintptr offset, GLsizei primcount)
 {
     m_context->context().make_current();
-    glDrawElementsInstancedANGLE(mode, count, type, reinterpret_cast<void*>(offset), primcount);
 }
 
 void ANGLEInstancedArrays::initialize(JS::Realm& realm)
