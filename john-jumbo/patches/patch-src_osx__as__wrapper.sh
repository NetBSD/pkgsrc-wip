$NetBSD$

--- src/osx_as_wrapper.sh.orig	2014-05-16 13:40:40.000000000 +0000
+++ src/osx_as_wrapper.sh
@@ -4,14 +4,14 @@ ARGS=$@
 while [ $# -ne 0 ]; do
         ARG=$1
         # Skip options
-        if [ $ARG == "-arch" ] || [ $ARG == "-o" ]; then
+        if [ $ARG = "-arch" ] || [ $ARG = "-o" ]; then
                 # Skip next token
                 shift
                 shift
                 continue
         fi
 
-        if [ `echo $ARG | head -c1` == "-" ]; then
+        if [ `echo $ARG | head -c1` = "-" ]; then
                 shift
                 continue
         fi
