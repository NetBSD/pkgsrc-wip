$NetBSD$

Don't pick up Doxygen or Java just because they're there.

--- cmake/Tools.cmake.orig	2021-03-31 09:24:50.000000000 +0000
+++ cmake/Tools.cmake
@@ -58,7 +58,7 @@ endif()
 # Doxygen (http://www.doxygen.org)
 # http://www.stack.nl/~dimitri/doxygen/manual/config.html
 find_package(Doxygen)
-if(DOXYGEN_FOUND)
+if(FALSE AND DOXYGEN_FOUND)
 	set(DOXYGEN_BIN_DIR "${PROJECT_BINARY_DIR}/doxygen")
 	set(DOXYGEN_CMD ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile)
 	set(DOXYGEN_CFG ${PROJECT_SOURCE_DIR}/Doxyfile.in)
@@ -512,13 +512,13 @@ if(INKSCAPE AND APPLE AND NOT IOS)
 	endif()
 endif()
 
-if(NOT JAVA_EXECUTABLE)
+if(FALSE AND NOT JAVA_EXECUTABLE)
 	find_package(Java COMPONENTS Runtime)
 	if(Java_JAVA_EXECUTABLE)
 		set(JAVA_EXECUTABLE "${Java_JAVA_EXECUTABLE}")
 	endif()
 endif()
-if(JAVA_EXECUTABLE)
+if(FALSE AND JAVA_EXECUTABLE)
 	find_file(PLANTUML plantuml.jar PATHS ENV HOME NO_DEFAULT_PATH)
 	if(PLANTUML)
 		message(STATUS "Target uml.statemachines is available using: ${PLANTUML}")
