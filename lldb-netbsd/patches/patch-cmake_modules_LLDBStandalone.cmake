$NetBSD$

--- cmake/modules/LLDBStandalone.cmake.orig	2017-04-19 04:06:59.854088855 +0000
+++ cmake/modules/LLDBStandalone.cmake
@@ -4,6 +4,8 @@ if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURR
   project(lldb)
   cmake_minimum_required(VERSION 2.8.12.2)
 
+  include(CheckIncludeFile)
+
   if (POLICY CMP0022)
     cmake_policy(SET CMP0022 NEW) # automatic when 2.8.12 is required
   endif()
