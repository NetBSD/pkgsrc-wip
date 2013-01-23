$NetBSD: patch-mkbindist.sh,v 1.1 2013/01/23 23:52:34 thomasklausner Exp $

Fix unportable test(1) construct.

--- mkbindist.sh.orig	2003-07-02 06:38:27.000000000 +0000
+++ mkbindist.sh
@@ -7,7 +7,7 @@ if [ $# -lt 2 ] ; then
   exit
 fi
 
-if [ $1 == "-dev" ] ; then
+if [ $1 = "-dev" ] ; then
   STRIP_DEV=0
   shift
 else
@@ -59,7 +59,7 @@ cc -o $DIST_DIR/bin/burnpath dist_docs/b
 #
 # Clean anything we don't want for non-developer releases.
 #
-if [ "$STRIP_DEV" == "1" ] ; then
+if [ "$STRIP_DEV" = "1" ] ; then
   rm -f $DIST_DIR/html/class_*
   rm -f $DIST_DIR/html/struct_*
   rm -f $DIST_DIR/html/*-source.html
