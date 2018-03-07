$NetBSD$

--- build-mg.sh.orig	2018-03-07 10:41:05.899626541 +0000
+++ build-mg.sh
@@ -107,9 +107,10 @@ EXTRA_CMAKE_OPTIONS=
 
 # Build threads
 # By default we use all physical CPU cores to build.
-NUMCORES=`lscpu -p | grep -cv '^#'`
+NUMCORES=`lscpu -p | grep -cv '^#'| wc -l`
 echo "CPU cores detected: $NUMCORES"
 if [ "$NUMCORES" = '' ]; then NUMCORES=1; fi
+if [ "$NUMCORES" = '0' ]; then NUMCORES=1; fi
 if [ $CPU_COUNT != -1 ]; then NUMCORES=$CPU_COUNT; fi
 echo "CPU cores to be used: $NUMCORES"
 
