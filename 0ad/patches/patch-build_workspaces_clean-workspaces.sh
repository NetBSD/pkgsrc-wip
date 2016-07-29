$NetBSD$

--- build/workspaces/clean-workspaces.sh.orig	2015-08-19 01:30:09.000000000 +0000
+++ build/workspaces/clean-workspaces.sh
@@ -3,7 +3,7 @@
 # Some of our makefiles depend on GNU make, so we set some sane defaults if MAKE
 # is not set.
 case "`uname -s`" in
-  "FreeBSD" | "OpenBSD" )
+  "FreeBSD" | "NetBSD" | "OpenBSD" )
     MAKE=${MAKE:="gmake"}
     ;;
   * )
@@ -37,7 +37,7 @@ fi
 
 echo "Removing generated test files..."
 
-find ../../source -name "test_*.cpp" -type f -not -name "test_setup.cpp" -exec rm {} \;
+find ../../source -name "test_*.cpp" -type f ! -name "test_setup.cpp" -exec rm {} \;
 
 echo "Cleaning build output..."
 
