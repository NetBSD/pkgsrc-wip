$NetBSD$

--- mono/tests/verifier/make_field_store_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_field_store_test.sh
@@ -11,7 +11,7 @@ TEST_OP=$3
 TEST_TYPE1=$4
 TEST_TYPE2=$5
 TEST_EMIT_CSTOR=$6
-if [ "${TEST_EMIT_CSTOR}" == "yes" ]; then
+if [ "${TEST_EMIT_CSTOR}" = "yes" ]; then
 	TEST_CSTOR="newobj instance void ${TEST_TYPE2}::.ctor()";
 else
 	TEST_CSTOR="ldloc.0";
