$NetBSD$

Fix escaping so substitutions occur in the right pass, and we don't try to
modify files in the final installation directory.

--- adm/cmake/occt_macros.cmake.orig	2022-11-11 22:19:44.000000000 +0000
+++ adm/cmake/occt_macros.cmake
@@ -592,7 +592,7 @@ macro (OCCT_UPDATE_TARGET_FILE)
 
   install (CODE
   "string (TOLOWER \"\${CMAKE_INSTALL_CONFIG_NAME}\" CMAKE_INSTALL_CONFIG_NAME_LOWERCASE)
-  file (GLOB ALL_OCCT_TARGET_FILES \"${INSTALL_DIR}/${INSTALL_DIR_CMAKE}/OpenCASCADE*Targets-\${CMAKE_INSTALL_CONFIG_NAME_LOWERCASE}.cmake\")
+  file (GLOB ALL_OCCT_TARGET_FILES \"\${INSTALL_DIR}/${INSTALL_DIR_CMAKE}/OpenCASCADE*Targets-\${CMAKE_INSTALL_CONFIG_NAME_LOWERCASE}.cmake\")
   foreach(TARGET_FILENAME \${ALL_OCCT_TARGET_FILES})
     file (STRINGS \"\${TARGET_FILENAME}\" TARGET_FILE_CONTENT)
     file (REMOVE \"\${TARGET_FILENAME}\")
