$NetBSD$

--- platforms/unix/plugins/UnicodePlugin/acinclude.m4.orig	2018-10-19 04:12:21.000000000 +0000
+++ platforms/unix/plugins/UnicodePlugin/acinclude.m4
@@ -1,12 +1,9 @@
-# -*- sh -*-
-
-AC_MSG_CHECKING([for PangoCairo libraries])
-save_CPPFLAGS="$CPPFLAGS"
-CPPFLAGS="-I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/lib/arm-linux-gnueabihf/glib-2.0/include -I/usr/lib/i386-linux-gnu/glib-2.0/include"
-AC_TRY_COMPILE([#include <pango/pangocairo.h>],[{}],[
-  AC_MSG_RESULT(yes)
-],[
-  AC_MSG_RESULT(no)
-  AC_PLUGIN_DISABLE
-])
-CPPFLAGS="$save_CPPFLAGS"
+# -*- sh -*-
+AC_MSG_CHECKING([for PangoCairo libraries])
+PKG_CHECK_MODULES([pangocairo], [pangocairo], [
+		      AC_MSG_RESULT(yes)
+		      CFLAGS="$CFLAGS $pangocairo_CFLAGS"
+		      LDFLAGS="$LDFLAGS $pangocairo_LIBS"
+		  ],[
+		      AC_MSG_RESULT(no)
+		  ])
