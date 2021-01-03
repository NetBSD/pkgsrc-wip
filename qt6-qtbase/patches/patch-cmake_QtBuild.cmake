$NetBSD$

support more pkgsrc platforms

--- cmake/QtBuild.cmake.orig	2020-12-04 10:14:27.000000000 +0000
+++ cmake/QtBuild.cmake
@@ -303,6 +303,16 @@ elseif(LINUX)
     elseif(ICC)
         set(QT_DEFAULT_MKSPEC linux-icc-64)
     endif()
+elseif(FREEBSD)
+    if(CLANG)
+        set(QT_DEFAULT_MKSPEC freebsd-clang)
+    else()
+        set(QT_DEFAULT_MKSPEC freebsd-g++)
+    endif()
+elseif(NETBSD)
+    set(QT_DEFAULT_MKSPEC netbsd-g++)
+elseif(OPENBSD)
+    set(QT_DEFAULT_MKSPEC openbsd-g++)
 elseif(ANDROID)
     if(GCC)
         set(QT_DEFAULT_MKSPEC android-g++)
