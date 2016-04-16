$NetBSD$

--- mono/tests/verifier/make_stobj_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_stobj_test.sh
@@ -16,7 +16,7 @@ ZZ=`echo $TEST_TYPE2 | grep "\&"`
 T2_REF=$?
 
 LOCAL_INIT="";
-if [ "$T2_REF" == "0" ]; then
+if [ $T2_REF -eq 0 ]; then
 	T2_NO_REF=`echo $TEST_TYPE2 | cut -d '\' -f 1`
 	INIT_LOCS=", $T2_NO_REF V_2"
 	INIT_IL="ldloca.s 2\n\tstloc.1"
