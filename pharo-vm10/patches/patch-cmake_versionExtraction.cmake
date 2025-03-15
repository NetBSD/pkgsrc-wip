$NetBSD$

Hide git

--- cmake/versionExtraction.cmake.orig	2025-03-15 10:40:08.474855086 +0000
+++ cmake/versionExtraction.cmake
@@ -35,7 +35,7 @@
 
 # Check if git is found...
 if (VERSION_UPDATE_FROM_GIT)
-        find_package(Git)
+#        find_package(Git)
 endif()
 
 if (GIT_FOUND AND VERSION_UPDATE_FROM_GIT)
