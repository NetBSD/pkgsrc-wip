$NetBSD: patch-src_compiler_glsl_glsl__parser__extras.cpp,v 1.1 2016/04/17 00:03:00 wiz Exp $

atexit() is not a good idea in a library; use destructor attribute.

--- src/compiler/glsl/glsl_parser_extras.cpp.orig	2017-02-13 11:55:49.000000000 +0000
+++ src/compiler/glsl/glsl_parser_extras.cpp
@@ -2147,7 +2147,7 @@ extern "C" {
  * programs would be invalid.  So this should happen at approximately
  * program exit.
  */
-void
+void __attribute__((__destructor__))
 _mesa_destroy_shader_compiler(void)
 {
    _mesa_destroy_shader_compiler_caches();
