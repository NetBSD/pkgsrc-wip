$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/rt/sections_elf_shared.d.orig	2016-02-13 20:02:16.000000000 +0000
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
@@ -115,6 +122,7 @@ __gshared bool _isRuntimeInitialized;
 
 
 version (FreeBSD) private __gshared void* dummy_ref;
+version (NetBSD) private __gshared void* dummy_ref;
 
 /****
  * Gets called on program startup just before GC is initialized.
@@ -124,6 +132,7 @@ void initSections()
     _isRuntimeInitialized = true;
     // reference symbol to support weak linkage
     version (FreeBSD) dummy_ref = &_d_dso_registry;
+    version (NetBSD) dummy_ref = &_d_dso_registry;
 }
 
 
@@ -243,6 +252,7 @@ private:
 
 // start of linked list for ModuleInfo references
 version (FreeBSD) deprecated extern (C) __gshared void* _Dmodule_ref;
+version (NetBSD) deprecated extern (C) __gshared void* _Dmodule_ref;
 
 version (Shared)
 {
@@ -649,6 +659,8 @@ nothrow:
                     strtab = cast(const(char)*)dyn.d_un.d_ptr;
                 else version (FreeBSD)
                     strtab = cast(const(char)*)(info.dlpi_addr + dyn.d_un.d_ptr); // relocate
+                else version (NetBSD)
+                    strtab = cast(const(char)*)(info.dlpi_addr + dyn.d_un.d_ptr); // relocate
                 else
                     static assert(0, "unimplemented");
                 break;
@@ -754,6 +766,24 @@ else version (FreeBSD) bool findDSOInfoF
 {
     return !!_rtld_addr_phdr(addr, result);
 }
+else version (NetBSD) bool findDSOInfoForAddr(in void* addr, dl_phdr_info* result=null) nothrow @nogc
+{
+    static struct DG { const(void)* addr; dl_phdr_info* result; }
+
+    extern(C) int callback(dl_phdr_info* info, size_t sz, void* arg) nothrow @nogc
+    {
+
+        auto p = cast(DG*)arg;
+        if (findSegmentForAddr(*info, p.addr))
+        {
+            if (p.result !is null) *p.result = *info;
+            return 1; // break;
+        }
+        return 0; // continue iteration
+    }
+    auto dg = DG(addr, result);
+    return dl_iterate_phdr(&callback, &dg) != 0;
+}
 
 /*********************************
  * Determine if 'addr' lies within shared object 'info'.
@@ -779,11 +809,13 @@ bool findSegmentForAddr(in ref dl_phdr_i
 version (linux) import core.sys.linux.errno : program_invocation_name;
 // should be in core.sys.freebsd.stdlib
 version (FreeBSD) extern(C) const(char)* getprogname() nothrow @nogc;
+version (NetBSD) extern(C) const(char)* getprogname() nothrow @nogc;
 
 @property const(char)* progname() nothrow @nogc
 {
     version (linux) return program_invocation_name;
     version (FreeBSD) return getprogname();
+    version (NetBSD) return getprogname();
 }
 
 nothrow
