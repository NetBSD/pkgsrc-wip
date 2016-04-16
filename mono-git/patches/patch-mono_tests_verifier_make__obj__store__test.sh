$NetBSD$

--- mono/tests/verifier/make_obj_store_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_obj_store_test.sh
@@ -18,7 +18,7 @@ echo $TEST_FILE
 TEST_TYPE1=`echo $TEST_TYPE1 | $SED -s 's/&/\\\&/'`
 TEST_TYPE2=`echo $TEST_TYPE2 | $SED -s 's/&/\\\&/'`
 
-if [ "$TEST_CREATE_FIELD" == "no" ]; then
+if [ "$TEST_CREATE_FIELD" = "no" ]; then
 	CLASS_FIELDS="";
 else
 	CLASS_FIELDS=".field public ${TEST_TYPE1} fld\n	.field public static ${TEST_TYPE1} sfld";
