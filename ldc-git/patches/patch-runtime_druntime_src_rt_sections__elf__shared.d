$NetBSD$

--- runtime/druntime/src/rt/sections_elf_shared.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/rt/sections_elf_shared.d
@@ -12,6 +12,7 @@ module rt.sections_elf_shared;
 
 version (CRuntime_Glibc) enum SharedELF = true;
 else version (FreeBSD) enum SharedELF = true;
+else version (NetBSD) enum SharedELF = true;
 else enum SharedELF = false;
 static if (SharedELF):
 
@@ -32,6 +33,12 @@ else version (FreeBSD)
     import core.sys.freebsd.sys.elf;
     import core.sys.freebsd.sys.link_elf;
 }
+else version (NetBSD)
+{
+    import core.sys.netbsd.dlfcn;
+    import core.sys.netbsd.sys.elf;
+    import core.sys.netbsd.sys.link_elf;
+}
 else
 {
     static assert(0, "unimplemented");
