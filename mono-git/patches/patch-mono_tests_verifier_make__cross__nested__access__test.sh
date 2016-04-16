$NetBSD$

--- mono/tests/verifier/make_cross_nested_access_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_cross_nested_access_test.sh
@@ -14,7 +14,7 @@ TEST_EXTENDS=$6
 TEST_LOAD_BASE=$7
 
 
-if [ "$TEST_EXTENDS" == "yes" ]; then
+if [ "$TEST_EXTENDS" = "yes" ]; then
 	TEST_EXTENDS="extends Owner\/Nested"
 	TEST_CONSTRUCTOR="call instance void Owner\/Nested::.ctor()"
 else
@@ -22,7 +22,7 @@ else
 	TEST_CONSTRUCTOR="call instance void object::.ctor()"
 fi
 
-if [ "$TEST_LOAD_BASE" == "yes" ]; then
+if [ "$TEST_LOAD_BASE" = "yes" ]; then
 	TEST_LOAD_REF="ldarg.0"
 else
 	TEST_LOAD_REF="call class Owner\/Nested Owner::Create ()"
