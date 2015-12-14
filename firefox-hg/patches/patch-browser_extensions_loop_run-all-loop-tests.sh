$NetBSD$

--- browser/extensions/loop/run-all-loop-tests.sh.orig	2015-12-14 14:47:20.000000000 +0000
+++ browser/extensions/loop/run-all-loop-tests.sh
@@ -1,7 +1,7 @@
 #!/bin/sh
 # Run from topsrcdir, no args
 
-if [ "$1" == "--help" ]; then
+if [ "$1" = "--help" ]; then
   echo "Usage: ./run-all-loop-tests.sh [options]"
   echo "    --skip-e10s  Skips the e10s tests"
   exit 0;
