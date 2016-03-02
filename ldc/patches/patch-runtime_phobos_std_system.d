$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/system.d.orig	2016-02-13 20:04:46.000000000 +0000
+++ runtime/phobos/std/system.d
@@ -34,6 +34,7 @@ immutable
         linux,     /// All Linux Systems
         osx,       /// Mac OS X
         freeBSD,   /// FreeBSD
+        netBSD,    /// NetBSD
         solaris,   /// Solaris
         android,   /// Android
         otherPosix /// Other Posix Systems
@@ -46,6 +47,7 @@ immutable
     else version(linux)   OS os = OS.linux;
     else version(OSX)     OS os = OS.osx;
     else version(FreeBSD) OS os = OS.freeBSD;
+    else version(NetBSD) OS os = OS.netBSD;
     else version(Posix)   OS os = OS.otherPosix;
     else static assert(0, "Unknown OS.");
 
