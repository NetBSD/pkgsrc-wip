$NetBSD: patch-cmake_modules_WaffleDefineOS.cmake,v 1.1 2015/09/19 14:51:52 tnn2 Exp $

Pretend we're Linux.

--- cmake/Modules/WaffleDefineOS.cmake.orig	2015-08-25 21:05:10.000000000 +0000
+++ cmake/Modules/WaffleDefineOS.cmake
@@ -25,6 +25,8 @@
 
 if("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
     set(waffle_on_linux true)
+elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "NetBSD")
+    set(waffle_on_linux true)
 elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
     set(waffle_on_mac true)
 elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
