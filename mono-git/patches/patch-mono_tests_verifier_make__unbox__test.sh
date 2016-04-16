$NetBSD$

--- mono/tests/verifier/make_unbox_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_unbox_test.sh
@@ -12,7 +12,7 @@ TEST_TYPE2=$4
 TEST_POST_OP=$5
 TEST_NO_BOX=$6
 TEST_BOX="box ${TEST_TYPE1}";
-if [ "${TEST_NO_BOX}" == "yes" ]; then
+if [ "${TEST_NO_BOX}" = "yes" ]; then
 	TEST_BOX="";
 fi
 
