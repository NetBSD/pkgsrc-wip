$NetBSD$

--- mono/tests/verifier/make_bin_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_bin_test.sh
@@ -12,7 +12,7 @@ TEST_TYPE2=$5
 TEST_INIT_EXP=$6
 TEST_INIT_VAL=$7
 
-if [ "$TEST_INIT_VAL" == "yes" ]; then
+if [ "$TEST_INIT_VAL" = "yes" ]; then
 	TEST_INIT="$TEST_INIT_EXP\n\t\stloc.1"
 else
 	TEST_INIT=""
@@ -50,4 +50,4 @@ $SED -e "s/INIT/${TEST_INIT}/g" -e "s/VA
 	ldc.i4.0
 	ret
 }
-//EOF
\ No newline at end of file
+//EOF
