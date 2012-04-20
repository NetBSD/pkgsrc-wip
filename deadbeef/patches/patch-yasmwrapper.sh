$NetBSD: patch-yasmwrapper.sh,v 1.1.1.1 2012/04/20 14:50:11 roelants Exp $
Don't use bash as interpreter.
--- yasmwrapper.sh.orig	2011-12-11 15:34:58.000000000 +0000
+++ yasmwrapper.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 ARGS=""
 for i in $@ ; do
     #if [ "$i" != "-fPIC" ] && [ "$i" != "-DPIC" ]; then
