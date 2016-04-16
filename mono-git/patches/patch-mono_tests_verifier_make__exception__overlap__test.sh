$NetBSD$

--- mono/tests/verifier/make_exception_overlap_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_exception_overlap_test.sh
@@ -12,7 +12,7 @@ TEST_BLOCK_2=$4
 TEST_WITH_FILTER_BLOCK=$5
 TEST_WITH_FINALLY_BLOCK=$6
 
-if [ "$TEST_WITH_FILTER_BLOCK" == "yes" ]; then
+if [ "$TEST_WITH_FILTER_BLOCK" = "yes" ]; then
 	FILTER_BLOCK="
 FILTER_BLOCK_3:
 	nop
@@ -35,7 +35,7 @@ else
 	FILTER_BLOCK="";
 fi
 
-if [ "$TEST_WITH_FINALLY_BLOCK" == "yes" ]; then
+if [ "$TEST_WITH_FINALLY_BLOCK" = "yes" ]; then
 	FINALLY_BLOCK="
 FINALLY_BLOCK_1:
 	nop
