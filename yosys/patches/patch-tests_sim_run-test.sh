$NetBSD$

Avoid a Linux specific invocation of basename.

--- tests/sim/run-test.sh
+++ tests/sim/run-test.sh
@@ -3,7 +3,7 @@ set -eu
 source ../gen-tests-makefile.sh
 echo "Generate FST for sim models"
 find tb/* -name tb*.v | while read name; do
-    test_name=$(basename -s .v $name)
+    test_name=$(basename $name .v)
     echo "Test $test_name"
     verilog_name=${test_name:3}.v
     iverilog -o tb/$test_name.out $name $verilog_name
