$NetBSD: patch-src_mesa_main_extensions.c,v 1.1 2016/01/27 07:39:54 wiz Exp $

atexit() is not a good idea in shared libraries.

--- src/mesa/main/extensions.c.orig	2017-02-13 11:55:49.000000000 +0000
+++ src/mesa/main/extensions.c
@@ -237,7 +237,7 @@ get_extension_override( struct gl_contex
  * These strings are allocated early during the first context creation by
  * _mesa_one_time_init_extension_overrides.
  */
-static void
+static void __attribute__((__destructor__))
 free_unknown_extensions_strings(void)
 {
    free(extra_extensions);
@@ -258,7 +258,7 @@ _mesa_one_time_init_extension_overrides(
    int len;
    size_t offset;
 
-   atexit(free_unknown_extensions_strings);
+   /* atexit(free_unknown_extensions_strings); */
 
    memset(&_mesa_extension_override_enables, 0, sizeof(struct gl_extensions));
    memset(&_mesa_extension_override_disables, 0, sizeof(struct gl_extensions));
