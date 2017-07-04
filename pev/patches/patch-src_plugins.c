$NetBSD$

Also use ".so" on most BSD systems.

--- src/plugins.c.orig	2017-07-04 17:13:23.000000000 +0000
+++ src/plugins.c
@@ -167,7 +167,7 @@ int plugins_load_all_from_directory(cons
 				const char *filename = dir_entry->d_name;
 
 				// TODO(jweyrich): Use macro conditions for each system: .so, .dylib, .dll
-#if defined(__linux__)
+#if defined(__FreeBSD__) || defined(__linux__) || defined(__NetBSD__) || defined(__OpenBSD__)
 				const bool possible_plugin = utils_str_ends_with(filename, ".so") != 0;
 #elif defined(__APPLE__)
 				const bool possible_plugin = utils_str_ends_with(filename, ".dylib") != 0;
