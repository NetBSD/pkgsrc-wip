$NetBSD$

--- runtime/druntime/src/core/stdc/stdlib.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/stdc/stdlib.d
@@ -66,6 +66,7 @@ version(Windows)      enum RAND_MAX = 0x
 else version(CRuntime_Glibc)  enum RAND_MAX = 0x7fffffff;
 else version(OSX)     enum RAND_MAX = 0x7fffffff;
 else version(FreeBSD) enum RAND_MAX = 0x7fffffff;
+else version(NetBSD)  enum RAND_MAX = 0x7fffffff;
 else version(Solaris) enum RAND_MAX = 0x7fff;
 else version(CRuntime_Bionic) enum RAND_MAX = 0x7fffffff;
 else static assert( false, "Unsupported platform" );
