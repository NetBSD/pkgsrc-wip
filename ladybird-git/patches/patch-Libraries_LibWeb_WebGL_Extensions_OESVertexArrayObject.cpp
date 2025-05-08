$NetBSD$

paper over missing symbols for now (this is very wrong)

--- Libraries/LibWeb/WebGL/Extensions/OESVertexArrayObject.cpp.orig	2025-05-08 06:16:12.852463559 +0000
+++ Libraries/LibWeb/WebGL/Extensions/OESVertexArrayObject.cpp
@@ -37,7 +37,6 @@ GC::Ref<WebGLVertexArrayObjectOES> OESVe
     m_context->context().make_current();
 
     GLuint handle = 0;
-    glGenVertexArraysOES(1, &handle);
     return WebGLVertexArrayObjectOES::create(realm(), m_context, handle);
 }
 
@@ -55,7 +54,6 @@ void OESVertexArrayObject::delete_vertex
         vertex_array_handle = handle_or_error.release_value();
     }
 
-    glDeleteVertexArraysOES(1, &vertex_array_handle);
 }
 
 bool OESVertexArrayObject::is_vertex_array_oes(GC::Root<WebGLVertexArrayObjectOES> array_object)
@@ -71,7 +69,7 @@ bool OESVertexArrayObject::is_vertex_arr
         vertex_array_handle = handle_or_error.release_value();
     }
 
-    return glIsVertexArrayOES(vertex_array_handle) == GL_TRUE;
+    return false;
 }
 
 void OESVertexArrayObject::bind_vertex_array_oes(GC::Root<WebGLVertexArrayObjectOES> array_object)
@@ -88,7 +86,6 @@ void OESVertexArrayObject::bind_vertex_a
         vertex_array_handle = handle_or_error.release_value();
     }
 
-    glBindVertexArrayOES(vertex_array_handle);
 }
 
 void OESVertexArrayObject::initialize(JS::Realm& realm)
