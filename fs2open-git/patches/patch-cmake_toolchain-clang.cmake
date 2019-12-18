$NetBSD$

Keep the linker flags (which include the rpath).

--- cmake/toolchain-clang.cmake.orig	2019-12-15 18:44:11.111523660 +0000
+++ cmake/toolchain-clang.cmake
@@ -97,7 +97,7 @@ set(CMAKE_CXX_FLAGS_DEBUG ${COMPILER_FLA
 set(CMAKE_C_FLAGS_DEBUG ${COMPILER_FLAGS_DEBUG})
 
 
-set(CMAKE_EXE_LINKER_FLAGS "")
+#set(CMAKE_EXE_LINKER_FLAGS "")
 
 if (CLANG_USE_LIBCXX)
 	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++abi")
