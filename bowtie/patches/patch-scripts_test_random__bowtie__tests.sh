$NetBSD$

# Remove bashisms
--- scripts/test/random_bowtie_tests.sh.orig	2018-09-14 16:08:02.613191531 +0000
+++ scripts/test/random_bowtie_tests.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 PREFIX=${0%/*}
 
@@ -9,7 +9,7 @@ else
 	shift
 fi
 
-if [ "$1" == "-c" ] ; then
+if [ "$1" = "-c" ] ; then
 	make clean
 	shift
 fi
