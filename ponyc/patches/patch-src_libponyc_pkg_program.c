$NetBSD$

--- src/libponyc/pkg/program.c.orig	2019-07-27 10:37:45.000000000 +0000
+++ src/libponyc/pkg/program.c
@@ -202,13 +202,13 @@ void program_lib_build_args(ast_t* progr
     const char* libpath = strlist_data(p);
     append_to_args(data, path_preamble);
     append_to_args(data, libpath);
-    append_to_args(data, " ");
+    append_to_args(data, "../ ");
 
     if(rpath_preamble != NULL)
     {
       append_to_args(data, rpath_preamble);
       append_to_args(data, libpath);
-      append_to_args(data, " ");
+      append_to_args(data, "../lib ");
     }
   }
 
