$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/time.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/time.d
@@ -304,6 +304,13 @@ else version(FreeBSD) enum ClockType
     uptimeCoarse = 9,
     uptimePrecise = 10,
 }
+else version(NetBSD) enum ClockType
+{
+    normal = 0,
+    coarse = 2,
+    precise = 3,
+    second = 6,
+}
 else version(Solaris) enum ClockType
 {
     normal = 0,
@@ -359,6 +366,17 @@ version(Posix)
             case second: assert(0);
             }
         }
+        else version(NetBSD)
+        {
+            import core.sys.netbsd.time;
+            with(ClockType) final switch(clockType)
+            {
+            case coarse: return CLOCK_MONOTONIC;
+            case normal: return CLOCK_MONOTONIC;
+            case precise: return CLOCK_MONOTONIC;
+            case second: assert(0);
+            }
+        }
         else version(Solaris)
         {
             import core.sys.solaris.time;
