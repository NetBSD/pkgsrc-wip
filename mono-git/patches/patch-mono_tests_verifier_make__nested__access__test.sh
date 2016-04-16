$NetBSD$

--- mono/tests/verifier/make_nested_access_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_nested_access_test.sh
@@ -12,7 +12,7 @@ TEST_CLASS_ACCESS=$4
 TEST_MEMBER_ACCESS=$5
 TEST_EXTENDS=$6
 
-if [ "$TEST_EXTENDS" == "yes" ]; then
+if [ "$TEST_EXTENDS" = "yes" ]; then
 	TEST_EXTENDS="extends Owner"
 	TEST_CONSTRUCTOR="call instance void Owner::.ctor()"
 else
@@ -108,4 +108,4 @@ $SED -e "s/VALIDITY/${TEST_VALIDITY}/g" 
 	ldc.i4.0
 	ret
 }
-//EOF
\ No newline at end of file
+//EOF
