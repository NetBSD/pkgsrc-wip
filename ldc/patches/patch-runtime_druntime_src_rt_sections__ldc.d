$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/rt/sections_ldc.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/rt/sections_ldc.d
@@ -16,7 +16,7 @@
 
 module rt.sections_ldc;
 
-version (linux) {} else version (FreeBSD) {} else version(LDC):
+version (linux) {} else version (FreeBSD) {}else version (NetBSD) {} else version(LDC):
 
 import core.stdc.stdlib : alloca;
 import rt.minfo;
@@ -387,7 +387,6 @@ void initSections()
     {
         dl_phdr_info phdr = void;
         findPhdrForAddr(&globalSectionGroup, &phdr) || assert(0);
-
         scanSegments(phdr, &globalSectionGroup);
     }
 }
