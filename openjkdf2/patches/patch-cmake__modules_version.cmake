$NetBSD$

* Don't use git.

--- cmake_modules/version.cmake.orig	2023-06-16 02:36:07.000000000 +0000
+++ cmake_modules/version.cmake
@@ -1,4 +1,9 @@
 set(OPENJKDF2_PROJECT_VERSION 0.9.0.0)
+set(OPENJKDF2_RELEASE_COMMIT ${OPENJKDF2_PROJECT_VERSION})
+set(OPENJKDF2_RELEASE_COMMIT_SHORT ${OPENJKDF2_PROJECT_VERSION})
+
+if(FALSE)
+
 find_package(Git)
 execute_process(
     COMMAND git log -1 --format=%H
@@ -9,4 +14,6 @@ execute_process(
     COMMAND git rev-parse --short=8 HEAD
     OUTPUT_VARIABLE OPENJKDF2_RELEASE_COMMIT_SHORT
     OUTPUT_STRIP_TRAILING_WHITESPACE
-)
\ No newline at end of file
+)
+
+endif()
