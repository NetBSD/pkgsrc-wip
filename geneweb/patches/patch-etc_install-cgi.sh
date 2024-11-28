$NetBSD$

Bashism exorcism.

Not yet reported upstream.

--- etc/install-cgi.sh.orig	2024-11-28 15:43:55.989604458 +0000
+++ etc/install-cgi.sh
@@ -42,7 +42,7 @@ DIR="$(dirname "$0")"
 cd "$DIR"
 PWD=`pwd`
 
-if ! [ $MY_BASES == "" ]; then
+if ! [ $MY_BASES = "" ]; then
   echo "Set link to my bases"
   rm -f -R $WEB_ROOT/$DISTRIB_NAME/bases
   ln -s $MY_BASES $WEB_ROOT/$DISTRIB_NAME/bases
