$NetBSD: patch-benchmarks_gabriel_run.sh,v 1.1 2015/07/13 02:29:29 leot1990 Exp $

test(1) does not support == for strings comparison, use = instead.

--- benchmarks/gabriel/run.sh.orig	2015-05-10 13:47:12.000000000 +0000
+++ benchmarks/gabriel/run.sh
@@ -1,7 +1,7 @@
 #!/bin/sh
 
 BENCHDIR=$(dirname $0)
-if [ "${BENCHDIR%%/*}" == "." ]; then
+if [ "${BENCHDIR%%/*}" = "." ]; then
     BENCHDIR=$(pwd)${BENCHDIR#.}
 fi
 CHIBIHOME=${BENCHDIR%%/benchmarks/gabriel}
