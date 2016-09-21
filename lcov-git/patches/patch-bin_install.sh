$NetBSD$

Get rid of Bash
Try to use install(1) in a more portable way

--- bin/install.sh.orig	2016-09-14 18:39:15.000000000 +0000
+++ bin/install.sh
@@ -1,11 +1,11 @@
-#!/bin/bash
+#!/bin/sh
 #
 # install.sh [--uninstall] sourcefile targetfile [install options]
 #
 
 
 # Check for uninstall option
-if test "x$1" == "x--uninstall" ; then
+if test "x$1" = "x--uninstall" ; then
   UNINSTALL=true
   SOURCE=$2
   TARGET=$3
@@ -30,11 +30,12 @@ fi
 
 do_install()
 {
-  local SOURCE=$1
-  local TARGET=$2
-  local PARAMS=$3
+  local SOURCE="$1"
+  local TARGET="$2"
+  local PARAMS="$3"
 
-  install -p -D $PARAMS $SOURCE $TARGET
+  install -d "${TARGET%/*}"
+  install -p $PARAMS "$SOURCE" "$TARGET"
 }
 
 
@@ -44,8 +45,8 @@ do_install()
 
 do_uninstall()
 {
-  local SOURCE=$1
-  local TARGET=$2
+  local SOURCE="$1"
+  local TARGET="$2"
 
   # Does target exist?
   if test -r $TARGET ; then
