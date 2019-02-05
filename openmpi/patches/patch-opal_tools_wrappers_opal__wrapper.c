$NetBSD$

# NetBSD uses rpath to prevent leakage

--- opal/tools/wrappers/opal_wrapper.c.orig	2018-11-12 20:20:53.000000000 +0000
+++ opal/tools/wrappers/opal_wrapper.c
@@ -56,6 +56,7 @@
 
 #define OPAL_INCLUDE_FLAG  "-I"
 #define OPAL_LIBDIR_FLAG   "-L"
+#define OPAL_RPATH_FLAG    "-R"
 
 struct options_data_t {
     char **compiler_args;
@@ -333,6 +334,8 @@ data_callback(const char *key, const cha
             char *line;
             asprintf(&line, OPAL_LIBDIR_FLAG"%s",
                      options_data[parse_options_idx].path_libdir);
+            asprintf(&line, OPAL_RPATH_FLAG"%s",
+                     options_data[parse_options_idx].path_libdir);
             opal_argv_append_nosize(&options_data[parse_options_idx].link_flags, line);
             free(line);
         }
