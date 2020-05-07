$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/system.d.orig	2020-05-07 08:52:19.304672455 +0000
+++ runtime/phobos/std/system.d
@@ -35,6 +35,7 @@ immutable
         osx,          /// Mac OS X
         freeBSD,      /// FreeBSD
         dragonFlyBSD, /// DragonFlyBSD
+        netBSD,       /// NetBSD
         solaris,      /// Solaris
         android,      /// Android
         otherPosix    /// Other Posix Systems
@@ -48,6 +49,7 @@ immutable
     else version(OSX)     OS os = OS.osx;
     else version(FreeBSD) OS os = OS.freeBSD;
     else version(DragonFlyBSD) OS os = OS.dragonFlyBSD;
+    else version(NetBSD) OS os = OS.netBSD;
     else version(Posix)   OS os = OS.otherPosix;
     else static assert(0, "Unknown OS.");
 
