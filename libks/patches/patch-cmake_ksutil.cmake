$NetBSD$

Added options for UNIX (not Mac, Windows or Linux).

--- cmake/ksutil.cmake.orig	2024-07-23 20:48:07.000000000 +0000
+++ cmake/ksutil.cmake
@@ -114,6 +114,25 @@ macro(ksutil_setup_platform)
 		set(CMAKE_POSITION_INDEPENDENT_CODE YES)
 		add_definitions("-DKS_PLAT_MAC=1")
 		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
+	elseif (UNIX)
+		message("Platform is UNIX")
+		set(KS_PLAT_UNIX 1 CACHE INTERNAL "Platform definition" FORCE)
+		add_compile_options("$<$<CONFIG:Release>:-O2>")
+		add_compile_options("$<$<CONFIG:Release>:-g>")
+		add_compile_options("$<$<CONFIG:Release>:-Wno-parentheses>")
+		add_compile_options("$<$<CONFIG:Release>:-Wno-pointer-sign>")
+		add_compile_options("$<$<CONFIG:Release>:-Wno-switch>")
+
+		add_compile_options("$<$<CONFIG:Debug>:-O0>")
+		add_compile_options("$<$<CONFIG:Debug>:-g>")
+		add_compile_options("$<$<CONFIG:Debug>:-DKS_BUILD_DEBUG=1>")
+		add_compile_options("$<$<CONFIG:Debug>:-Wno-parentheses>")
+		add_compile_options("$<$<CONFIG:Debug>:-Wno-pointer-sign>")
+		add_compile_options("$<$<CONFIG:Debug>:-Wno-switch>")
+
+		set(CMAKE_POSITION_INDEPENDENT_CODE YES)
+		add_definitions("-DKS_PLAT_UNIX=1")
+		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
 	elseif (WIN32)
 		message("Platform is windows")
 		set(KS_PLAT_WIN 1 CACHE INTERNAL "Platform definition" FORCE)
