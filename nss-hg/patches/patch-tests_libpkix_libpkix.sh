$NetBSD: patch-tests_libpkix_libpkix.sh,v 1.2 2014/10/05 20:12:38 thomasklausner Exp $

Posix compatibility - avoid bash specific == operator

--- tests/libpkix/libpkix.sh.orig	2014-09-28 13:54:02.000000000 +0000
+++ tests/libpkix/libpkix.sh
@@ -52,12 +52,12 @@ libpkix_cleanup()
 ParseArgs ()
 {
     while [ $# -gt 0 ]; do
-        if [ $1 == "-checkmem" ]; then
+        if [ $1 = "-checkmem" ]; then
             checkMemArg=$1
             memText="   (Memory Checking Enabled)"
-        elif [ $1 == "-quiet" ]; then
+        elif [ $1 = "-quiet" ]; then
             quietArg=$1
-        elif [ $1 == "-arenas" ]; then
+        elif [ $1 = "-arenas" ]; then
             arenasArg=$1
         fi
         shift
