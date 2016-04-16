$NetBSD$

--- mono/tests/verifier/make_ctor_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_ctor_test.sh
@@ -13,7 +13,7 @@ TEST_TARGET_TYPE=$4
 TARGET_TYPE="Test"
 TEST_OTHER_CODE="call instance void TestClass::'.ctor'()"
 
-if [ "$TEST_TARGET_TYPE" == "other" ]; then
+if [ "$TEST_TARGET_TYPE" = "other" ]; then
 	TARGET_TYPE="TestSubClass"
 	TEST_OTHER_CODE=$TEST_CODE
 	TEST_CODE=""
