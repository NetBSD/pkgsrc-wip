$NetBSD$

Don't link against libdl on NetBSD.
--- cmake/compilers/GNU.cmake.orig	2022-08-10 20:30:17.538194226 -0700
+++ cmake/compilers/GNU.cmake	2022-08-10 20:31:26.829818970 -0700
@@ -40,7 +40,7 @@
     set(TBB_COMMON_COMPILE_FLAGS ${TBB_COMMON_COMPILE_FLAGS} -mrtm $<$<AND:$<NOT:$<CXX_COMPILER_ID:Intel>>,$<NOT:$<VERSION_LESS:${CMAKE_CXX_COMPILER_VERSION},11.0>>>:-mwaitpkg>)
 endif()
 
-if (NOT MINGW)
+if (NOT MINGW AND NOT ${CMAKE_SYSTEM_NAME} STREQUAL "NetBSD")
     set(TBB_COMMON_LINK_LIBS dl)
 endif()
 
