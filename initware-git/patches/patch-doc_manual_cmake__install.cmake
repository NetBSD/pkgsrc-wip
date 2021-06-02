$NetBSD$

Man file doesn't exist, don't install

--- doc/manual/cmake_install.cmake.orig	2021-06-02 10:14:16.943802945 +0000
+++ doc/manual/cmake_install.cmake
@@ -38,6 +38,6 @@ if(NOT DEFINED CMAKE_OBJDUMP)
 endif()
 
 if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
-  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/man/man7" TYPE FILE FILES "/opt/pkg/src/wip/initware-git/work/initware/doc/manual/iw_rcng.7")
+	#  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/man/man7" TYPE FILE FILES "/opt/pkg/src/wip/initware-git/work/initware/doc/manual/iw_rcng.7")
 endif()
 
