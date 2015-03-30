$NetBSD: patch-browser_components_loop_run-all-loop-tests.sh,v 1.1 2015/03/30 08:09:10 thomasklausner Exp $

Fix unportable test(1) operator.

--- browser/components/loop/run-all-loop-tests.sh.orig	2015-03-27 05:10:09.000000000 +0000
+++ browser/components/loop/run-all-loop-tests.sh
@@ -1,7 +1,7 @@
 #!/bin/sh
 # Run from topsrcdir, no args
 
-if [ "$1" == "--help" ]; then
+if [ "$1" = "--help" ]; then
   echo "Usage: ./run-all-loop-tests.sh [options]"
   echo "    --skip-e10s  Skips the e10s tests"
   exit 0;
