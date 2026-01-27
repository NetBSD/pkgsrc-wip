$NetBSD$

Remediate bash ==.

Reported upstream by email 20260124 (or 25).

--- tests/nut-driver-enumerator-test.sh.orig	2026-01-27 00:24:21.471437853 +0000
+++ tests/nut-driver-enumerator-test.sh
@@ -614,7 +614,7 @@ testcase_semver_compare() {
 
     run_testcase_generic callSEMVERCMP \
         "SEMVER comparison helper: shell-style maths: (non-)equality with added trailing zero value e.g. 3 vs 30" 1 "" \
-        test 01.02.03 == 1.002.00030
+        test 01.02.03 = 1.002.00030
 
     run_testcase_generic callSEMVERCMP \
         "SEMVER comparison helper: shell-style maths: non-equality with added trailing zeroed components (and different leading zero pads)" 1 "" \
