$NetBSD$

bashism

--- modules/web/src/main/native/Tools/ReducedFTL/build.sh.orig	2016-03-03 23:18:49.000000000 +0000
+++ modules/web/src/main/native/Tools/ReducedFTL/build.sh
@@ -3,7 +3,7 @@
 set -e
 set -x
 
-if test "x${LLVM_PATH}" == "x"
+if test "x${LLVM_PATH}" = "x"
 then
     configPath="llvm-config"
 else
