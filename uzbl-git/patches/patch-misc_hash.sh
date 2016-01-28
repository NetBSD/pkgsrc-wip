$NetBSD$

Try to use a commit ID if there are no tags available.

--- misc/hash.sh.orig	2015-12-29 21:19:52.000000000 +0000
+++ misc/hash.sh
@@ -9,7 +9,7 @@ tarball_check='$Format:$'
 
 # ... but try to use whatever git tells us if there is a .git folder
 if [ -d .git ] && [ -r .git ]; then
-    hash=$( git describe --tags )
+    hash=$( git describe --tags --always )
     echo $hash
 elif [ -n "$tarball_check" ]; then
     echo '$Format:%h$'
