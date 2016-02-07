$NetBSD$

--- src/pal/tools/gen-buildsys-clang.sh.orig	2016-01-18 21:51:39.000000000 +0000
+++ src/pal/tools/gen-buildsys-clang.sh
@@ -3,6 +3,8 @@
 # This file invokes cmake and generates the build system for gcc.
 #
 
+set -x
+
 if [ $# -lt 4 -o $# -gt 7 ]
 then
   echo "Usage..."
@@ -133,7 +135,10 @@ if [[ -n "$CROSSCOMPILE" ]]; then
     cmake_extra_defines="$cmake_extra_defines -DCMAKE_TOOLCHAIN_FILE=$1/cross/$build_arch/toolchain.cmake"
 fi
 
-cmake \
+cmake_extra_env="$cmake_extra_env $CMAKE_ENV_EXTRA"
+cmake_extra_defines="$cmake_extra_defined $CMAKE_ARGS_EXTRA"
+
+$cmake_extra_env cmake \
   -G "$generator" \
   "-DCMAKE_USER_MAKE_RULES_OVERRIDE=$1/src/pal/tools/clang-compiler-override.txt" \
   "-DCMAKE_AR=$llvm_ar" \
