$NetBSD$

--- src/Native/configure.cmake.orig	2016-02-07 13:49:29.000000000 +0000
+++ src/Native/configure.cmake
@@ -10,6 +10,7 @@ include(CheckTypeSize)
 #CMake does not include /usr/local/include into the include search path
 #thus add it manually. This is required on FreeBSD.
 include_directories(SYSTEM /usr/local/include)
+include_directories(SYSTEM /usr/pkg/include)
 
 # in_pktinfo: Find whether this struct exists
 check_include_files(
@@ -75,6 +76,16 @@ check_symbol_exists(
     "sys/ioctl.h"
     HAVE_TIOCGWINSZ)
 
+check_symbol_exists(
+    ENOTRECOVERABLE
+    "sys/errno.h"
+    HAVE_ENOTRECOVERABLE)
+
+check_symbol_exists(
+    EOWNERDEAD
+    "sys/errno.h"
+    HAVE_EOWNERDEAD)
+
 check_function_exists(
     tcgetattr
     HAVE_TCGETATTR)
