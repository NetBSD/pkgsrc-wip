$NetBSD$

Use more portable boost routine for finding running executable path.

--- src/PrusaSlicer.cpp.orig	2020-03-21 10:55:51.000000000 +0000
+++ src/PrusaSlicer.cpp
@@ -22,6 +22,7 @@
 #include <cstring>
 #include <iostream>
 #include <math.h>
+#include <boost/dll/runtime_symbol_info.hpp>
 #include <boost/filesystem.hpp>
 #include <boost/nowide/args.hpp>
 #include <boost/nowide/cenv.hpp>
@@ -554,7 +555,7 @@ bool CLI::setup(int argc, char **argv)
         }
     }
 
-    boost::filesystem::path path_to_binary = boost::filesystem::system_complete(argv[0]);
+    boost::filesystem::path path_to_binary = boost::dll::program_location();
 
     // Path from the Slic3r binary to its resources.
 #ifdef __APPLE__
