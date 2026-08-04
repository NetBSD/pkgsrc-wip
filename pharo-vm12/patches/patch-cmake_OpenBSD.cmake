$NetBSD$

fix include directories

--- cmake/OpenBSD.cmake.orig	2026-08-01 12:59:56.011291716 +0000
+++ cmake/OpenBSD.cmake
@@ -14,8 +14,8 @@ PUBLIC
 function(add_platform_headers)
 target_include_directories(${VM_LIBRARY_NAME}
 PUBLIC
-    ${CMAKE_CURRENT_SOURCE_DIR}/include/unix
-    ${CMAKE_CURRENT_SOURCE_DIR}/include/common
+    ${CMAKE_CURRENT_SOURCE_DIR}/include/pharovm/unix
+    ${CMAKE_CURRENT_SOURCE_DIR}/include/pharovm/common
 )
 endfunction() #add_platform_headers
 
@@ -81,7 +81,7 @@ macro(configure_installables INSTALL_COMPONENT)
 
 
 	install(
-	    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/unix/"
+	    DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/pharovm/unix/"
 	    DESTINATION include/pharovm
 	    COMPONENT include
 	    FILES_MATCHING PATTERN *.h)
