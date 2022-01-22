$NetBSD$

--- tools/minicargo/build.h.orig	2021-09-12 00:15:52.000000000 +0000
+++ tools/minicargo/build.h
@@ -20,6 +20,7 @@ struct BuildOptions
     ::helpers::path build_script_overrides;
     ::std::vector<::helpers::path>  lib_search_dirs;
     bool emit_mmir = false;
+    bool mrustc_g  = false;
     const char* target_name = nullptr;  // if null, host is used
     enum class Mode {
         /// Build the binary/library
