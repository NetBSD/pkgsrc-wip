$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/gc/os.d.orig	2020-05-07 08:52:17.834676660 +0000
+++ runtime/druntime/src/gc/os.d
@@ -32,6 +32,7 @@ else version (Posix)
     import core.sys.posix.sys.mman;
     version (FreeBSD) import core.sys.freebsd.sys.mman : MAP_ANON;
     version (DragonFlyBSD) import core.sys.dragonflybsd.sys.mman : MAP_ANON;
+    version (NetBSD) import core.sys.netbsd.sys.mman : MAP_ANON;    
     version (CRuntime_Glibc) import core.sys.linux.sys.mman : MAP_ANON;
     version (OSX) import core.sys.osx.sys.mman : MAP_ANON;
     import core.stdc.stdlib;
