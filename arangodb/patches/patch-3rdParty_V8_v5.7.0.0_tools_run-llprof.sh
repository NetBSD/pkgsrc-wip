$NetBSD$

--- 3rdParty/V8/v5.7.0.0/tools/run-llprof.sh.orig	2017-08-23 15:57:40.000000000 +0000
+++ 3rdParty/V8/v5.7.0.0/tools/run-llprof.sh
@@ -46,7 +46,7 @@ framework, then calls the low level tick
 EOF
 }
 
-if [ $# -eq 0 ] || [ "$1" == "-h" ]  || [ "$1" == "--help" ] ; then
+if [ $# -eq 0 ] || [ "$1" = "-h" ]  || [ "$1" = "--help" ] ; then
   usage
   exit 1
 fi
