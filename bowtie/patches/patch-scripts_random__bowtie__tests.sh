$NetBSD: patch-scripts_random__bowtie__tests.sh,v 1.1 2013/09/01 15:56:45 asau Exp $

--- scripts/random_bowtie_tests.sh.orig	2013-04-18 19:33:39.000000000 +0000
+++ scripts/random_bowtie_tests.sh
@@ -7,7 +7,7 @@ else
 	shift
 fi
 
-if [ "$1" == "-c" ] ; then
+if [ "$1" = "-c" ] ; then
 	rm -f bowtie bowtie-debug bowtie-build-debug bowtie-inspect-debug
 	shift
 fi
