$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/rt/sections.d.orig	2020-05-07 08:52:18.074675974 +0000
+++ runtime/druntime/src/rt/sections.d
@@ -18,6 +18,8 @@ else version (FreeBSD)
     public import rt.sections_elf_shared;
 else version (DragonFlyBSD)
     public import rt.sections_elf_shared;
+else version (NetBSD)
+    public import rt.sections_elf_shared;
 else version (Solaris)
     public import rt.sections_solaris;
 else version (OSX)
