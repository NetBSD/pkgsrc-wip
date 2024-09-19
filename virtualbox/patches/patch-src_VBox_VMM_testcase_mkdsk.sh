$NetBSD$

--- src/VBox/VMM/testcase/mkdsk.sh.orig	2016-03-04 19:30:15.000000000 +0000
+++ src/VBox/VMM/testcase/mkdsk.sh
@@ -11,7 +11,7 @@
 # hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 #
 
-if [ "x$3" == "x" ]; then
+if [ "x$3" = "x" ]; then
 
     echo "syntax error"
     echo "syntax: $0 imagename <size-in-KBs> <init prog> [tar files]"
