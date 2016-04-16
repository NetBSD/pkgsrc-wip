$NetBSD$

--- mono/tests/verifier/make_tail_call_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_tail_call_test.sh
@@ -12,7 +12,7 @@ TEST_LOAD_OP=$4
 TEST_TYPE=$5
 TEST_RET_TYPE=$6
 
-if [ "$TEST_RET_TYPE" == "" ]; then
+if [ "x$TEST_RET_TYPE" = "x" ]; then
 	TEST_RET_TYPE="void"
 else
 	LD_RET_CODE="ldloc.0"
