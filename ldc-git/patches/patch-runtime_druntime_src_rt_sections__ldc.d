$NetBSD$

--- runtime/druntime/src/rt/sections_ldc.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/rt/sections_ldc.d
@@ -16,7 +16,7 @@
 
 module rt.sections_ldc;
 
-version (linux) {} else version (FreeBSD) {} else version(LDC):
+version (linux) {} else version (FreeBSD) {} else version (NetBSD) {} else version(LDC):
 
 import core.stdc.stdlib : alloca;
 import rt.minfo;
