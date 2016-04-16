$NetBSD$

--- mono/tests/verifier/make_cmmp_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_cmmp_test.sh
@@ -14,7 +14,7 @@ TEST_BEFORE_OP=$6
 
 echo $TEST_OP | grep unbox > /dev/null;
 
-if [ "$?" == "0" ]; then
+if [ $? -eq 0 ]; then
 	TEST_CODE="
 	ldloc.0
 	box $TEST_TYPE";
