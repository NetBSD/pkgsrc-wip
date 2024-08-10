$NetBSD$

Use aio using select(2).

--- cmake/OpenBSD.cmake.orig	2024-08-10 01:15:33.961377106 +0000
+++ cmake/OpenBSD.cmake
@@ -26,7 +26,7 @@ set(EXTRACTED_SOURCES
     ${CMAKE_CURRENT_SOURCE_DIR}/extracted/vm/src/common/sqTicker.c
 
 #Platform sources
-    ${CMAKE_CURRENT_SOURCE_DIR}/extracted/vm/src/unix/aio.c
+    ${CMAKE_CURRENT_SOURCE_DIR}/extracted/vm/src/unix/aio_select.c
     ${CMAKE_CURRENT_SOURCE_DIR}/src/debugUnix.c
 
 #Virtual Memory functions
