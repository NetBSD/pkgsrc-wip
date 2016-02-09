$NetBSD$

--- src/pal/tools/gen-buildsys-clang.sh.orig	2016-02-06 09:37:43.000000000 +0000
+++ src/pal/tools/gen-buildsys-clang.sh
@@ -3,16 +3,17 @@
 # This file invokes cmake and generates the build system for gcc.
 #
 
-if [ $# -lt 4 -o $# -gt 7 ]
+if [ $# -lt 4 -o $# -gt 8 ]
 then
   echo "Usage..."
-  echo "gen-buildsys-clang.sh <path to top level CMakeLists.txt> <ClangMajorVersion> <ClangMinorVersion> <Architecture> [build flavor] [coverage] [ninja]"
+  echo "gen-buildsys-clang.sh <path to top level CMakeLists.txt> <ClangMajorVersion> <ClangMinorVersion> <Architecture> [build flavor] [coverage] [ninja] [cmakeargs]"
   echo "Specify the path to the top level CMake file - <ProjectK>/src/NDP"
   echo "Specify the clang version to use, split into major and minor version"
   echo "Specify the target architecture." 
   echo "Optionally specify the build configuration (flavor.) Defaults to DEBUG." 
   echo "Optionally specify 'coverage' to enable code coverage build."
   echo "Target ninja instead of make. ninja must be on the PATH."
+  echo "Pass additional arguments to CMake call."
   exit 1
 fi
 
@@ -39,6 +40,7 @@ buildtype=DEBUG
 code_coverage=OFF
 build_tests=OFF
 generator="Unix Makefiles"
+__UnprocessedCMakeArgs=""
 
 for i in "${@:5}"; do
     upperI="$(echo $i | awk '{print toupper($0)}')"
@@ -59,7 +61,7 @@ for i in "${@:5}"; do
       generator=Ninja
       ;;
       *)
-      echo "Ignoring unknown arg '$i'"
+      __UnprocessedCMakeArgs="$__UnprocessedCMakeArgs $i"
     esac
 done
 
@@ -144,4 +146,5 @@ cmake \
   "-DCMAKE_ENABLE_CODE_COVERAGE=$code_coverage" \
   "-DCLR_CMAKE_BUILD_TESTS=$build_tests" \
   $cmake_extra_defines \
+  "$__UnprocessedCMakeArgs" \
   "$1"
