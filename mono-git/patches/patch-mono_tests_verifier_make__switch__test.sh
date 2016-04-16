$NetBSD$

--- mono/tests/verifier/make_switch_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_switch_test.sh
@@ -12,7 +12,7 @@ TEST_EXTRA=$4
 TEST_OP=$5
 TEST_FIN=$6
 
-if [ "$TEST_FIN" == "" ]; then
+if [ "x$TEST_FIN" = "x" ]; then
 	TEST_FIN="finally";
 fi
 
