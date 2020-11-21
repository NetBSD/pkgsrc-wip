$NetBSD$

--- Source/cmake/FindGTK.cmake.orig	2020-08-12 09:17:57.000000000 +0000
+++ Source/cmake/FindGTK.cmake
@@ -85,7 +85,11 @@ if (GTK_FIND_VERSION VERSION_LESS 3.90)
     set(GTK_4 FALSE)
     set(GTK_3 TRUE)
 else ()
-    set(GTK_PC_MODULE "gtk4")
+    if (ENABLE_QUARTZ_TARGET)
+        set(GTK_PC_MODULE "gtk4-macos")
+    else ()
+        set(GTK_PC_MODULE "gtk4")
+    endif ()
     set(GTK_PC_UNIX_PRINT_MODULE "gtk4-unix-print")
     set(GTK_4 TRUE)
     set(GTK_3 FALSE)
@@ -123,6 +127,10 @@ if (GTK_VERSION AND GTK_VERSION_OK)
     endforeach ()
 endif ()
 
+if (DEFINED GTK_SUPPORTS_MACOS)
+    set(GTK_SUPPORTS_QUARTZ ${GTK_SUPPORTS_MACOS})
+endif ()
+
 if (TARGET PkgConfig::GTK AND NOT TARGET GTK::GTK)
     add_library(GTK::GTK INTERFACE IMPORTED GLOBAL)
     set_property(TARGET GTK::GTK PROPERTY
