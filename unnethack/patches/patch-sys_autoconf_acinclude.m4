$NetBSD: patch-sys_autoconf_acinclude.m4,v 1.1 2014/04/07 22:04:16 rhialto Exp $

--- sys/autoconf/acinclude.m4.orig	2013-12-08 15:00:26.000000000 +0000
+++ sys/autoconf/acinclude.m4
@@ -171,9 +171,9 @@ AC_DEFUN([NETHACK_CHECK_LIBXAW],[
     fi
     if test $nethack__succeeded = yes; then
 	NETHACK__ADD_FLAGS(nethack__cflags, [$NETHACK__LIBXAW_CFLAGS],
-	  [-I/usr/X11R6/include])
+	  [-I/usr/X11R7/include])
 	NETHACK__ADD_FLAGS(nethack__libs, [$NETHACK__LIBXAW_LIBS],
-	  [-L/usr/X11R6/lib -lXaw -lXmu -lXext -lXt -lX11])
+	  [-L/usr/X11R7/lib -lXaw -lXmu -lXext -lXt -lX11])
 	NETHACK__TRY_LIBXAW($1, [$nethack__cflags], [$nethack__libs],
 	  [nethack__succeeded=yes], [nethack__succeeded=no])
     fi
