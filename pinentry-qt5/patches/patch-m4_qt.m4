$NetBSD$

The "-rpath" option requires an equal sign.

--- m4/qt.m4.orig	2020-03-11 20:06:21.000000000 +0000
+++ m4/qt.m4
@@ -59,7 +59,7 @@ AC_DEFUN([FIND_QT],
 
     qtlibdir=`"$PKG_CONFIG" --variable libdir Qt5Core`
     if test -n "$qtlibdir"; then
-        PINENTRY_QT_LDFLAGS="$PINENTRY_QT_LDFLAGS -Wl,-rpath \"$qtlibdir\""
+        PINENTRY_QT_LDFLAGS="$PINENTRY_QT_LDFLAGS -Wl,-rpath=\"$qtlibdir\""
     fi
 
     AC_CHECK_TOOL(MOC, moc)
