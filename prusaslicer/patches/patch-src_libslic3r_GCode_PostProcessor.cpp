$NetBSD$

--- src/libslic3r/GCode/PostProcessor.cpp.orig	2025-12-31 12:41:53.543628241 +0000
+++ src/libslic3r/GCode/PostProcessor.cpp
@@ -152,7 +152,7 @@ static int run_script(const std::string 
 
 #include <cstdlib>   // getenv()
 #include <sstream>
-#include <boost/process.hpp>
+#include <boost/process/v1.hpp>
 
 namespace process = boost::process;
 
@@ -173,8 +173,8 @@ static int run_script(const std::string 
 
     BOOST_LOG_TRIVIAL(debug) << boost::format("Executing script, shell: %1%, command: %2%") % shell % command;
 
-    process::ipstream istd_err;
-    process::child child(shell, "-c", command, process::std_err > istd_err);
+    process::v1::ipstream istd_err;
+    process::v1::child child(shell, "-c", command, process::v1::std_err > istd_err);
 
     std_err.clear();
     std::string line;
