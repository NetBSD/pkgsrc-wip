$NetBSD: patch-third-party_cmake_FindMySQL.cmake $

Find buildlink mysql include dir

--- third-party/cmake/FindMySQL.cmake.orig	2018-07-24 12:48:12.000000000 +0200
+++ third-party/cmake/FindMySQL.cmake	2018-08-28 16:28:14.000000000 +0200
@@ -31,22 +31,10 @@
 FILE(GLOB _macports_include_dirs /opt/local/include/mysql*/mysql)
 
 #-------------- FIND MYSQL_INCLUDE_DIR ------------------
-FIND_PATH(MYSQL_INCLUDE_DIR mysql.h
-  $ENV{MYSQL_INCLUDE_DIR}
-  $ENV{MYSQL_DIR}/include
-  /usr/include/mysql
-  /usr/local/include/mysql
-  /opt/mysql/mysql/include
-  /opt/mysql/mysql/include/mysql
-  /opt/mysql/include
-  /opt/local/include/mysql5
-  /usr/local/mysql/include
-  /usr/local/mysql/include/mysql
-  ${_macports_include_dirs}
-  $ENV{ProgramFiles}/MySQL/*/include
-  $ENV{SystemDrive}/MySQL/*/include)
-
-UNSET(_macports_include_dirs)
+FIND_PATH(MYSQL_INCLUDE_DIR
+  NAMES mysql.h
+  PATH_SUFFIXES mysql
+)
 
 #----------------- FIND MYSQL_LIB_DIR -------------------
 IF (WIN32)
