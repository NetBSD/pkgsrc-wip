$NetBSD: patch-contrib_mac_app_run-install-name-tool-change.sh,v 1.1 2015/05/18 03:40:54 genolopolis Exp $

--- contrib/mac/app/run-install-name-tool-change.sh.orig	2015-05-17 18:48:15.000000000 +0000
+++ contrib/mac/app/run-install-name-tool-change.sh
@@ -10,7 +10,7 @@ WRONG_PREFIX=$2
 RIGHT_PREFIX="@executable_path/../$3"
 ACTION=$4
 
-if [ "x$ACTION" == "xchange" ]; then
+if [ "x$ACTION" = "xchange" ]; then
     libs="`otool -L $LIBRARY 2>/dev/null | fgrep compatibility | cut -d\( -f1 | grep $WRONG_PREFIX | sort | uniq`"
     for lib in $libs; do
 	if ! echo $lib | grep --silent "@executable_path" ; then
@@ -18,7 +18,7 @@ if [ "x$ACTION" == "xchange" ]; then
 	    install_name_tool -change $lib $fixed $LIBRARY
 	fi
     done;
-elif [ "x$ACTION" == "xid" ]; then
+elif [ "x$ACTION" = "xid" ]; then
     lib="`otool -D $LIBRARY 2>/dev/null | grep ^$WRONG_PREFIX`"
     install_name_tool -id "$RIGHT_PREFIX/$lib" $LIBRARY;
 fi
