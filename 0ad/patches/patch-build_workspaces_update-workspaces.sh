$NetBSD$

--- build/workspaces/update-workspaces.sh.orig	2015-06-14 20:43:12.000000000 +0000
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
@@ -26,7 +21,7 @@ JOBS=${JOBS:="-j2"}
 # Some of our makefiles depend on GNU make, so we set some sane defaults if MAKE
 # is not set.
 case "`uname -s`" in
-  "FreeBSD" | "OpenBSD" )
+  "FreeBSD" | "NetBSD" | "OpenBSD" )
     MAKE=${MAKE:="gmake"}
     ;;
   * )
