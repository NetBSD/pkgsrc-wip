$NetBSD$

--- opcodes/cgen.sh.orig	2019-07-16 00:00:27.000000000 +0000
+++ opcodes/cgen.sh
@@ -61,6 +61,7 @@ shift ; options=$9
 shift ; extrafiles=$9
 
 rootdir=${srcdir}/..
+move_if_change="${CONFIG_SHELL:-/bin/sh} ${rootdir}/move-if-change"
 
 # $arch is $6, as passed on the command line.
 # $ARCH is the same argument but in all uppercase.
