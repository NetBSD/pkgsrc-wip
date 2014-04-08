$NetBSD: patch-sys_autoconf_acinclude.m4,v 1.2 2014/04/08 21:02:25 rhialto Exp $

Hopefully equivalent to the patch of configure, which is a generated file.

--- sys/autoconf/acinclude.m4.orig	2013-12-08 15:00:26.000000000 +0000
+++ sys/autoconf/acinclude.m4
@@ -156,7 +156,10 @@ AC_DEFUN([NETHACK_CHECK_LIBXAW],[
 	NETHACK__ADD_FLAGS(nethack__libs, [$NETHACK__LIBXAW_LIBS],
 	  [$LIBXAW_LIBS])
 	NETHACK__TRY_LIBXAW($1, [$nethack__cflags], [$nethack__libs],
-	  [nethack__succeeded=yes], [nethack__succeeded=no])
+	  [nethack__succeeded=yes
+           NETHACK__LIBXAW_CFLAGS="$nethack__cflags"
+           NETHACK__LIBXAW_LIBS="$nethack__libs"],
+	  [nethack__succeeded=no])
     else
 	nethack__succeeded=maybe
     fi
@@ -170,10 +173,12 @@ AC_DEFUN([NETHACK_CHECK_LIBXAW],[
 	PKG_CHECK_EXISTS(xaw6, [nethack__succeeded=yes], [])
     fi
     if test $nethack__succeeded = yes; then
+	dnl These -I and -L options are surely already included in
+	dnl the flags as obtained so far!?
 	NETHACK__ADD_FLAGS(nethack__cflags, [$NETHACK__LIBXAW_CFLAGS],
-	  [-I/usr/X11R6/include])
+	  [-I/usr/X11R7/include])
 	NETHACK__ADD_FLAGS(nethack__libs, [$NETHACK__LIBXAW_LIBS],
-	  [-L/usr/X11R6/lib -lXaw -lXmu -lXext -lXt -lX11])
+	  [-L/usr/X11R7/lib -lXaw -lXmu -lXext -lXt -lX11])
 	NETHACK__TRY_LIBXAW($1, [$nethack__cflags], [$nethack__libs],
 	  [nethack__succeeded=yes], [nethack__succeeded=no])
     fi
