$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/numeric.d.orig	2016-02-13 20:04:46.000000000 +0000
+++ runtime/phobos/std/numeric.d
@@ -1687,7 +1687,8 @@ unittest
     assert(sumOfLog2s(new double[0]) == 0);
     assert(sumOfLog2s([0.0L]) == -real.infinity);
     assert(sumOfLog2s([-0.0L]) == -real.infinity);
-    assert(sumOfLog2s([2.0L]) == 1);
+    import std.math;
+    assert(approxEqual(sumOfLog2s([2.0L]), 1));
     assert(sumOfLog2s([-2.0L]).isNaN());
     assert(sumOfLog2s([real.nan]).isNaN());
     assert(sumOfLog2s([-real.nan]).isNaN());
