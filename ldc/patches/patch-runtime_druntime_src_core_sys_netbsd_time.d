$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/netbsd/time.d.orig	2016-03-02 01:38:47.251518739 +0000
+++ runtime/druntime/src/core/sys/netbsd/time.d
@@ -0,0 +1,19 @@
+//Written in the D programming language
+
+/++
+    D header file for NetBSD's extensions to POSIX's time.h.
+
+    Copyright: Copyright 2014
+    License:   $(WEB www.boost.org/LICENSE_1_0.txt, Boost License 1.0).
+    Authors:   Jonathan M Davis
+ +/
+module core.sys.netbsd.time;
+
+public import core.sys.posix.time;
+
+version(NetBSD):
+
+enum CLOCK_REALTIME          = 0;
+enum CLOCK_VIRTUAL           = 1;
+enum CLOCK_PROF              = 2;
+enum CLOCK_MONOTONIC         = 3;
