$NetBSD: patch-platform_mac_compile.sh,v 1.1 2014/09/06 22:22:37 thomasklausner Exp $

Fix unportable test(1) construct.

--- platform/mac/compile.sh.orig	2013-11-27 12:54:02.000000000 +0000
+++ platform/mac/compile.sh
@@ -2,7 +2,7 @@
 
 # This script builds the server, the plugins and the application (sclang), one after another.
 
-if [ $# == 0 ]; then
+if [ $# = 0 ]; then
 	echo "--------------------------------------------------------------------------------
 Building SuperCollider as a 32 bit UNIVERSAL BINARY (intel + ppc).
 For faster build, or if you don't have UB versions of the libs 
@@ -20,7 +20,7 @@ switchableConfig="Deployment"
 buildArg=$*
 for opt in $*
 do
-    if [ $opt == "ARCHS=32_64" ]; then
+    if [ $opt = "ARCHS=32_64" ]; then
 		switchableConfig="Deployment32-64"
 		buildArg=""
         echo "Building 32/64 bit sclang, scsynth and plugins"
