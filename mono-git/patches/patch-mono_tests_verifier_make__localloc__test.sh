$NetBSD$

--- mono/tests/verifier/make_localloc_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_localloc_test.sh
@@ -16,14 +16,14 @@ TRY_END="
 		leave END
 	}"
 
-if [ "$TEST_BLOCK" == "catch" ]; then
+if [ "$TEST_BLOCK" = "catch" ]; then
 	TRY_MIDDLE="
 		leave END
 	} catch [mscorlib]System.NullReferenceException {"
 	TRY_END="
 		leave END
 	}"
-elif [ "$TEST_BLOCK" == "filter" ]; then
+elif [ "$TEST_BLOCK" = "filter" ]; then
 	TRY_MIDDLE="
 		leave END
 	} filter {"
@@ -34,7 +34,7 @@ elif [ "$TEST_BLOCK" == "filter" ]; then
 	} {
 		leave END
 	}"
-elif [ "$TEST_BLOCK" == "handler" ]; then
+elif [ "$TEST_BLOCK" = "handler" ]; then
 	TRY_MIDDLE="
 		leave END
 	} filter {
@@ -45,14 +45,14 @@ elif [ "$TEST_BLOCK" == "handler" ]; the
 	TRY_END="
 		leave END
 	}"
-elif [ "$TEST_BLOCK" == "finally" ]; then
+elif [ "$TEST_BLOCK" = "finally" ]; then
 	TRY_MIDDLE="
 		leave END
 	} finally {"
 	TRY_END="
 		endfinally
 	}"
-elif [ "$TEST_BLOCK" == "fault" ]; then
+elif [ "$TEST_BLOCK" = "fault" ]; then
 	TRY_MIDDLE="
 		leave END
 	} fault {"
