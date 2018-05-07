$NetBSD$

Fix the shebang.
Refactor the wrapping code.

--- idalink/support/ida_env.sh.orig	2015-04-28 07:05:43.000000000 +0000
+++ idalink/support/ida_env.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 # Copyright (C) 2013- Yan Shoshitaishvili aka. zardus
 #
@@ -16,8 +16,4 @@
 # along with this program; if not, write to the Free Software Foundation,
 # Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 
-export TERM=xterm
-
-IDA=$1
-shift
-$IDA "$@"
+TERM=xterm "$@"
