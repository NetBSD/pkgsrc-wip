$NetBSD: patch-cmake_FindIconv.cmake,v 1.1 2015/09/05 14:50:45 yhardy Exp $

XXX remove on next release

commit ed79efbb53a9da84c7efb471f7679c352191df40
Author: Sven Hesse <drmccoy@drmccoy.de>
Date:   Wed Sep 2 22:51:18 2015 +0200

    BUILD: Fix case of FindIconv CMake file

diff --git a/cmake/FindIconv.cmake b/cmake/FindIconv.cmake
new file mode 100644
index 0000000..95fa59a
--- /dev/null
+++ cmake/FindIconv.cmake
@@ -0,0 +1,60 @@
+# https://github.com/onyx-intl/cmake_modules/blob/master/FindIconv.cmake
+#
+# - Try to find Iconv
+# Once done this will define
+#
+# ICONV_FOUND - system has Iconv
+# ICONV_INCLUDE_DIR - the Iconv include directory
+# ICONV_LIBRARIES - Link these to use Iconv
+# ICONV_SECOND_ARGUMENT_IS_CONST - the second argument for iconv() is const
+#
+include(CheckCXXSourceCompiles)
+
+IF (ICONV_INCLUDE_DIR AND ICONV_LIBRARIES)
+  # Already in cache, be silent
+  SET(ICONV_FIND_QUIETLY TRUE)
+ENDIF (ICONV_INCLUDE_DIR AND ICONV_LIBRARIES)
+
+FIND_PATH(ICONV_INCLUDE_DIR iconv.h)
+
+FIND_LIBRARY(ICONV_LIBRARIES NAMES iconv libiconv libiconv-2 c)
+
+IF(ICONV_INCLUDE_DIR AND ICONV_LIBRARIES)
+  SET(ICONV_FOUND TRUE)
+  SET(ICONV_INCLUDE_DIRS ${ICONV_INCLUDE_DIR})
+ENDIF(ICONV_INCLUDE_DIR AND ICONV_LIBRARIES)
+
+set(CMAKE_REQUIRED_INCLUDES ${ICONV_INCLUDE_DIR})
+set(CMAKE_REQUIRED_LIBRARIES ${ICONV_LIBRARIES})
+IF(ICONV_FOUND)
+  check_cxx_source_compiles("
+  #include <iconv.h>
+    int main(){
+    iconv_t conv = 0;
+    const char* in = 0;
+    size_t ilen = 0;
+    char* out = 0;
+    size_t olen = 0;
+    iconv(conv, &in, &ilen, &out, &olen);
+    return 0;
+  }
+" ICONV_SECOND_ARGUMENT_IS_CONST )
+ENDIF(ICONV_FOUND)
+set(CMAKE_REQUIRED_INCLUDES)
+set(CMAKE_REQUIRED_LIBRARIES)
+
+IF(ICONV_FOUND)
+  IF(NOT ICONV_FIND_QUIETLY)
+    MESSAGE(STATUS "Found Iconv: ${ICONV_LIBRARIES}")
+  ENDIF(NOT ICONV_FIND_QUIETLY)
+ELSE(ICONV_FOUND)
+  IF(Iconv_FIND_REQUIRED)
+    MESSAGE(FATAL_ERROR "Could not find Iconv")
+  ENDIF(Iconv_FIND_REQUIRED)
+ENDIF(ICONV_FOUND)
+
+MARK_AS_ADVANCED(
+  ICONV_INCLUDE_DIR
+  ICONV_LIBRARIES
+  ICONV_SECOND_ARGUMENT_IS_CONST
+)
