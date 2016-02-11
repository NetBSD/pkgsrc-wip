$NetBSD$

--- runtime/druntime/src/core/time.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/time.d
@@ -304,6 +304,11 @@ else version(FreeBSD) enum ClockType
     uptimeCoarse = 9,
     uptimePrecise = 10,
 }
+else version(NetBSD) enum ClockType
+{
+     normal,
+     processCPUTime = 4,
+} 
 else version(Solaris) enum ClockType
 {
     normal = 0,
@@ -359,6 +364,22 @@ version(Posix)
             case second: assert(0);
             }
         }
+	else version(NetBSD)
+	{
+	    enum
+	    {
+	        CLOCK_REALTIME,
+	        CLOCK_VIRTUAL,
+                CLOCK_PROF,
+                CLOCK_MONOTONIC,
+	    }
+
+	    with(ClockType) final switch(clockType)
+	    {
+            case normal: return CLOCK_MONOTONIC; // Should it be CLOCK_REALTIME?
+            case processCPUTime: return CLOCK_PROF; // Should it be CLOCK_VIRTUAL?
+            }
+	}
         else version(Solaris)
         {
             import core.sys.solaris.time;
