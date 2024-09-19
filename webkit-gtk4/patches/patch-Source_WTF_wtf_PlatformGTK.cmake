$NetBSD$

--- Source/WTF/wtf/PlatformGTK.cmake.orig	2020-08-12 09:17:54.000000000 +0000
+++ Source/WTF/wtf/PlatformGTK.cmake
@@ -18,6 +18,10 @@ if (CMAKE_SYSTEM_NAME MATCHES "Linux")
         linux/ProcessMemoryFootprint.h
         linux/CurrentProcessMemoryStatus.h
     )
+elseif (APPLE)
+    list(APPEND WTF_PUBLIC_HEADERS
+        spi/darwin/ProcessMemoryFootprint.h
+    )
 endif ()
 
 list(APPEND WTF_SOURCES
