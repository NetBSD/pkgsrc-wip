$NetBSD: patch-make_autoconf_lib-x11.m4,v 1.1 2019/10/01 12:36:34 tnn Exp $

Add rpath for X11.

--- make/autoconf/lib-x11.m4.orig	2021-06-10 07:19:56.734306890 -0400
+++ make/autoconf/lib-x11.m4	2021-06-10 13:10:09.531100936 -0400
@@ -88,6 +88,8 @@
       AC_MSG_ERROR([Could not find X11 libraries. $HELP_MSG])
     fi
 
+    X_LIBS="@COMPILER_RPATH_FLAG@${x_libraries} ${X_LIBS}"
+
     AC_LANG_PUSH(C)
     OLD_CFLAGS="$CFLAGS"
     CFLAGS="$CFLAGS $SYSROOT_CFLAGS $X_CFLAGS"
