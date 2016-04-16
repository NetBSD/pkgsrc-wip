$NetBSD$

--- mono/tests/verifier/make_overlapped_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_overlapped_test.sh
@@ -12,7 +12,7 @@ TEST_POS_1=$4
 TEST_POS_2=$5
 TEST_TYPE_0=$6
 
-if [ "$TEST_TYPE_0" == "" ] ; then
+if [ "x$TEST_TYPE_0" = "x" ] ; then
 	TEST_TYPE_0="int32";
 fi
 
