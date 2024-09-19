$NetBSD: patch-symux_c_smrrds.sh,v 1.1 2011/04/18 14:51:27 hfath Exp $

Allow for substitution of hardcoded paths

--- symux/c_smrrds.sh.orig	2010-05-31 13:38:06.000000000 +0000
+++ symux/c_smrrds.sh
@@ -70,7 +70,7 @@ find_exec() {
         done)
 }
 # find rrdtool
-RRDTOOL=`find_exec "$RRDTOOL" /usr/local/bin rrdtool`
+RRDTOOL=`find_exec "$RRDTOOL" @PKG_PREFIX@/bin rrdtool`
 if [ ! -x "$RRDTOOL" ]; then
     echo "Cannot find rrdtool - add it to \$PATH or \$RRDTOOL"
     exit 1;
@@ -144,7 +144,7 @@ j=`basename $i`
 case $j in
 
 all)
-    SYMUX=`find_exec "$SYMUX" /usr/libexec:/usr/local/libexec:/usr/local/bin:/usr/local/sbin symux`
+    SYMUX=`find_exec "$SYMUX" /usr/libexec:@PKG_PREFIX@/libexec:@PKG_PREFIX@/bin:@PKG_PREFIX@/sbin symux`
     if [ ! -x "$SYMUX" ]; then
         echo "Cannot find symux - add it to \$PATH or \$SYMUX"
         exit 1;
