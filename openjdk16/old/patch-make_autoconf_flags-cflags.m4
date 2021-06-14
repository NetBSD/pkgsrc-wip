$NetBSD: patch-make_autoconf_flags-cflags.m4,v 1.1 2019/10/01 12:36:34 tnn Exp $

We prefer to use explicit run paths.

--- make/autoconf/flags-cflags.m4.orig	2021-06-10 07:19:56.609007352 -0400
+++ make/autoconf/flags-cflags.m4	2021-06-10 07:27:30.570412512 -0400
@@ -38,7 +38,8 @@
     # Default works for linux, might work on other platforms as well.
     SHARED_LIBRARY_FLAGS='-shared'
     SET_EXECUTABLE_ORIGIN='-Wl,-rpath,\$$ORIGIN[$]1'
-    SET_SHARED_LIBRARY_ORIGIN="-Wl,-z,origin $SET_EXECUTABLE_ORIGIN"
+    SET_EXECUTABLE_ORIGIN='@COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib @COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib/server'
+    SET_SHARED_LIBRARY_ORIGIN="$SET_EXECUTABLE_ORIGIN"
     SET_SHARED_LIBRARY_NAME='-Wl,-soname=[$]1'
     SET_SHARED_LIBRARY_MAPFILE='-Wl,-version-script=[$]1'
 
@@ -46,7 +47,7 @@
     if test "x$OPENJDK_TARGET_OS" = xmacosx; then
       # Linking is different on MacOSX
       SHARED_LIBRARY_FLAGS="-dynamiclib -compatibility_version 1.0.0 -current_version 1.0.0"
-      SET_EXECUTABLE_ORIGIN='-Wl,-rpath,@loader_path$(or [$]1,/.)'
+      SET_EXECUTABLE_ORIGIN='@COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib @COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib/server'
       SET_SHARED_LIBRARY_ORIGIN="$SET_EXECUTABLE_ORIGIN"
       SET_SHARED_LIBRARY_NAME='-Wl,-install_name,@rpath/[$]1'
       SET_SHARED_LIBRARY_MAPFILE='-Wl,-exported_symbols_list,[$]1'
@@ -54,17 +55,9 @@
     else
       # Default works for linux, might work on other platforms as well.
       SHARED_LIBRARY_FLAGS='-shared'
-      SET_EXECUTABLE_ORIGIN='-Wl,-rpath,\$$ORIGIN[$]1'
-      SET_SHARED_LIBRARY_NAME='-Wl,-soname=[$]1'
+      SET_EXECUTABLE_ORIGIN='@COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib @COMPILER_RPATH_FLAG@@PREFIX@/java/@JAVA_NAME@/lib/server'
+      SET_SHARED_LIBRARY_ORIGIN="$SET_EXECUTABLE_ORIGIN"
       SET_SHARED_LIBRARY_MAPFILE='-Wl,-version-script=[$]1'
-
-      # arm specific settings
-      if test "x$OPENJDK_TARGET_CPU" = "xarm"; then
-        # '-Wl,-z,origin' isn't used on arm.
-        SET_SHARED_LIBRARY_ORIGIN='-Wl,-rpath,\$$$$ORIGIN[$]1'
-      else
-        SET_SHARED_LIBRARY_ORIGIN="-Wl,-z,origin $SET_EXECUTABLE_ORIGIN"
-      fi
     fi
 
   elif test "x$TOOLCHAIN_TYPE" = xxlc; then
@@ -527,7 +520,7 @@
   # C99 level.
   if test "x$TOOLCHAIN_TYPE" = xgcc || test "x$TOOLCHAIN_TYPE" = xclang || test "x$TOOLCHAIN_TYPE" = xxlc; then
     # Explicitly set C99. clang and xlclang support the same flag.
-    LANGSTD_CFLAGS="-std=c99"
+    LANGSTD_CFLAGS="-std=gnu99"
   elif test "x$TOOLCHAIN_TYPE" = xmicrosoft; then
     # MSVC doesn't support C99/C11 explicitly, unless you compile as C++:
     # LANGSTD_CFLAGS="-TP"
@@ -540,7 +533,7 @@
 
   # CXXFLAGS C++ language level for all of JDK, including Hotspot.
   if test "x$TOOLCHAIN_TYPE" = xgcc || test "x$TOOLCHAIN_TYPE" = xclang || test "x$TOOLCHAIN_TYPE" = xxlc; then
-    LANGSTD_CXXFLAGS="-std=c++14"
+    LANGSTD_CXXFLAGS="-std=gnu++14"
   elif test "x$TOOLCHAIN_TYPE" = xmicrosoft; then
     LANGSTD_CXXFLAGS="-std:c++14"
   else
