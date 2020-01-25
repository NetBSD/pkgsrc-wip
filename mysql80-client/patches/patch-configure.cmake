$NetBSD$

* bstring.h is need for bzero on some platforms
* check for ffsll and provide a portable version if not found

--- configure.cmake.orig	2019-12-09 19:53:17.000000000 +0000
+++ configure.cmake
@@ -199,13 +199,9 @@ ENDIF()
 #
 INCLUDE (CheckIncludeFiles)
 
-IF(FREEBSD)
-  # On FreeBSD some includes, e.g. sasl/sasl.h, is in /usr/local/include
-  LIST(APPEND CMAKE_REQUIRED_INCLUDES "/usr/local/include")
-ENDIF()
-
 CHECK_INCLUDE_FILES (alloca.h HAVE_ALLOCA_H)
 CHECK_INCLUDE_FILES (arpa/inet.h HAVE_ARPA_INET_H)
+CHECK_INCLUDE_FILES (bstring.h HAVE_BSTRING_H)
 CHECK_INCLUDE_FILES (dlfcn.h HAVE_DLFCN_H)
 CHECK_INCLUDE_FILES (endian.h HAVE_ENDIAN_H)
 CHECK_INCLUDE_FILES (execinfo.h HAVE_EXECINFO_H)
@@ -269,6 +265,7 @@ CHECK_FUNCTION_EXISTS (fcntl HAVE_FCNTL)
 CHECK_FUNCTION_EXISTS (fdatasync HAVE_FDATASYNC)
 CHECK_SYMBOL_EXISTS(fdatasync "unistd.h" HAVE_DECL_FDATASYNC)
 CHECK_FUNCTION_EXISTS (fedisableexcept HAVE_FEDISABLEEXCEPT)
+CHECK_FUNCTION_EXISTS (ffsll HAVE_FFSLL)
 CHECK_FUNCTION_EXISTS (fsync HAVE_FSYNC)
 CHECK_FUNCTION_EXISTS (gethrtime HAVE_GETHRTIME)
 CHECK_FUNCTION_EXISTS (getnameinfo HAVE_GETNAMEINFO)
