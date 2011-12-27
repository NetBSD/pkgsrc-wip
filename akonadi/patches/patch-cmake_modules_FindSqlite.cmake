$NetBSD: patch-cmake_modules_FindSqlite.cmake,v 1.1 2011/12/27 10:06:13 absd Exp $

If pkg-config provides a sqlite version, use it in preference

--- cmake/modules/FindSqlite.cmake.orig	2011-05-07 09:22:49.000000000 +0000
+++ cmake/modules/FindSqlite.cmake
@@ -67,22 +67,26 @@ else( UNIX )
   set( SQLITE_STATIC_LIBRARIES ${SQLITE_LIBRARIES} )
 endif( UNIX )
 
-if(EXISTS ${SQLITE_INCLUDE_DIR}/sqlite3.h)
-  file(READ ${SQLITE_INCLUDE_DIR}/sqlite3.h SQLITE3_H_CONTENT)
-  string(REGEX MATCH "SQLITE_VERSION[ ]*\"[0-9.]*\"\n" SQLITE_VERSION_MATCH "${SQLITE3_H_CONTENT}")
-
-  if(SQLITE_VERSION_MATCH)
-    string(REGEX REPLACE ".*SQLITE_VERSION[ ]*\"(.*)\"\n" "\\1" SQLITE_VERSION ${SQLITE_VERSION_MATCH})
-
-    if(SQLITE_VERSION VERSION_LESS "${SQLITE_MIN_VERSION}")
-        message(STATUS "Sqlite ${SQLITE_VERSION} was found, but at least version ${SQLITE_MIN_VERSION} is required")
-        set(SQLITE_VERSION_OK FALSE)
-    else(SQLITE_VERSION VERSION_LESS "${SQLITE_MIN_VERSION}")
-        set(SQLITE_VERSION_OK TRUE)
-    endif(SQLITE_VERSION VERSION_LESS "${SQLITE_MIN_VERSION}")
-
-  endif(SQLITE_VERSION_MATCH)
-
+if( PC_SQLITE_VERSION )
+  set( SQLITE_VERSION ${PC_SQLITE_VERSION})
+else( PC_SQLITE_VERSION )
+  if(EXISTS ${SQLITE_INCLUDE_DIR}/sqlite3.h)
+    file(READ ${SQLITE_INCLUDE_DIR}/sqlite3.h SQLITE3_H_CONTENT)
+    string(REGEX MATCH "SQLITE_VERSION[ ]*\"[0-9.]*\"\n" SQLITE_VERSION_MATCH "${SQLITE3_H_CONTENT}")
+
+    if(SQLITE_VERSION_MATCH)
+      string(REGEX REPLACE ".*SQLITE_VERSION[ ]*\"(.*)\"\n" "\\1" SQLITE_VERSION ${SQLITE_VERSION_MATCH})
+    endif(SQLITE_VERSION_MATCH)
+  endif()
+endif( PC_SQLITE_VERSION )
+
+if (SQLITE_VERSION)
+  if(SQLITE_VERSION VERSION_LESS "${SQLITE_MIN_VERSION}")
+      message(STATUS "Sqlite ${SQLITE_VERSION} was found, but at least version ${SQLITE_MIN_VERSION} is required")
+      set(SQLITE_VERSION_OK FALSE)
+  else(SQLITE_VERSION VERSION_LESS "${SQLITE_MIN_VERSION}")
+      set(SQLITE_VERSION_OK TRUE)
+  endif(SQLITE_VERSION VERSION_LESS "${SQLITE_MIN_VERSION}")
 endif()
 
 include(FindPackageHandleStandardArgs)
