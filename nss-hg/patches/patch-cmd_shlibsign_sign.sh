$NetBSD: patch-cmd_shlibsign_sign.sh,v 1.2 2014/10/05 20:12:38 thomasklausner Exp $

Add ${PREFIX}/lib to search path (pkgsrc specific)

--- cmd/shlibsign/sign.sh.orig	2014-09-28 13:54:02.000000000 +0000
+++ cmd/shlibsign/sign.sh
@@ -37,7 +37,7 @@ WIN*)
     export LIBPATH
     SHLIB_PATH=${1}/lib:${4}:$SHLIB_PATH
     export SHLIB_PATH
-    LD_LIBRARY_PATH=${1}/lib:${4}:$LD_LIBRARY_PATH
+    LD_LIBRARY_PATH=${1}/lib:${4}:${PREFIX}/lib:$LD_LIBRARY_PATH
     export LD_LIBRARY_PATH
     DYLD_LIBRARY_PATH=${1}/lib:${4}:$DYLD_LIBRARY_PATH
     export DYLD_LIBRARY_PATH
