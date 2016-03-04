$NetBSD$

--- src/Native/gen-buildsys-clang.sh.orig	2016-03-02 23:13:05.000000000 +0000
+++ src/Native/gen-buildsys-clang.sh
@@ -3,14 +3,15 @@
 # This file invokes cmake and generates the build system for Clang.
 #
 
-if [ $# -lt 4 -o $# -gt 5 ]
+if [ $# -lt 4 -o $# -gt 6 ]
 then
   echo "Usage..."
-  echo "gen-buildsys-clang.sh <path to top level CMakeLists.txt> <ClangMajorVersion> <ClangMinorVersion> <Architecture> [build flavor]"
+  echo "gen-buildsys-clang.sh <path to top level CMakeLists.txt> <ClangMajorVersion> <ClangMinorVersion> <Architecture> [build flavor] [cmakeargs]"
   echo "Specify the path to the top level CMake file - <corefx>/src/Native"
   echo "Specify the clang version to use, split into major and minor version"
   echo "Specify the target architecture." 
   echo "Optionally specify the build configuration (flavor.) Defaults to DEBUG." 
+  echo "Optionally pass additional arguments to CMake call." 
   exit 1
 fi
 
@@ -63,4 +64,13 @@ if [[ -n "$CROSSCOMPILE" ]]; then
     cmake_extra_defines="$cmake_extra_defines -DCMAKE_TOOLCHAIN_FILE=$project_root/cross/$build_arch/toolchain.cmake"
 fi
 
-cmake $cmake_extra_defines $1
+__UnprocessedCMakeArgs=""
+if [ -z "$6" ]; then
+    echo "No CMake extra Args specified"
+else
+    __UnprocessedCMakeArgs="$6"
+fi
+
+cmake $cmake_extra_defines \
+    $__UnprocessedCMakeArgs \
+    $1
