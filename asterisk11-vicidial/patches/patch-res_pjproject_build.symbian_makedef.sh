$NetBSD$

--- res/pjproject/build.symbian/makedef.sh.orig	2016-03-29 19:25:17.000000000 +0000
+++ res/pjproject/build.symbian/makedef.sh
@@ -1,13 +1,13 @@
 #!/bin/sh
 
 MMP=$1
-if test "$MMP" == ""; then
+if test "$MMP" = ""; then
 	echo "Usage: makedef.sh FILE.MMP"
 	echo "    or makedef.sh all"
 	exit 1
 fi
 
-if test "$MMP" == "all"; then
+if test "$MMP" = "all"; then
 	. $0 pjlib.mmp
 	. $0 pjlib_util.mmp
 	. $0 pjnath.mmp
