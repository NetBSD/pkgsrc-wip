$NetBSD: patch-test_unittests_all__tests.sh,v 1.1 2012/11/16 11:13:17 slitvinov Exp $

# hardcoded a python version number
--- test/unittests/all_tests.sh.orig	2011-10-11 20:35:01.000000000 +0000
+++ test/unittests/all_tests.sh
@@ -1,5 +1,5 @@
 #/bin/bash
-COVERAGE=coverage
+COVERAGE=coverage2.7
 $COVERAGE -e
 
 for file in test_*.py; do
