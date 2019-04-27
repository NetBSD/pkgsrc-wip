$NetBSD$

Avoid HAVE_X11 TRUE, where TRUE is not defined yet!

--- config-X11.h.cmake.orig	2018-03-27 11:26:39.000000000 +0000
+++ config-X11.h.cmake
@@ -41,4 +41,4 @@
 #cmakedefine HAS_RANDR_1_3 1
 
 /* Define if you have X11 at all */
-#define HAVE_X11 ${X11_FOUND}
+#cmakedefine01 HAVE_X11
