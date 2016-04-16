$NetBSD$

--- mono/tests/verifier/make_tests.sh.orig	2016-04-16 14:26:45.000000000 +0000
+++ mono/tests/verifier/make_tests.sh
@@ -25,7 +25,7 @@ done
 I=1
 for OP in add div mul rem sub
 do
-  if [ "$OP" == "div" ] || [ "$OP" == "rem" ]; then
+  if [ "$OP" = "div" ] || [ "$OP" = "rem" ]; then
   	INIT="yes";
   else
   	INIT="no";
@@ -92,7 +92,7 @@ done
 I=1
 for OP in div mul rem
 do
-  if [ "$OP" == "div" ] || [ "$OP" == "div" ]; then
+  if [ "$OP" = "div" ] || [ "$OP" = "div" ]; then
   	INIT="yes";
   else
   	INIT="no";
@@ -112,7 +112,7 @@ done
 I=1
 for OP in div mul rem add
 do
-  if [ "$OP" == "div" ] || [ "$OP" == "div" ]; then
+  if [ "$OP" = "div" ] || [ "$OP" = "div" ]; then
   	INIT="yes";
   else
   	INIT="no";
@@ -503,9 +503,9 @@ function fix () {
 		A=$1;
 	fi
 
-	if [ "$A" == "bool&" ]; then
+	if [ "$A" = "bool&" ]; then
 		A="int8&";
-	elif [ "$A" == "char&" ]; then
+	elif [ "$A" = "char&" ]; then
 		A="int16&";
 	fi
 
@@ -522,11 +522,11 @@ do
 		do
 			TA="$(fix $TYPE1)"
 			TB="$(fix $TYPE2)"
-			if [ "$TA" == "$TB" ]; then
+			if [ "$TA" = "$TB" ]; then
 				./make_store_test.sh ref_coercion_${I} valid "$OP" "$TYPE1" "$TYPE2"
-			elif [ "$TA" == "int32&" ] && [ "$TB" == "int&" ]; then
+			elif [ "$TA" = "int32&" ] && [ "$TB" = "int&" ]; then
 				./make_store_test.sh ref_coercion_${I} valid "$OP" "$TYPE1" "$TYPE2"
-			elif [ "$TA" == "int&" ] && [ "$TB" == "int32&" ]; then
+			elif [ "$TA" = "int&" ] && [ "$TB" = "int32&" ]; then
 				./make_store_test.sh ref_coercion_${I} valid "$OP" "$TYPE1" "$TYPE2"
 			else
 				./make_store_test.sh ref_coercion_${I} unverifiable "$OP" "$TYPE1" "$TYPE2"
@@ -545,7 +545,7 @@ do
 		do
 			TA="$(fix $TYPE1)"
 			TB="$(fix $TYPE2)"
-			if [ "$TA" == "$TB" ]; then
+			if [ "$TA" = "$TB" ]; then
 				./make_store_test.sh ref_coercion_${I} valid "$OP" "$TYPE1" "$TYPE2"
 			else
 				./make_store_test.sh ref_coercion_${I} unverifiable "$OP" "$TYPE1" "$TYPE2"
@@ -561,7 +561,7 @@ do
 	do
 		for TYPE2 in 'class ClassA&' 'class ClassB&' 'class InterfaceA&' 'class InterfaceB&' 'class ValueType&'
 		do
-			if [ "$TYPE1" == "$TYPE2" ]; then
+			if [ "$TYPE1" = "$TYPE2" ]; then
 				./make_store_test.sh ref_coercion_${I} valid "$OP" "$TYPE1" "$TYPE2"
 			else
 				./make_store_test.sh ref_coercion_${I} unverifiable "$OP" "$TYPE1" "$TYPE2"
@@ -791,17 +791,17 @@ do
  	ZZ=`echo $TYPE2 | grep "*";`
  	T2_PTR=$?
  	
-    if (($T1_PTR == 0  ||  $T2_PTR == 0)); then
+    if (($T1_PTR = 0  ||  $T2_PTR = 0)); then
 		./make_stack_merge_test.sh stack_merge_${I} unverifiable "$TYPE1" "$TYPE2"
-    elif [ "$TYPE1" == "$TYPE2" ]; then
+    elif [ "$TYPE1" = "$TYPE2" ]; then
 		./make_stack_merge_test.sh stack_merge_${I} valid "$TYPE1" "$TYPE2"
-	elif [ "$TYPE1" == "int32" ] && [ "$TYPE2" == "native int" ]; then
+	elif [ "$TYPE1" = "int32" ] && [ "$TYPE2" = "native int" ]; then
 		./make_stack_merge_test.sh stack_merge_${I} valid "$TYPE1" "$TYPE2"
-	elif [ "$TYPE1" == "native int" ] && [ "$TYPE2" == "int32" ]; then
+	elif [ "$TYPE1" = "native int" ] && [ "$TYPE2" = "int32" ]; then
 		./make_stack_merge_test.sh stack_merge_${I} valid "$TYPE1" "$TYPE2"
-	elif [ "$TYPE1" == "int32&" ] && [ "$TYPE2" == "native int&" ]; then
+	elif [ "$TYPE1" = "int32&" ] && [ "$TYPE2" = "native int&" ]; then
 		./make_stack_merge_test.sh stack_merge_${I} valid "$TYPE1" "$TYPE2"
-	elif [ "$TYPE1" == "native int&" ] && [ "$TYPE2" == "int32&" ]; then
+	elif [ "$TYPE1" = "native int&" ] && [ "$TYPE2" = "int32&" ]; then
 		./make_stack_merge_test.sh stack_merge_${I} valid "$TYPE1" "$TYPE2"
 	else
 		./make_stack_merge_test.sh stack_merge_${I} unverifiable "$TYPE1" "$TYPE2"
@@ -1335,7 +1335,7 @@ do
 	MAX_PARAM_RESULT="unverifiable"
 	POPS="pop\npop\npop\npop\npop\npop\npop\npop\n"
 	
-	if [ "$OP" == "ldloc" ]; then
+	if [ "$OP" = "ldloc" ]; then
 		MAX_PARAM_RESULT="invalid"
 
 		LOCALS_1=$ARGS_1
@@ -1892,7 +1892,7 @@ function create_nesting_test_same_result
       do
         for LOAD in yes no
         do
-          if ! ( [ "$NESTED" == "no" ] && [ "$LOAD" == "yes" ] ) ; then
+          if ! ( [ "$NESTED" = "no" ] && [ "$LOAD" = "yes" ] ) ; then
             ./make_double_nesting_test.sh double_nesting_access_check_${K}_$I $2 "$OP" $3 $4 $5 "$BASE" "$NESTED" "$LOAD"
             K=`expr $K + 1`
           fi
@@ -1910,9 +1910,9 @@ function create_nesting_test_only_first_
       do
         for LOAD in yes no
         do
-          if ! ( [ "$NESTED" == "no" ] && [ "$LOAD" == "yes" ] ) ; then
+          if ! ( [ "$NESTED" = "no" ] && [ "$LOAD" = "yes" ] ) ; then
 	       EXPECT=unverifiable
-           if [ "$FIRST" == "$K" ]; then
+           if [ "$FIRST" = "$K" ]; then
               EXPECT=valid
            fi
            ./make_double_nesting_test.sh double_nesting_access_check_${K}_$I $EXPECT "$OP" $2 $3 $4 "$BASE" "$NESTED" "$LOAD"
@@ -2065,7 +2065,7 @@ function create_nesting_test_strips_resu
     for NESTED in yes no
       do
         EXPECT=unverifiable
-        if [ "$NESTED" == "yes" ]; then
+        if [ "$NESTED" = "yes" ]; then
           EXPECT=valid
         fi
         ./make_double_nesting_test.sh double_nesting_access_check_${K}_$I $EXPECT "$OP" $2 $3 $4 "$BASE" "$NESTED" yes
@@ -2188,9 +2188,9 @@ function fix_ldobj () {
 		A=$1;
 	fi
 
-	if [ "$A" == "bool" ]; then
+	if [ "$A" = "bool" ]; then
 		A="int8";
-	elif [ "$A" == "char" ]; then
+	elif [ "$A" = "char" ]; then
 		A="int16";
 	fi
 
@@ -2207,7 +2207,7 @@ do
 	do
 		TYPE1="$(fix_ldobj $T1)"
 		TYPE2="$(fix_ldobj $T2)"
-		if [ "$TYPE1" == "$TYPE2" ] ; then
+		if [ "$TYPE1" = "$TYPE2" ] ; then
 			./make_ldobj_test.sh ldobj_${I} valid "${T1}\&" "${T2}"
 		else
 			./make_ldobj_test.sh ldobj_${I} unverifiable "${T1}\&" "${T2}"
@@ -2564,7 +2564,7 @@ I=1
 for TYPE1 in "int8" "bool" "int16" "char" "int32" "int64" "float64" "native int" "object" "string" "class Class" "valuetype MyStruct"  "int32[]" "int32[,]" "int32*" "method int32 *(int32)"  "class Template\`1<object>"
 do
 	./make_store_indirect_test.sh indirect_store_bad_addr_r4_${I} unverifiable "stind.r4" "${TYPE1}\&" "float32"
-	if [ "$TYPE1" == "float64" ]; then
+	if [ "$TYPE1" = "float64" ]; then
 		./make_store_indirect_test.sh indirect_store_good_val_r4_${I} valid "stind.r4" "float32\&" "${TYPE1}"
 	else
 		./make_store_indirect_test.sh indirect_store_bad_val_r4_${I} unverifiable "stind.r4" "float32\&" "${TYPE1}"
@@ -2577,7 +2577,7 @@ I=1
 for TYPE1 in "int8" "bool" "int16" "char" "int32" "int64" "float32" "native int" "object" "string" "class Class" "valuetype MyStruct"  "int32[]" "int32[,]" "int32*" "method int32 *(int32)"  "class Template\`1<object>"
 do
 	./make_store_indirect_test.sh indirect_store_bad_addr_r8_${I} unverifiable "stind.r8" "${TYPE1}\&" "float64"
-	if [ "$TYPE1" == "float32" ]; then
+	if [ "$TYPE1" = "float32" ]; then
 		./make_store_indirect_test.sh indirect_store_good_val_r8_${I} valid "stind.r8" "float64\&" "${TYPE1}";
 	else
 		./make_store_indirect_test.sh indirect_store_bad_val_r8_${I} unverifiable "stind.r8" "float64\&" "${TYPE1}";
@@ -3326,7 +3326,7 @@ done
 
 #branching to a protected block from the outside
 for I in {2..6}; do
-	if [ "$I" == "4" ]; then
+	if [ "$I" = "4" ]; then
 		./make_branch_test.sh branch_inside_protected_block_from_outside_${I}_finally invalid 1 "br BLOCK_${I}" "finally";
 		./make_branch_test.sh branch_inside_protected_block_from_outside_${I}_fault invalid 1 "br BLOCK_${I}" "fault";
 	else
@@ -3362,7 +3362,7 @@ done
 
 #branching to a protected block from the outside
 for I in {2..6}; do
-	if [ "$I" == "4" ]; then
+	if [ "$I" = "4" ]; then
 		./make_switch_test.sh switch_inside_protected_block_from_outside_${I}_finally invalid 1 "ldloc.0" "switch (BLOCK_${I}, BLOCK_${I}_B)" "finally";
 		./make_switch_test.sh switch_inside_protected_block_from_outside_${I}_fault invalid 1 "ldloc.0" "switch (BLOCK_${I}, BLOCK_${I}_B)" "fault";
 	else
@@ -5148,5 +5148,3 @@ done
 
 ./make_generic_argument_constraints_test.sh type_mixed_3 valid "" "(IfaceA)"
 ./make_generic_argument_constraints_test.sh type_mixed_4 valid "" "class (IfaceA)"
-
-
