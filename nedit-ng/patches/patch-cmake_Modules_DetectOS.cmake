$NetBSD$

* make compilation run on all pkgsrc platforms

--- cmake/Modules/DetectOS.cmake.orig	2020-02-05 05:36:17.000000000 +0000
+++ cmake/Modules/DetectOS.cmake
@@ -8,5 +8,5 @@ elseif (CMAKE_SYSTEM_NAME MATCHES "FreeB
 elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
 	set(TARGET_PLATFORM_MACOS 1)
 else()
-	message(FATAL_ERROR "Unsupported OS: ${CMAKE_SYSTEM_NAME}")
+	set(TARGET_PLATFORM_PKGSRC 1)
 endif ()
