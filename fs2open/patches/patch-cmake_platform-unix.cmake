$NetBSD$

Use the pkgsrcs settings for rpath, and set the binary
and library destinations for pkgsrc.

--- cmake/platform-unix.cmake.orig	2019-12-15 06:53:29.388252150 +0000
+++ cmake/platform-unix.cmake
@@ -6,8 +6,11 @@ MESSAGE(STATUS "Configuring UNIX specifi
 target_compile_definitions(platform INTERFACE SCP_UNIX USE_OPENAL _REENTRANT)
 
 # Set RPATH
-set(CMAKE_SKIP_BUILD_RPATH TRUE)
-set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
-set(CMAKE_INSTALL_RPATH "\$ORIGIN")
+#set(CMAKE_SKIP_BUILD_RPATH TRUE)
+#set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
+#set(CMAKE_INSTALL_RPATH "\$ORIGIN")
 
 set(PLATFORM_UNIX TRUE CACHE INTERNAL "" FORCE)
+
+SET(BINARY_DESTINATION "bin")
+SET(LIBRAY_DESTINATION "lib")
