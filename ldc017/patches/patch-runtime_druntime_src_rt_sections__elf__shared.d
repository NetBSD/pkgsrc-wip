$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/rt/sections_elf_shared.d.orig	2020-05-07 08:52:18.174675688 +0000
+++ runtime/druntime/src/rt/sections_elf_shared.d
@@ -13,6 +13,7 @@ module rt.sections_elf_shared;
 version (CRuntime_Glibc) enum SharedELF = true;
 else version (FreeBSD) enum SharedELF = true;
 else version (DragonFlyBSD) enum SharedELF = true;
+else version (NetBSD) enum SharedELF = true;
 else enum SharedELF = false;
 static if (SharedELF):
 
@@ -39,6 +40,12 @@ else version (DragonFlyBSD)
     import core.sys.dragonflybsd.sys.elf;
     import core.sys.dragonflybsd.sys.link_elf;
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
@@ -123,6 +130,7 @@ __gshared bool _isRuntimeInitialized;
 
 version (FreeBSD) private __gshared void* dummy_ref;
 version (DragonFlyBSD) private __gshared void* dummy_ref;
+version (NetBSD) private __gshared void* dummy_ref;
 
 /****
  * Gets called on program startup just before GC is initialized.
@@ -253,6 +261,7 @@ private:
 // start of linked list for ModuleInfo references
 version (FreeBSD) deprecated extern (C) __gshared void* _Dmodule_ref;
 version (DragonFlyBSD) deprecated extern (C) __gshared void* _Dmodule_ref;
+version (NetBSD) deprecated extern (C) __gshared void* _Dmodule_ref;
 
 version (Shared)
 {
@@ -661,6 +670,8 @@ nothrow:
                     strtab = cast(const(char)*)(info.dlpi_addr + dyn.d_un.d_ptr); // relocate
                 else version (DragonFlyBSD)
                     strtab = cast(const(char)*)(info.dlpi_addr + dyn.d_un.d_ptr); // relocate
+                else version (NetBSD)
+                    strtab = cast(const(char)*)(info.dlpi_addr + dyn.d_un.d_ptr); // relocate
                 else
                     static assert(0, "unimplemented");
                 break;
@@ -814,12 +825,14 @@ version (linux) import core.sys.linux.er
 // should be in core.sys.freebsd.stdlib
 version (FreeBSD) extern(C) const(char)* getprogname() nothrow @nogc;
 version (DragonFlyBSD) extern(C) const(char)* getprogname() nothrow @nogc;
+version (NetBSD) extern(C) const(char)* getprogname() nothrow @nogc;
 
 @property const(char)* progname() nothrow @nogc
 {
     version (linux) return program_invocation_name;
     version (FreeBSD) return getprogname();
     version (DragonFlyBSD) return getprogname();
+    version (NetBSD) return getprogname();
 }
 
 nothrow
