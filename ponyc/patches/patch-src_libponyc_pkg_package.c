$NetBSD$

Look for packages where they end up being installed.
Look for pony libraries in PREFIX/lib

--- src/libponyc/pkg/package.c.orig	2019-07-27 10:37:45.000000000 +0000
+++ src/libponyc/pkg/package.c
@@ -698,6 +698,10 @@ static bool add_exec_dir(pass_opt_t* opt
   snprintf(lib_path, lib_len, "../lib/%s", link_arch);
 
   success = add_relative_path(path, lib_path, opt);
+  if(!success)
+    return false;
+
+  success = add_relative_path(path, "../lib", opt);
 
   ponyint_pool_free_size(lib_len, lib_path);
 
@@ -721,7 +725,7 @@ static bool add_exec_dir(pass_opt_t* opt
 #ifdef PLATFORM_IS_WINDOWS
   success = add_relative_path(path, "..\\packages", opt);
 #else
-  success = add_relative_path(path, "../packages", opt);
+  success = add_relative_path(path, "../lib/pony/" PONY_VERSION "/packages", opt);
 #endif
 
   if(!success)
@@ -756,8 +760,7 @@ bool package_init(pass_opt_t* opt)
 
   // Finally we add OS specific paths.
 #ifdef PLATFORM_IS_POSIX_BASED
-  add_path("/usr/local/lib", opt);
-  add_path("/opt/local/lib", opt);
+  add_path(PREFIX "lib", opt);
 #endif
 
   // Convert all the safe packages to their full paths.
