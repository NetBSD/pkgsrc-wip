$NetBSD$

Portability fixes: use "=" instead of "==" for test(1).

--- testscripts/test_make.sh.orig	2021-05-09 08:48:44.000000000 +0000
+++ testscripts/test_make.sh
@@ -8,13 +8,13 @@ CHARSET=$1
 shift
 
 skiprun="NO"
-if [ $1 == "-norun" ]; then
+if [ $1 = "-norun" ]; then
     skiprun="YES"
     shift
 fi
 
 tstscript=""
-if [ $1 == "-script" ]; then
+if [ $1 = "-script" ]; then
     tstscript="YES"
     shift
 fi
@@ -42,9 +42,9 @@ case "$1" in
 esac
 cat "$T3_OUT/$1.err" >> "$T3_OUT/$1.log"
 
-if [ $skiprun == "NO" ]; then
+if [ $skiprun = "NO" ]; then
     echo "'Make' test: $1"
-    if [ $tstscript == "YES" ]; then
+    if [ $tstscript = "YES" ]; then
         $TESTPROGS/test_exec -I "$T3_DAT/$1.in" -cs $CHARSET -norand "$T3_OUT/$1.t3" >> "$T3_OUT/$1.log" 2>"$T3_OUT/$1.err"
     else
         $TESTPROGS/test_exec -cs $CHARSET -norand "$T3_OUT/$1.t3" >> "$T3_OUT/$1.log" 2>"$T3_OUT/$1.err"
