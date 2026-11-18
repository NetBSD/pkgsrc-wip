$NetBSD$

Keep the linker flags (which include the rpath).

--- cmake/toolchain-clang.cmake.orig	2026-09-15 10:00:09.000000000 +0000
+++ cmake/toolchain-clang.cmake
@@ -148,7 +148,7 @@ set(CMAKE_C_FLAGS_DEBUG ${C_FLAGS_DEBUG})
 set(CMAKE_CXX_FLAGS_DEBUG ${CXX_FLAGS_DEBUG})
 set(CMAKE_C_FLAGS_DEBUG ${C_FLAGS_DEBUG})
 
-set(CMAKE_EXE_LINKER_FLAGS "")
+#set(CMAKE_EXE_LINKER_FLAGS "")
 
 if(DEFINED ENV{LDFLAGS})
     set(CMAKE_EXE_LINKER_FLAGS $ENV{LDFLAGS})
