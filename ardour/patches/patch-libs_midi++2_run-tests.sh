$NetBSD$

Patch merged upstream:
https://github.com/Ardour/ardour/commit/2b869e1563342e15b0336a3dc234de8a058b168e

--- libs/midi++2/run-tests.sh.orig	2015-10-15 12:59:11.000000000 +0000
+++ libs/midi++2/run-tests.sh
@@ -9,7 +9,7 @@ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:
 export MIDIPP_TEST_PATH=$TOP/patchfiles
 
 cd $LIBS_DIR/midi++2
-if [ "$1" == "debug" ]; then 
+if [ "$1" = "debug" ]; then
 	gdb ./run-tests
 else
 	./run-tests
