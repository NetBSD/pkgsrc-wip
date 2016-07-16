$NetBSD$

Do not use /bin/echo, on e.g. SunOS it does not support -n.

--- src/rust-installer/gen-install-script.sh.orig	2016-05-31 21:13:01.000000000 +0000
+++ src/rust-installer/gen-install-script.sh
@@ -1,4 +1,4 @@
-#!/bin/sh
+#!/usr/pkg/bin/bash
 # Copyright 2014 The Rust Project Developers. See the COPYRIGHT
 # file at the top-level directory of this distribution and at
 # http://rust-lang.org/COPYRIGHT.
@@ -11,7 +11,7 @@
 
 set -u
 
-if [ -x /bin/echo ]; then
+if [ -x /bin/donotuseecho ]; then
     ECHO='/bin/echo'
 else
     ECHO='echo'
