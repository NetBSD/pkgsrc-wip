$NetBSD$

--- mono/tests/verifier/make_double_nesting_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_double_nesting_test.sh
@@ -16,7 +16,7 @@ TEST_NESTED_EXTENDS=$8
 TEST_LOAD_BASE=$9
 
 
-if [ "$TEST_BASE_EXTENDS" == "yes" ]; then
+if [ "$TEST_BASE_EXTENDS" = "yes" ]; then
 	TEST_BASE_EXTENDS="extends Root"
 	TEST_BASE_CONSTRUCTOR="call instance void Root::.ctor()"
 else
@@ -24,7 +24,7 @@ else
 	TEST_BASE_CONSTRUCTOR="call instance void object::.ctor()"
 fi
 
-if [ "$TEST_NESTED_EXTENDS" == "yes" ]; then
+if [ "$TEST_NESTED_EXTENDS" = "yes" ]; then
 	TEST_NESTED_EXTENDS="extends Root\/Nested"
 	TEST_NESTED_CONSTRUCTOR="call instance void Root\/Nested::.ctor()"
 else
@@ -32,7 +32,7 @@ else
 	TEST_NESTED_CONSTRUCTOR="call instance void object::.ctor()"
 fi
 
-if [ "$TEST_LOAD_BASE" == "yes" ]; then
+if [ "$TEST_LOAD_BASE" = "yes" ]; then
 	TEST_LOAD_REF="ldarg.0"
 else
 	TEST_LOAD_REF="call class Root\/Nested Root::Create ()"
