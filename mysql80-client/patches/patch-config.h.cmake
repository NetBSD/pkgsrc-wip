$NetBSD$

* bstring.h is needed for bzero on some platforms.
* check for ffsll and provide a portable version for sytems that
  don't have it.

--- config.h.cmake.orig	2019-12-09 19:53:17.000000000 +0000
+++ config.h.cmake
@@ -41,6 +41,7 @@
 /* Header files */
 #cmakedefine HAVE_ALLOCA_H 1
 #cmakedefine HAVE_ARPA_INET_H 1
+#cmakedefine HAVE_BSTRING_H 1
 #cmakedefine HAVE_DLFCN_H 1
 #cmakedefine HAVE_EXECINFO_H 1
 #cmakedefine HAVE_FPU_CONTROL_H 1
@@ -90,6 +91,7 @@
 #cmakedefine HAVE_FDATASYNC 1
 #cmakedefine HAVE_DECL_FDATASYNC 1
 #cmakedefine HAVE_FEDISABLEEXCEPT 1
+#cmakedefine HAVE_FFSLL 1
 #cmakedefine HAVE_FSYNC 1
 #cmakedefine HAVE_GETHRTIME 1
 #cmakedefine HAVE_GETNAMEINFO 1
