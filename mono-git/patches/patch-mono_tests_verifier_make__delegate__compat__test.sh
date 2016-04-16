$NetBSD$

--- mono/tests/verifier/make_delegate_compat_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_delegate_compat_test.sh
@@ -26,7 +26,7 @@ fi
 RET_2_LOCAL="$TEST_RET_TYPE2"
 RET_2_OP="ldloc 0"
 
-if [ "$TEST_RET_TYPE2" == "void" ]; then
+if [ "$TEST_RET_TYPE2" = "void" ]; then
 	RET_2_LOCAL="int32"
 	RET_2_OP="nop"
 fi
@@ -47,7 +47,7 @@ MANAGED_METHOD="
 	}
 "
 
-if [ "$TEST_USE_NATIVE" == "pinvoke" ]; then
+if [ "$TEST_USE_NATIVE" = "pinvoke" ]; then
 	LDFTN="ldftn $TCONV_2 ${TEST_RET_TYPE2} Driver::NativeMethod(${TEST_PARAM_TYPE2})"
 	CALLVIRT="nop"
 	MANAGED_METHOD=""
