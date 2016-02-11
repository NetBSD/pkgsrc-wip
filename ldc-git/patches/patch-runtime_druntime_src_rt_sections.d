$NetBSD$

--- runtime/druntime/src/rt/sections.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/rt/sections.d
@@ -16,6 +16,8 @@ version (CRuntime_Glibc)
     public import rt.sections_elf_shared;
 else version (FreeBSD)
     public import rt.sections_elf_shared;
+else version (NetBSD)
+    public import rt.sections_elf_shared;
 else version (Solaris)
     public import rt.sections_solaris;
 else version (OSX)
