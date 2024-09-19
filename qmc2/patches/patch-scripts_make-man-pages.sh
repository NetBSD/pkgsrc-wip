$NetBSD: patch-scripts_make-man-pages.sh,v 1.1 2013/12/07 00:39:22 thomasklausner Exp $

Unportable test(1) comparison operator.

--- scripts/make-man-pages.sh.orig	2013-08-30 07:49:00.000000000 +0000
+++ scripts/make-man-pages.sh
@@ -7,17 +7,17 @@ usage() {
 }
 
 MAN_SOURCE_FOLDER=$1
-if [ "$MAN_SOURCE_FOLDER" == "" ]; then
+if [ "$MAN_SOURCE_FOLDER" = "" ]; then
 	usage
 fi
 
 VERSION=$2
-if [ "$VERSION" == "" ]; then
+if [ "$VERSION" = "" ]; then
 	usage
 fi
 
 ARCH=$3
-if [ "$ARCH" == "" ]; then
+if [ "$ARCH" = "" ]; then
 	usage
 fi
 
