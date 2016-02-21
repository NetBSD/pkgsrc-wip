$NetBSD$

--- src/pal/tools/gen-buildsys-clang.sh.orig	2016-02-15 22:52:17.000000000 +0000
+++ src/pal/tools/gen-buildsys-clang.sh
@@ -1,6 +1,6 @@
 #!/usr/bin/env bash
 #
-# This file invokes cmake and generates the build system for gcc.
+# This file invokes cmake and generates the build system for Clang.
 #
 
 if [ $# -lt 4 -o $# -gt 8 ]
@@ -61,7 +61,7 @@ for i in "${@:5}"; do
       generator=Ninja
       ;;
       *)
-      __UnprocessedCMakeArgs="$__UnprocessedCMakeArgs $i"
+      __UnprocessedCMakeArgs="${__UnprocessedCMakeArgs}${__UnprocessedCMakeArgs:+ }$i"
     esac
 done
 
@@ -147,5 +147,5 @@ cmake \
   "-DCMAKE_EXPORT_COMPILE_COMMANDS=1 " \
   "-DCLR_CMAKE_BUILD_TESTS=$build_tests" \
   $cmake_extra_defines \
-  "$__UnprocessedCMakeArgs" \
+  $__UnprocessedCMakeArgs \
   "$1"
