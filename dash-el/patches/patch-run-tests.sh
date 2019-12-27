$NetBSD$

CHECK_PORTABILITY

--- run-tests.sh.orig	2019-12-27 21:57:12.854280102 +0900
+++ run-tests.sh	2019-12-27 21:55:18.150666839 +0900
@@ -25,7 +25,7 @@ $EMACS -batch \
 
 VERSION=`$EMACS -version | head -1 | cut -d" " -f3`
 
-if [[ $VERSION == "24.1.1" ]] || [[ $VERSION == "24.2.1" ]] ; then
+if [[ $VERSION = "24.1.1" ]] || [[ $VERSION = "24.2.1" ]] ; then
     echo Skipping byte compile check for early Emacs version
 else
     $EMACS -Q --batch \
