$NetBSD$

--- tools/minicargo/main.cpp.orig	2021-09-12 00:15:52.000000000 +0000
+++ tools/minicargo/main.cpp
@@ -44,6 +44,9 @@ struct ProgramOptions
     // Library search directories
     ::std::vector<const char*>  lib_search_dirs;
 
+    // Pass "-g" to backend mrustc (for compiling in debugging symbols)
+    bool mrustc_g = false;
+
     // Number of build jobs to run at a time
     unsigned build_jobs = 1;
 
@@ -220,6 +223,7 @@ int main(int argc, const char* argv[])
         build_opts.output_dir = opts.output_directory ? ::helpers::path(opts.output_directory) : ::helpers::path("output");
         build_opts.lib_search_dirs.reserve(opts.lib_search_dirs.size());
         build_opts.emit_mmir = opts.emit_mmir;
+        build_opts.mrustc_g = opts.mrustc_g;
         build_opts.target_name = opts.target;
         for(const auto* d : opts.lib_search_dirs)
             build_opts.lib_search_dirs.push_back( ::helpers::path(d) );
@@ -318,6 +322,9 @@ int ProgramOptions::parse(int argc, cons
                     return 1;
                 }
                 break;
+            case 'g':
+                this->mrustc_g = true;
+                break;
             case 'n':
                 this->build_jobs = 0;
                 break;
@@ -429,6 +436,7 @@ void ProgramOptions::help() const
         << "--vendor-dir <dir>       : Directory containing vendored packages (from `cargo vendor`)\n"
         << "--output-dir,-o <dir>    : Specify the compiler output directory\n"
         << "-L <dir>                 : Search for pre-built crates (e.g. libstd) in the specified directory\n"
+        << "-g                       : Pass -g to invocations of mrustc (for compiling in debugging symbols)\n"
         << "-j <count>               : Run at most <count> build tasks at once (default is to run only one)\n"
         << "-n                       : Don't build any packages, just list the packages that would be built\n"
         ;
