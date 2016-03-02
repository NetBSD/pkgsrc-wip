$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/conv.d.orig	2016-02-13 20:04:46.000000000 +0000
+++ runtime/phobos/std/conv.d
@@ -2859,7 +2859,17 @@ unittest
 
     // min and max
     real r = to!real(to!string(real.min_normal));
-    assert(to!string(r) == to!string(real.min_normal));
+    version(NetBSD)
+    {
+        // NetBSD notice
+        // to!string returns 3.3621e-4932L. It is less than real.min_normal and it is subnormal value
+        // Simple C code
+        //     long double rd = 3.3621e-4932L;
+        //     printf("%Le\n", rd);
+        // has unexpected result: 1.681050e-4932
+    } else {
+        assert(to!string(r) == to!string(real.min_normal));
+    }
     r = to!real(to!string(real.max));
     assert(to!string(r) == to!string(real.max));
 }
