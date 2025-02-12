$NetBSD$

--- admin/download-android-deps.sh.orig	2025-02-12 10:28:07.380330814 +0000
+++ admin/download-android-deps.sh
@@ -11,7 +11,7 @@ set -e
 
 bits_64=no
 
-if [ "$1" == "64" ]; then
+if [ "$1" = "64" ]; then
     bits_64=yes
 fi
 
