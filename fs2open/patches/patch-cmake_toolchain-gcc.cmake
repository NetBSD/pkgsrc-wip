$NetBSD$

Keep the linker flags (which include the rpath).

--- cmake/toolchain-gcc.cmake.orig	2019-11-03 18:11:21.000000000 +0000
+++ cmake/toolchain-gcc.cmake
@@ -108,7 +108,7 @@ set(CMAKE_C_FLAGS_RELEASE ${COMPILER_FLA
 set(CMAKE_CXX_FLAGS_DEBUG ${COMPILER_FLAGS_DEBUG})
 set(CMAKE_C_FLAGS_DEBUG ${COMPILER_FLAGS_DEBUG})
 
-set(CMAKE_EXE_LINKER_FLAGS "")
+#set(CMAKE_EXE_LINKER_FLAGS "")
 
 IF (MINGW)
 	SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++ -Wl,--enable-auto-import")
