$NetBSD: patch-configure.py,v 1.3 2015/09/16 02:36:53 outpaddling Exp $

--- configure.py.orig	2015-08-12 17:41:23.000000000 +0000
+++ configure.py
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#!/usr/bin/env python2.7
 """Configure the build.
 
 - Fetch HDF5 headers.
@@ -93,7 +93,7 @@ nohdf         ?=1
 """%(dict(thisdir=thisdir))
 
 def get_OS_STRING():
-    G_BUILDOS_CMD = """bash -c 'set -e; set -o pipefail; id=$(lsb_release -si | tr "[:upper:]" "[:lower:]"); rel=$(lsb_release -sr); case $id in ubuntu) printf "$id-%04d\n" ${rel/./};; centos) echo "$id-${rel%%.*}";; *) echo "$id-$rel";; esac' 2>/dev/null"""
+    G_BUILDOS_CMD = """printf `uname`-`uname -r | cut -d - -f 1`'\n'"""
     return shell(G_BUILDOS_CMD)
 
 def get_PBBAM(env, prefix):
