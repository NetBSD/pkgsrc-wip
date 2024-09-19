$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/rt/sections_ldc.d.orig	2020-05-07 08:52:18.254675459 +0000
+++ runtime/druntime/src/rt/sections_ldc.d
@@ -19,6 +19,7 @@ module rt.sections_ldc;
 version (linux) {}
 else version (FreeBSD) {}
 else version (DragonFlyBSD) {}
+else version (NetBSD) {}
 else version(LDC):
 
 import core.stdc.stdlib : alloca;
