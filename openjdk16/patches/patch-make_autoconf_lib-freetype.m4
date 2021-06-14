$NetBSD: patch-make_autoconf_lib-freetype.m4,v 1.1 2019/10/01 12:36:34 tnn Exp $

Add rpath for freetype.

--- make/autoconf/lib-freetype.m4.orig	2021-06-10 07:19:56.695594572 -0400
+++ make/autoconf/lib-freetype.m4	2021-06-10 13:08:49.396360360 -0400
@@ -221,7 +221,7 @@
     fi
 
     if test "x$FREETYPE_LIBS" = "x" ; then
-      FREETYPE_LIBS="-L$FREETYPE_LIB_PATH -l$FREETYPE_BASE_NAME"
+      FREETYPE_LIBS="@COMPILER_RPATH_FLAG@$FREETYPE_LIB_PATH -L$FREETYPE_LIB_PATH -l$FREETYPE_BASE_NAME"
     fi
   fi
 
