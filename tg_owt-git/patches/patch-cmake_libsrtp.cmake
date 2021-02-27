$NetBSD$

--- cmake/libsrtp.cmake.orig	2020-11-13 06:17:31.000000000 +0000
+++ cmake/libsrtp.cmake
@@ -1,4 +1,5 @@
 add_library(libsrtp OBJECT)
+set_property(TARGET libsrtp PROPERTY POSITION_INDEPENDENT_CODE ON)
 init_target(libsrtp)
 add_library(tg_owt::libsrtp ALIAS libsrtp)
 
