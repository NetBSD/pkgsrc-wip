$NetBSD$

--- cmake/libyuv.cmake.orig	2021-02-27 15:11:29.753790023 +0000
+++ cmake/libyuv.cmake
@@ -1,5 +1,6 @@
 add_library(libyuv OBJECT)
 init_target(libyuv)
+set_property(TARGET libyuv PROPERTY POSITION_INDEPENDENT_CODE ON)
 add_library(tg_owt::libyuv ALIAS libyuv)
 
 link_libjpeg(libyuv)
