$NetBSD$

../src/config.c: In function 'parse_window_shader_prefix_with_cwd':
../src/config.c:625:78: error: parameter name omitted
  625 | void *parse_window_shader_prefix_with_cwd(const char *src, const char **end, void *) {
      |                                                                              ^~~~~~

--- src/config.c.orig	2024-11-13 06:48:38.000000000 +0000
+++ src/config.c
@@ -622,7 +622,7 @@ void *parse_window_shader_prefix(const c
 	*end = endptr + 1;
 	return shader_source;
 }
-void *parse_window_shader_prefix_with_cwd(const char *src, const char **end, void *) {
+void *parse_window_shader_prefix_with_cwd(const char *src, const char **end, void *foo) {
 	scoped_charp cwd = getcwd(NULL, 0);
 	return parse_window_shader_prefix(src, end, cwd);
 }
