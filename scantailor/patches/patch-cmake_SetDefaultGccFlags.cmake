$NetBSD: patch-cmake_SetDefaultGccFlags.cmake,v 1.1.1.1 2011/02/28 18:32:39 thomasklausner Exp $

--- cmake/SetDefaultGccFlags.cmake.orig	2010-10-24 22:15:40.000000000 +0000
+++ cmake/SetDefaultGccFlags.cmake
@@ -34,10 +34,6 @@ MACRO(ST_SET_DEFAULT_GCC_FLAGS)
 				CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}"
 				CACHE STRING "Common C++ flags for all build configurations." FORCE
 			)
-			SET(
-				CMAKE_EXE_LINKER_FLAGS "" CACHE STRING
-				"Common link flags for all build configurations." FORCE
-			)
 		
 			# Release
 			SET(
@@ -50,11 +46,6 @@ MACRO(ST_SET_DEFAULT_GCC_FLAGS)
 				"-DNDEBUG -O2 ${visibility_cflags_} ${gc_sections_cflags_}"
 				CACHE STRING "C++ flags for Release builds." FORCE
 			)
-			SET(
-				CMAKE_EXE_LINKER_FLAGS_RELEASE
-				"${gc_sections_ldflags_} ${dead_strip_ldflags_}"
-				CACHE STRING "Link flags for Release builds." FORCE
-			)
 			
 			# MinSizeRel
 			SET(
@@ -67,11 +58,6 @@ MACRO(ST_SET_DEFAULT_GCC_FLAGS)
 				"-DNDEBUG -Os ${visibility_cflags_} ${gc_sections_cflags_}"
 				CACHE STRING "C++ flags for MinSizeRel builds." FORCE
 			)
-			SET(
-				CMAKE_EXE_LINKER_FLAGS_MINSIZEREL
-				"${gc_sections_ldflags_} ${dead_strip_ldflags_}"
-				CACHE STRING "Link flags for MinSizeRel builds." FORCE
-			)
 			
 			# RelWithDebInfo
 			SET(
@@ -84,10 +70,6 @@ MACRO(ST_SET_DEFAULT_GCC_FLAGS)
 				"-DNDEBUG -g -O2 ${visibility_cflags_}"
 				CACHE STRING "C++ flags for RelWithDebInfo builds." FORCE
 			)
-			SET(
-				CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO ""
-				CACHE STRING "Link flags for RelWithDebInfo builds." FORCE
-			)
 			
 			# Debug
 			SET(
@@ -98,10 +80,6 @@ MACRO(ST_SET_DEFAULT_GCC_FLAGS)
 				CMAKE_CXX_FLAGS_DEBUG "-DDEBUG -g" CACHE STRING
 				"C++ flags for Debug builds." FORCE
 			)
-			SET(
-				CMAKE_EXE_LINKER_FLAGS_DEBUG ""
-				CACHE STRING "Link flags for Debug builds." FORCE
-			)
 			
 			SET(COMPILER_FLAGS_OVERRIDDEN YES CACHE INTERNAL "" FORCE)
 		
