$NetBSD: patch-cmake_VersionString.cmake,v 1.1 2015/08/18 20:14:58 yhardy Exp $

Fix use of CMAKE_MODULE_PATH (see also patch-CMakeLists.txt)

--- cmake/VersionString.cmake.orig	2013-07-15 19:54:22.000000000 +0200
+++ cmake/VersionString.cmake	2013-07-15 19:54:52.000000000 +0200
@@ -29,7 +29,7 @@
 	set(mode "variable")
 	
 	set(args)
-	set(dependencies "${CMAKE_MODULE_PATH}/VersionScript.cmake")
+	set(dependencies "${CMAKE_CUSTOM_MODULE_PATH}/VersionScript.cmake")
 	
 	foreach(arg IN LISTS VERSION_SOURCES)
 		
@@ -72,7 +72,7 @@
 			"-DVERSION_SOURCES=${args}"
 			"-DGIT_DIR=${abs_git_dir}"
 			${defines}
-			-P "${CMAKE_MODULE_PATH}/VersionScript.cmake"
+			-P "${CMAKE_CUSTOM_MODULE_PATH}/VersionScript.cmake"
 		MAIN_DEPENDENCY
 			"${abs_src}"
 		DEPENDS
