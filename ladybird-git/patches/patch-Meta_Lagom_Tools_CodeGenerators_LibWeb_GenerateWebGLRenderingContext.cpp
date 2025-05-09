$NetBSD$

--- Meta/Lagom/Tools/CodeGenerators/LibWeb/GenerateWebGLRenderingContext.cpp.orig	2025-05-09 08:23:04.025562517 +0000
+++ Meta/Lagom/Tools/CodeGenerators/LibWeb/GenerateWebGLRenderingContext.cpp
@@ -352,12 +352,7 @@ static void generate_get_internal_format
     generator.append(R"~~~(
     switch (pname) {
     case GL_SAMPLES: {
-        GLint num_sample_counts { 0 };
-        glGetInternalformativ(target, internalformat, GL_NUM_SAMPLE_COUNTS, 1, &num_sample_counts);
-        auto samples_buffer = MUST(ByteBuffer::create_zeroed(num_sample_counts * sizeof(GLint)));
-        glGetInternalformativ(target, internalformat, GL_SAMPLES, num_sample_counts, reinterpret_cast<GLint*>(samples_buffer.data()));
-        auto array_buffer = JS::ArrayBuffer::create(m_realm, move(samples_buffer));
-        return JS::Int32Array::create(m_realm, num_sample_counts, array_buffer);
+        return JS::js_null();
     }
     default:
         dbgln("Unknown WebGL internal format parameter name: {:x}", pname);
