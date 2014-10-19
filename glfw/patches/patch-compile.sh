$NetBSD: patch-compile.sh,v 1.1 2014/10/19 17:42:27 nros Exp $
* Test and use $X11BASE/lib, add rpath
* Fix version number in pkgconfig file
--- compile.sh.orig	2013-05-30 14:07:32.000000000 +0000
+++ compile.sh
@@ -107,7 +107,11 @@ esac
 ##########################################################################
 echo -n "Checking for X11 libraries location... " 1>&6
 
-if [ -r "/usr/X11/lib" ]; then
+if [ -r "$X11BASE/lib" ]; then
+  GLFW_LFLAGS="$GLFW_LFLAGS -L$X11BASE/lib -R$X11BASE/lib"
+  GLFW_CFLAGS="-I$X11BASE/include $GLFW_CFLAGS"
+  echo "$X11BASE" 1>&6
+elif [ -r "/usr/X11/lib" ]; then
   GLFW_LFLAGS="$GLFW_LFLAGS -L/usr/X11/lib"
   GLFW_CFLAGS="-I/usr/X11/include $GLFW_CFLAGS"
   echo "/usr/X11/lib" 1>&6
@@ -738,7 +742,7 @@ libdir=\${exec_prefix}/lib
 
 Name: GLFW
 Description: A portable framework for OpenGL development
-Version: 2.7.4
+Version: 2.7.9
 URL: http://www.glfw.org/
 Requires.private: gl x11 $PKG_LIBS
 Libs: -L\${libdir} -lglfw $LFLAGS_THREAD $LFLAGS_CLOCK
