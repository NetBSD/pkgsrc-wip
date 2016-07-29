$NetBSD$

--- build/workspaces/update-workspaces.sh.orig	2016-07-29 19:33:02.688237533 +0000
+++ build/workspaces/update-workspaces.sh
@@ -1,10 +1,5 @@
 #!/bin/sh
 
-if [ "$(id -u)" = "0" ]; then
-   echo "Running as root will mess up file permissions. Aborting ..." 1>&2
-   exit 1
-fi
-
 die()
 {
   echo ERROR: $*
