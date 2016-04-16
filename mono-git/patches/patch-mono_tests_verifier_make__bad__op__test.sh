$NetBSD$

--- mono/tests/verifier/make_bad_op_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_bad_op_test.sh
@@ -11,7 +11,7 @@ TEST_BYTE_0=$3
 TEST_BYTE_1=$4
 
 
-if [ "$TEST_BYTE_1" == "" ] ; then
+if [ "x$TEST_BYTE_1" = "x" ] ; then
 	TEST_BYTE_1="0";
 fi
 
