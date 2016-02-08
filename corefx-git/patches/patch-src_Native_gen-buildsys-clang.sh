$NetBSD$

--- src/Native/gen-buildsys-clang.sh.orig	2016-01-30 00:20:59.000000000 +0000
+++ src/Native/gen-buildsys-clang.sh
@@ -50,4 +50,4 @@ if [[ -n "$LLDB_INCLUDE_DIR" ]]; then
     cmake_extra_defines="$cmake_extra_defines -DWITH_LLDB_INCLUDES=$LLDB_INCLUDE_DIR"
 fi
 
-cmake $cmake_extra_defines $1
+cmake $cmake_extra_defines $CMAKE_ARGS_EXTRA $1
