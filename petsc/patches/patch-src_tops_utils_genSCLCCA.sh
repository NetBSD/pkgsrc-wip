$NetBSD: patch-src_tops_utils_genSCLCCA.sh,v 1.1 2012/05/12 02:04:12 outpaddling Exp $

--- src/tops/utils/genSCLCCA.sh.orig	2010-03-25 14:13:16.000000000 +0000
+++ src/tops/utils/genSCLCCA.sh
@@ -62,7 +62,7 @@ done
 #echo $scope
 #echo $resolution
 #exit 0
-if [ "$language" == python ] ; then
+if [ "$language" = python ] ; then
   pythonImplLine="<class name=\"$className\" desc=\"python/impl\" />"
 fi;  
 if test "x$mode" = "xscl"; then
@@ -79,7 +79,7 @@ cat << __EOF1
 __EOF1
 for className in $classes; do
     echo "    <class name=\"$className\" desc=\"ior/impl\" />"
-    if [ "$language" == python ] ; then
+    if [ "$language" = python ] ; then
       echo "    <class name=\"$className\" desc=\"python/impl\" />"
     fi
 done
@@ -106,7 +106,7 @@ cat << __EOF3
 __EOF3
 for className in $classes; do
     echo "    <class name=\"$className\" desc=\"ior/impl\" />"
-    if [ "$language" == python ] ; then
+    if [ "$language" = python ] ; then
       echo "    <class name=\"$className\" desc=\"python/impl\" />"
     fi
 done
