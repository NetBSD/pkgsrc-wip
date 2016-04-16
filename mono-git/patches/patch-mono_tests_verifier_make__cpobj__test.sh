$NetBSD$

--- mono/tests/verifier/make_cpobj_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_cpobj_test.sh
@@ -15,7 +15,7 @@ TEST_EXTRA_OPS=$6
 ZZ=`echo $TEST_TYPE1 | grep "\&"`
 T1_REF=$?
 
-if [ "$T1_REF" == "0" ]; then
+if [ $T1_REF -eq 0 ]; then
 	T1_NO_REF=`echo $TEST_TYPE1 | cut -d '\' -f 1`
 	INIT_LOCS=", $T1_NO_REF V_2"
 	INIT_IL="ldloca.s 2\n\tstloc.0"
@@ -24,9 +24,9 @@ fi
 ZZ=`echo $TEST_TYPE2 | grep "\&"`
 T2_REF=$?
 
-if [ "$T2_REF" == "0" ]; then
+if [ $T2_REF -eq 0 ]; then
 	T2_NO_REF=`echo $TEST_TYPE2 | cut -d '\' -f 1`
-	if [ "$T1_REF" == "0" ]; then
+	if [ $T1_REF -eq 0 ]; then
 		INIT_LOCS="$INIT_LOCS , $T2_NO_REF V_3"
 		INIT_IL="$INIT_IL \n\tldloca.s 3\n\tstloc.1"
 	else
