$NetBSD$

--- src/pal/tools/gen-buildsys-clang.sh.orig	2016-01-18 21:51:39.000000000 +0000
+++ src/pal/tools/gen-buildsys-clang.sh
@@ -144,4 +144,5 @@ cmake \
   "-DCMAKE_ENABLE_CODE_COVERAGE=$code_coverage" \
   "-DCLR_CMAKE_BUILD_TESTS=$build_tests" \
   $cmake_extra_defines \
+  $CMAKE_ARGS_EXTRA \
   "$1"
