$NetBSD$

Avoid HAVE_X11 TRUE, where TRUE is not defined yet!

--- runners/windows/config-windowsrunner.h.cmake.orig	2018-03-27 11:26:39.000000000 +0000
+++ runners/windows/config-windowsrunner.h.cmake
@@ -1,2 +1,2 @@
 /* Define if you have X11 at all */
-#define HAVE_X11 ${X11_FOUND}
\ No newline at end of file
+#cmakedefine01 HAVE_X11
