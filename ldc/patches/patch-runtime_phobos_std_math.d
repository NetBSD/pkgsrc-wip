$NetBSD$

Stolen from https://github.com/nrTQgc/phobos/tree/netbsd

--- runtime/phobos/std/math.d.orig	2018-08-23 23:30:04.000000000 +0000
+++ runtime/phobos/std/math.d
@@ -752,7 +752,8 @@ ireal sin(ireal y) @safe pure nothrow @n
 @safe pure nothrow @nogc unittest
 {
   assert(sin(0.0+0.0i) == 0.0);
-  assert(sin(2.0+0.0i) == sin(2.0L) );
+  assert(sin(2.0+0.0i).im == 0.0L );
+  assert(feqrel(sin(2.0+0.0i).re, sin(2.0L)) >  real.mant_dig-10 );
 }
 
 /***********************************
@@ -777,7 +778,8 @@ real cos(ireal y) @safe pure nothrow @no
 @safe pure nothrow @nogc unittest
 {
     assert(cos(0.0+0.0i)==1.0);
-    assert(cos(1.3L+0.0i)==cos(1.3L));
+    assert(cos(1.3L+0.0i).im == 0.0L );
+    assert(feqrel(cos(1.3L+0.0i).re, cos(1.3L)) >= real.mant_dig-12 );
     assert(cos(5.2Li)== cosh(5.2L));
 }
 
@@ -1032,7 +1034,7 @@ Lret: {}
 
 unittest
 {
-    assert(equalsDigit(tan(PI / 3), std.math.sqrt(3.0), useDigits));
+    assert(feqrel(tan(PI / 3), std.math.sqrt(3.0)) > real.mant_dig-15 );
 }
 
 /***************
@@ -2579,7 +2581,8 @@ creal expi(real y) @trusted pure nothrow
 ///
 @safe pure nothrow @nogc unittest
 {
-    assert(expi(1.3e5L) == cos(1.3e5L) + sin(1.3e5L) * 1i);
+    assert(feqrel(expi(1.3e5L).re, (cos(1.3e5L) + sin(1.3e5L) * 1i).re)> real.mant_dig-15);
+    assert(feqrel(expi(1.3e5L).im, (cos(1.3e5L) + sin(1.3e5L) * 1i).im)> real.mant_dig-15);
     assert(expi(0.0L) == 1L + 0.0Li);
 }
 
@@ -3694,8 +3697,8 @@ real log2(real x) @safe pure nothrow @no
 ///
 unittest
 {
-    // check if values are equal to 19 decimal digits of precision
-    assert(equalsDigit(log2(1024.0L), 10, 19));
+    // check if values are equal except last 10 mantis bits
+    assert(feqrel(log2(1024.0L), 10) > real.mant_dig-10);
 }
 
 /*****************************************
@@ -7639,6 +7642,34 @@ private real polyImpl(real x, in real[]
         {
             asm pure nothrow @nogc // assembler by W. Bright
             {
+                // EDX = (A.length - 1) * real.sizeof
+                mov     ECX,A[EBP]              ; // ECX = A.length
+                dec     ECX                     ;
+                lea     EDX,[ECX*8]             ;
+                lea     EDX,[EDX][ECX*4]        ;
+                add     EDX,A+4[EBP]            ;
+                fld     real ptr [EDX]          ; // ST0 = coeff[ECX]
+                jecxz   return_ST               ;
+                fld     x[EBP]                  ; // ST0 = x
+                fxch    ST(1)                   ; // ST1 = x, ST0 = r
+                align   4                       ;
+        L2:     fmul    ST,ST(1)                ; // r *= x
+                fld     real ptr -12[EDX]       ;
+                sub     EDX,12                  ; // deg--
+                faddp   ST(1),ST                ;
+                dec     ECX                     ;
+                jne     L2                      ;
+                fxch    ST(1)                   ; // ST1 = r, ST0 = x
+                fstp    ST(0)                   ; // dump x
+                align   4                       ;
+        return_ST:                              ;
+                ;
+            }
+        }
+        else version (NetBSD)
+        {
+            asm pure nothrow @nogc // assembler by W. Bright
+            {
                 // EDX = (A.length - 1) * real.sizeof
                 mov     ECX,A[EBP]              ; // ECX = A.length
                 dec     ECX                     ;
