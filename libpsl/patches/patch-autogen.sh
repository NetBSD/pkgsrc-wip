$NetBSD$

Skip use of gtk-doc.
--- autogen.sh.orig	2018-04-26 18:18:39.000000000 +0000
+++ autogen.sh
@@ -15,17 +15,12 @@ fi
 #  create m4 before gtkdocize
 mkdir -p m4 2>/dev/null
 
-GTKDOCIZE=$(which gtkdocize 2>/dev/null)
-if test $? -ne 0; then
   echo "No gtk-doc support found. You can't build the docs."
   # rm because gtk-doc.make might be a link to a protected file
   rm -f gtk-doc.make 2>/dev/null
   echo "EXTRA_DIST =" >gtk-doc.make
   echo "CLEANFILES =" >>gtk-doc.make
   GTKDOCIZE=""
-else
-  $GTKDOCIZE
-fi
 
 $GIT submodule init
 $GIT submodule update
