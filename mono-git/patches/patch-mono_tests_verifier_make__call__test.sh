$NetBSD$

--- mono/tests/verifier/make_call_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_call_test.sh
@@ -12,7 +12,7 @@ TEST_LOAD_ARGS=$4
 TEST_INSTANCE_METHOD=$5
 TEST_EXTRA_STUFF=$6
 
-if [ "$TEST_INSTANCE_METHOD" == "instance" ]; then
+if [ "$TEST_INSTANCE_METHOD" = "instance" ]; then
 	MEMBER_TEST_OP=$TEST_OP
 	MEMBER_TEST_LOAD_ARGS=$TEST_LOAD_ARGS
 	MEMBER_TEST_EXTRA_STUFF=$6
