$NetBSD: patch-autogen.sh,v 1.1 2015/05/08 12:43:31 jonthn Exp $

Add the options to disable po files update

--- autogen.sh.orig	2014-09-23 11:40:36.000000000 +0000
+++ autogen.sh
@@ -15,6 +15,27 @@ test -f free.c || {
 	DIE=1
 }
 
+UPDATEPO=yes
+autogen_options ()
+{
+  if test "x$1" = "x"; then
+    return 0
+  fi
+
+  while test "x$1" != "x" ; do
+    optarg=`expr "x$1" : 'x[^=]*=\(.*\)'`
+    case "$1" in
+      --nopo)
+          UPDATEPO=no
+          echo "+ po updates disabled"
+          shift
+          ;;
+       --) shift ; break ;;
+      *) echo "- ignoring unknown autogen.sh argument $1"; shift ;;
+    esac
+  done
+}
+
 (autopoint --version) < /dev/null > /dev/null 2>&1 || {
 	echo "You must have autopoint installed to generate procps-ng build system."
 	echo "The autopoint command is part of the GNU gettext package."
@@ -58,15 +79,19 @@ echo "   autoheader: $(autoheader --vers
 echo "   automake:   $(automake --version | head -1)"
 echo "   libtoolize: $(libtoolize --version | head -1)"
 
+autogen_options $@
+
 rm -rf autom4te.cache
 
 set -e
-po/update-potfiles
-autopoint --force $AP_OPTS
-if ! grep -q datarootdir po/Makefile.in.in; then
+if test ${UPDATEPO} = yes; then
+    po/update-potfiles
+    autopoint --force $AP_OPTS
+    if ! grep -q datarootdir po/Makefile.in.in; then
 	echo autopoint does not honor dataroot variable, patching.
 	sed -i -e 's/^datadir *=\(.*\)/datarootdir = @datarootdir@\
-datadir = @datadir@/g' po/Makefile.in.in
+	    datadir = @datadir@/g' po/Makefile.in.in
+    fi
 fi
 libtoolize --force ${LT_OPTS}
 aclocal -I m4 ${AL_OPTS}
