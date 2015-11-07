$NetBSD$

--- cmake/modules/AddSphinxTarget.cmake.orig	2015-11-07 14:20:56.000000000 +0000
+++ cmake/modules/AddSphinxTarget.cmake
@@ -7,6 +7,8 @@
 #
 # This script was copied from the LLVM repository.
 #
+include(GNUInstallDirs)
+
 function (add_sphinx_target builder project)
   set(SPHINX_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/${builder}")
   set(SPHINX_DOC_TREE_DIR "${CMAKE_CURRENT_BINARY_DIR}/_doctrees")
@@ -53,7 +55,7 @@ function (add_sphinx_target builder proj
       if (builder STREQUAL man)
         # FIXME: We might not ship all the tools that these man pages describe
         install(DIRECTORY "${SPHINX_BUILD_DIR}/" # Slash indicates contents of
-                DESTINATION share/man/man1)
+                DESTINATION ${CMAKE_INSTALL_MANDIR}/man1)
 
       elseif (builder STREQUAL html)
         install(DIRECTORY "${SPHINX_BUILD_DIR}"
