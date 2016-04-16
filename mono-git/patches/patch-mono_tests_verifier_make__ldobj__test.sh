$NetBSD$

--- mono/tests/verifier/make_ldobj_test.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_ldobj_test.sh
@@ -13,7 +13,7 @@ ZZ=`echo $TEST_TYPE1 | grep "\&"`
 T1_REF=$?
 
 LOCAL_INIT="";
-if [ "$T1_REF" == "0" ]; then
+if [ $T1_REF -eq 0 ]; then
 	T1_NO_REF=`echo $TEST_TYPE1 | cut -d '\' -f 1`
 	INIT_LOCS=", $T1_NO_REF V_0"
 	INIT_IL="ldloca.s 1\n\tstloc.0"
