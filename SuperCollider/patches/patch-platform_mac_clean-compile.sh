$NetBSD: patch-platform_mac_clean-compile.sh,v 1.1 2014/09/06 22:22:37 thomasklausner Exp $

Fix unportable test(1) construct.

--- platform/mac/clean-compile.sh.orig	2013-11-27 12:54:02.000000000 +0000
+++ platform/mac/clean-compile.sh
@@ -3,7 +3,7 @@
 # This script cleans all targets, then invokes compile.sh
 
 # Replicate warning from compile.sh, because it's user-friendly for it to be the first output:
-if [ $# == 0 ]; then
+if [ $# = 0 ]; then
 	echo "--------------------------------------------------------------------------------
 Building SuperCollider as a UNIVERSAL BINARY (intel + ppc).
 For faster build, or if you don't have UB versions of the libs (e.g. libsndfile),
