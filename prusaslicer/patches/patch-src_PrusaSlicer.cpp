$NetBSD$

Use /proc filesystem by default for the path to the running binary.

--- src/PrusaSlicer.cpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/PrusaSlicer.cpp
@@ -612,7 +612,22 @@ bool CLI::setup(int argc, char **argv)
     // Detect the operating system flavor after SLIC3R_LOGLEVEL is set.
     detect_platform();
 
-    boost::filesystem::path path_to_binary = boost::filesystem::system_complete(argv[0]);
+    boost::filesystem::path path_to_binary;
+    boost::system::error_code ec;
+    // Linux
+    path_to_binary = boost::filesystem::canonical("/proc/self/exe", ec);
+    // NetBSD
+    if (path_to_binary.empty()) {
+        path_to_binary = boost::filesystem::canonical("/proc/curproc/exe", ec);
+    }
+    // FreeBSD
+    if (path_to_binary.empty()) {
+        path_to_binary = boost::filesystem::canonical("/proc/curproc/file", ec);
+    }
+    // fallback to old, incorrect method, which just appends the binary to the cwd.
+    if (path_to_binary.empty()) {
+        path_to_binary = boost::filesystem::canonical(boost::filesystem::system_complete(argv[0]));
+    }
 
     // Path from the Slic3r binary to its resources.
 #ifdef __APPLE__
