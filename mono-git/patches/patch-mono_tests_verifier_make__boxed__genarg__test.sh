$NetBSD$

--- mono/tests/verifier/make_boxed_genarg_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_boxed_genarg_test.sh
@@ -11,7 +11,7 @@ TEST_OP=$3
 TEST_BEFORE_OP=$4
 TEST_CONSTRAINT_TYPE=$5
 
-if [ "$TEST_CONSTRAINT_TYPE" == "" ]; then
+if [ "x$TEST_CONSTRAINT_TYPE" = "x" ]; then
 	TEST_CONSTRAINT_TYPE="IFace";
 fi
 
