$NetBSD: patch-join-duplicates.sh,v 1.2 2012/07/05 14:47:43 othyro Exp $

Using = instead of == for comparison.

--- join-duplicates.sh.orig	2011-04-10 13:17:26.000000000 +0000
+++ join-duplicates.sh
@@ -10,7 +10,7 @@
 # to a single physical file, thus saving disk space.  Use with care.
 #
 
-if [ "$1" == '' ]; then
+if [ "$1" = '' ]; then
   echo "usage: `basename $0` directory"
   exit 1
 fi
@@ -19,10 +19,10 @@ duff -r '-f#' -z -p -P "$1" |
 (
   while read file 
   do
-    if [ "$file" == '#' ]; then
+    if [ "$file" = '#' ]; then
       first=''
     else
-      if [ "$first" == '' ]; then
+      if [ "$first" = '' ]; then
         first="$file"
       else
 	temp=`mktemp -p \`dirname $file\``
