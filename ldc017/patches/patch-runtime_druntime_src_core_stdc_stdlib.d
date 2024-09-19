$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/stdc/stdlib.d.orig	2020-05-07 08:52:13.934687779 +0000
+++ runtime/druntime/src/core/stdc/stdlib.d
@@ -67,6 +67,7 @@ else version(CRuntime_Glibc)  enum RAND_
 else version(OSX)     enum RAND_MAX = 0x7fffffff;
 else version(FreeBSD) enum RAND_MAX = 0x7fffffff;
 else version(DragonFlyBSD) enum RAND_MAX = 0x7fffffff;
+else version(NetBSD)  enum RAND_MAX = 0x7fffffff;
 else version(Solaris) enum RAND_MAX = 0x7fff;
 else version(CRuntime_Bionic) enum RAND_MAX = 0x7fffffff;
 else static assert( false, "Unsupported platform" );
