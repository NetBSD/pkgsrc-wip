$NetBSD$

--- src/pal/tools/gen-buildsys-clang.sh.orig	2016-01-18 21:51:39.000000000 +0000
+++ src/pal/tools/gen-buildsys-clang.sh
@@ -133,6 +133,9 @@ if [[ -n "$CROSSCOMPILE" ]]; then
     cmake_extra_defines="$cmake_extra_defines -DCMAKE_TOOLCHAIN_FILE=$1/cross/$build_arch/toolchain.cmake"
 fi
 
+# Allow to specify additional parameters via environment variables.
+
+$CMAKE_ENV_EXTRA \
 cmake \
   -G "$generator" \
   "-DCMAKE_USER_MAKE_RULES_OVERRIDE=$1/src/pal/tools/clang-compiler-override.txt" \
@@ -144,4 +147,5 @@ cmake \
   "-DCMAKE_ENABLE_CODE_COVERAGE=$code_coverage" \
   "-DCLR_CMAKE_BUILD_TESTS=$build_tests" \
   $cmake_extra_defines \
+  $CMAKE_ARGS_EXTRA \
   "$1"
