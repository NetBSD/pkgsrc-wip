$NetBSD: patch-awesomeConfig.cmake,v 1.2 2012/04/27 00:39:30 blckmaxima Exp $

--- awesomeConfig.cmake.orig	2011-01-17 11:38:13.000000000 +0000
+++ awesomeConfig.cmake
@@ -16,7 +16,7 @@ option(COMPRESS_MANPAGES "compress manpa
 option(GENERATE_LUADOC "generate luadoc" ON)
 
 # {{{ CFLAGS
-add_definitions(-std=gnu99 -ggdb3 -fno-strict-aliasing -Wall -Wextra
+add_definitions(-std=gnu99 -fno-strict-aliasing -Wall -Wextra
     -Wchar-subscripts -Wundef -Wshadow -Wcast-align -Wwrite-strings
     -Wsign-compare -Wunused -Wno-unused-parameter -Wuninitialized -Winit-self
     -Wpointer-arith -Wredundant-decls -Wformat-nonliteral
@@ -155,7 +155,7 @@ if(NOT AWESOME_REQUIRED_FOUND OR NOT AWE
 endif()
 
 macro(a_find_library variable library)
-    find_library(${variable} ${library})
+    find_library(${variable} ${library} PKGPREFIX/lib/ev)
     if(NOT ${variable})
         message(FATAL_ERROR ${library} " library not found.")
     endif()
