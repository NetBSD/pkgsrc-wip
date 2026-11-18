$NetBSD$

Keep the linker flags (which include the rpath).

--- cmake/toolchain-gcc.cmake.orig	2026-09-15 10:00:09.000000000 +0000
+++ cmake/toolchain-gcc.cmake
@@ -190,7 +190,7 @@ set(CMAKE_C_FLAGS_DEBUG ${C_FLAGS_DEBUG})
 set(CMAKE_CXX_FLAGS_DEBUG ${CXX_FLAGS_DEBUG})
 set(CMAKE_C_FLAGS_DEBUG ${C_FLAGS_DEBUG})
 
-set(CMAKE_EXE_LINKER_FLAGS "${LINKER_FLAGS}")
+#set(CMAKE_EXE_LINKER_FLAGS "${LINKER_FLAGS}")
 
 IF (MINGW)
 	SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++ -Wl,--enable-auto-import")
