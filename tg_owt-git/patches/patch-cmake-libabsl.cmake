$NetBSD$

--- cmake/libabsl.cmake.orig	2021-02-03 11:42:41.000000000 +0000
+++ cmake/libabsl.cmake
@@ -1,5 +1,6 @@
 add_library(libabsl OBJECT)
 init_target(libabsl)
+set_property(TARGET libabsl PROPERTY POSITION_INDEPENDENT_CODE ON)
 add_library(tg_owt::libabsl ALIAS libabsl)
 
 set(libabsl_loc ${third_party_loc}/abseil-cpp)
