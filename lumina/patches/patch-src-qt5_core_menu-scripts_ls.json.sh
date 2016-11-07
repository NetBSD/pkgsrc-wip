$NetBSD$

--- src-qt5/core/menu-scripts/ls.json.sh.orig	2016-10-21 14:48:55.000000000 +0000
+++ src-qt5/core/menu-scripts/ls.json.sh
@@ -1,6 +1,6 @@
 #!/bin/sh
 DIR=${1}
-if [ "$1" == "" ] ; then
+if [ "$1" = "" ] ; then
   DIR=`pwd`
 fi
 
