$NetBSD$

--- installer/build-mac-dmg.sh.orig	2024-12-24 12:44:27.459588121 +0000
+++ installer/build-mac-dmg.sh
@@ -80,7 +80,7 @@ echo " Notarization ID: $REQUEST_UUID"
 REQUEST_STATUS="${BASH_REMATCH[2]}"
 echo " Notarization Status: $REQUEST_STATUS"
 
-if [ "$REQUEST_UUID" == "" ]; then
+if [ "$REQUEST_UUID" = "" ]; then
     echo "Failed to locate Notarization ID, exiting with error."
     exit 1
 fi
