$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/gc/os.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/gc/os.d
@@ -31,6 +31,7 @@ else version (Posix)
 {
     import core.sys.posix.sys.mman;
     version (FreeBSD) import core.sys.freebsd.sys.mman : MAP_ANON;
+    version (NetBSD) import core.sys.netbsd.sys.mman : MAP_ANON;
     version (CRuntime_Glibc) import core.sys.linux.sys.mman : MAP_ANON;
     version (OSX) import core.sys.osx.sys.mman : MAP_ANON;
     import core.stdc.stdlib;
