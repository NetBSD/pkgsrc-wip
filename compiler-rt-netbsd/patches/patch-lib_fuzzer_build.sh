$NetBSD$

--- lib/fuzzer/build.sh.orig	2017-08-19 18:02:19.281531111 +0000
+++ lib/fuzzer/build.sh
@@ -0,0 +1,11 @@
+#!/bin/bash
+LIBFUZZER_SRC_DIR=$(dirname $0)
+CXX="${CXX:-clang}"
+for f in $LIBFUZZER_SRC_DIR/*.cpp; do
+  $CXX -g -O2 -fno-omit-frame-pointer -std=c++11 $f -c &
+done
+wait
+rm -f libFuzzer.a
+ar ru libFuzzer.a Fuzzer*.o
+rm -f Fuzzer*.o
+
