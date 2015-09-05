$NetBSD: patch-cmake_FindOgg.cmake,v 1.1 2015/09/05 14:50:45 yhardy Exp $

XXX remove on next release

commit 24c1de92e78f1e608d7311102d5c12af54740f12
Author: cc9cii
Date:   Sat Aug 1 07:08:14 2015 +1000

    BUILD: Add CMake modules for Windows and add MSVC specific settings
    
    Includes fixes after berenm's review comments (see https://github.com/cc9cii/xoreos/commit/4a436114ea6663e86fb57bd3f03bff8c583039b8)

diff --git a/cmake/FindOgg.cmake b/cmake/FindOgg.cmake
new file mode 100644
index 0000000..bd09734
--- /dev/null
+++ cmake/FindOgg.cmake
@@ -0,0 +1,41 @@
+# Try to find Ogg library and include path.
+# Once done this will define
+#
+# OGG_INCLUDE_DIRS - where to find ogg/ogg.h, etc.
+# OGG_LIBRARIES - List of libraries when using libogg.
+# OGG_FOUND - True if libogg found.
+
+if(WIN32)
+  find_path(OGG_INCLUDE_DIR ogg/ogg.h $ENV{PROGRAMFILES}/libogg/include DOC "The directory where ogg/ogg.h resides")
+  find_library(OGG_LIBRARY NAMES libogg PATHS $ENV{PROGRAMFILES}/libogg/lib DOC "The libogg library")
+
+else(WIN32)
+  find_path(OGG_INCLUDE_DIR ogg/ogg.h DOC "The directory where ogg/ogg.h resides")
+  find_library(OGG_LIBRARY NAMES libogg DOC "The libogg library")
+
+endif(WIN32)
+
+if(OGG_INCLUDE_DIR AND OGG_LIBRARY)
+  set(OGG_FOUND 1)
+  set(OGG_LIBRARIES ${OGG_LIBRARY})
+  set(OGG_INCLUDE_DIRS ${OGG_INCLUDE_DIR})
+else(OGG_INCLUDE_DIR AND OGG_LIBRARY)
+  set(OGG_FOUND 0)
+  set(OGG_LIBRARIES)
+  set(OGG_INCLUDE_DIRS)
+endif(OGG_INCLUDE_DIR AND OGG_LIBRARY)
+
+mark_as_advanced(OGG_INCLUDE_DIR)
+mark_as_advanced(OGG_LIBRARY)
+mark_as_advanced(OGG_FOUND)
+
+if(NOT OGG_FOUND)
+  set(OGG_DIR_MESSAGE "libogg was not found. Make sure OGG_LIBRARY and OGG_INCLUDE_DIR are set.")
+  if(NOT OGG_FIND_QUIETLY)
+    message(STATUS "${OGG_DIR_MESSAGE}")
+  else(NOT OGG_FIND_QUIETLY)
+    if(OGG_FIND_REQUIRED)
+      message(FATAL_ERROR "${OGG_DIR_MESSAGE}")
+    endif(OGG_FIND_REQUIRED)
+  endif(NOT OGG_FIND_QUIETLY)
+endif(NOT OGG_FOUND)
