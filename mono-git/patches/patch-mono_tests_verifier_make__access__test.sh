$NetBSD$

--- mono/tests/verifier/make_access_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_access_test.sh
@@ -13,7 +13,7 @@ TEST_MEMBER_ACCESS=$5
 TEST_EXTENDS=$6
 TEST_USE_SUB_CLASS=$7
 
-if [ "$TEST_EXTENDS" == "yes" ]; then
+if [ "$TEST_EXTENDS" = "yes" ]; then
 	TEST_EXTENDS="extends Class"
 	TEST_SUPER_TYPE="Class"
 else
@@ -21,7 +21,7 @@ else
 	TEST_SUPER_TYPE="object"
 fi
 
-if [ "$TEST_USE_SUB_CLASS" == "yes" ]; then
+if [ "$TEST_USE_SUB_CLASS" = "yes" ]; then
 	TEST_VAR_TYPE="ExampleClass"
 else
 	TEST_VAR_TYPE="Class"
@@ -87,4 +87,4 @@ $SED -e "s/SUPER_TYPE/${TEST_SUPER_TYPE}
 		ret
 	}
 }
-//EOF
\ No newline at end of file
+//EOF
