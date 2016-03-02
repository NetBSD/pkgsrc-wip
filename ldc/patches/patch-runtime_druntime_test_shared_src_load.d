$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/test/shared/src/load.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/test/shared/src/load.d
@@ -2,6 +2,7 @@ import core.runtime, core.stdc.stdio, co
 
 version (linux) import core.sys.linux.dlfcn;
 else version (FreeBSD) import core.sys.freebsd.dlfcn;
+else version (NetBSD) import core.sys.netbsd.dlfcn;
 else static assert(0, "unimplemented");
 
 void loadSym(T)(void* handle, ref T val, const char* mangle)
