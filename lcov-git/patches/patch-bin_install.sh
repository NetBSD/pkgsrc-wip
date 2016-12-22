$NetBSD$

Get rid of Bash
Try to use install(1) in a more portable way

--- bin/install.sh.orig	2016-12-21 08:18:41.000000000 +0000
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
@@ -30,9 +30,9 @@ fi
 
 do_install()
 {
-  local SOURCE=$1
-  local TARGET=$2
-  local PARAMS=$3
+  local SOURCE="$1"
+  local TARGET="$2"
+  local PARAMS="$3"
 
   install -d $(dirname $TARGET)
   install -p $PARAMS $SOURCE $TARGET
@@ -45,8 +45,8 @@ do_install()
 
 do_uninstall()
 {
-  local SOURCE=$1
-  local TARGET=$2
+  local SOURCE="$1"
+  local TARGET="$2"
 
   # Does target exist?
   if test -r $TARGET ; then
