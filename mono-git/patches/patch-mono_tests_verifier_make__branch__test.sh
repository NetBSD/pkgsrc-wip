$NetBSD$

--- mono/tests/verifier/make_branch_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_branch_test.sh
@@ -11,7 +11,7 @@ TEST_POS=$3
 TEST_OP=$4
 TEST_FIN=$5
 
-if [ "$TEST_FIN" == "" ]; then
+if [ "x$TEST_FIN" = "x" ]; then
 	TEST_FIN="finally";
 fi
 
