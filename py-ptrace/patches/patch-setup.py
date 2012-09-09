$NetBSD: patch-setup.py,v 1.1 2012/09/09 22:46:51 jihbed Exp $

--- setup.py.orig	2012-02-26 14:42:14.000000000 +0100
+++ setup.py	2012-09-09 23:36:16.000000000 +0100
@@ -20,10 +20,11 @@
 #  - add a new empty section in the changelog for version n+1
 
 from __future__ import with_statement
+import sys
 
 MODULES = ["ptrace", "ptrace.binding", "ptrace.syscall", "ptrace.debugger"]
 
-SCRIPTS = ("strace.py", "gdb.py")
+SCRIPTS = ("strace.py"+sys.version[0:3], "gdb.py"+sys.version[0:3])
 
 CLASSIFIERS = [
     'Intended Audience :: Developers',
