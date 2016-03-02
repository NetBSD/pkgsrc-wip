$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/complex.d.orig	2016-02-13 20:04:46.000000000 +0000
+++ runtime/phobos/std/complex.d
@@ -758,8 +758,9 @@ Complex!T sin(T)(Complex!T z)  @safe pur
 
 unittest
 {
+  import std.math: feqrel;
   assert(sin(complex(0.0)) == 0.0);
-  assert(sin(complex(2.0L, 0)) == std.math.sin(2.0L));
+  assert(feqrel(sin(complex(2.0L, 0)).re, std.math.sin(2.0L)) > real.mant_dig-10);
 }
 
 
@@ -776,7 +777,7 @@ unittest{
     import std.math;
     import std.complex;
     assert(cos(complex(0.0)) == 1.0);
-    assert(cos(complex(1.3L)) == std.math.cos(1.3L));
+    assert(feqrel(cos(complex(1.3L)).re, std.math.cos(1.3L)) >= real.mant_dig-12);
     assert(cos(complex(0, 5.2L)) == cosh(5.2L));
 }
 
@@ -801,7 +802,8 @@ unittest
     assert(expi(0.0L) == 1.0L);
     auto z1 = expi(1.234);
     auto z2 = std.math.expi(1.234);
-    assert(z1.re == z2.re && z1.im == z2.im);
+    import std.math : approxEqual;
+    assert(approxEqual(z1.re, z2.re) && approxEqual(z1.im, z2.im));
 }
 
 
