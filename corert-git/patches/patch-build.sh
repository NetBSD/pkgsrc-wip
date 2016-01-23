$NetBSD$

--- build.sh.orig	2016-01-23 16:33:43.000000000 +0000
+++ build.sh
@@ -1,4 +1,4 @@
-#!/usr/bin/env bash
+#!/usr/pkg/bin/bash
 
 usage()
 {
@@ -305,6 +305,12 @@ case $OSName in
         __TestNugetRuntimeId=osx.10.10-x64
         ;;
 
+    NetBSD)
+        __BuildOS=NetBSD
+        __ToolNugetRuntimeId=osx.10.10-x64
+        __TestNugetRuntimeId=osx.10.10-x64
+        ;;
+
     *)
         echo "Unsupported OS $OSName detected, configuring as if for Linux"
         __BuildOS=Linux
