$NetBSD$

Add statvfs() checks.
https://github.com/wxWidgets/wxWidgets/pull/22643

Use proper variable for dlopen() library.
https://github.com/wxWidgets/wxWidgets/pull/22644

--- build/cmake/setup.cmake.orig	2022-07-06 14:19:50.000000000 +0000
+++ build/cmake/setup.cmake
@@ -290,7 +290,7 @@ if(UNIX)
     wx_check_funcs(mkstemp mktemp)
 
     # get the library function to use for wxGetDiskSpace(): it is statfs() under
-    # Linux and *BSD and statvfs() under Solaris
+    # Linux and *BSD and statvfs() under Solaris and NetBSD
     wx_check_c_source_compiles("
         return 0; }
         #if defined(__BSD__)
@@ -308,6 +308,18 @@ if(UNIX)
         l += fs.f_blocks;
         l += fs.f_bavail;"
         HAVE_STATFS)
+    wx_check_c_source_compiles("
+        return 0; }
+        #include <sys/statvfs.h>
+
+        int foo() {
+        long l;
+        struct statvfs fs;
+        statvfs(\"/\", &fs);
+        l = fs.f_bsize;
+        l += fs.f_blocks;
+        l += fs.f_bavail;"
+        HAVE_STATVFS)
     if(HAVE_STATFS)
         set(WX_STATFS_T "struct statfs")
         wx_check_cxx_source_compiles("
@@ -324,9 +336,8 @@ if(UNIX)
             statfs(\"/\", &fs);"
             HAVE_STATFS_DECL)
     else()
-        # TODO: implement statvfs checks
         if(HAVE_STATVFS)
-            set(WX_STATFS_T statvfs_t)
+            set(WX_STATFS_T "struct statvfs")
         endif()
     endif()
 
@@ -611,7 +622,7 @@ if(wxUSE_DATETIME)
 endif()
 
 cmake_push_check_state(RESET)
-set(CMAKE_REQUIRED_LIBRARIES dl)
+set(CMAKE_REQUIRED_LIBRARIES ${CMAKE_DL_LIBS})
 check_symbol_exists(dlopen dlfcn.h HAVE_DLOPEN)
 cmake_pop_check_state()
 if(HAVE_DLOPEN)
