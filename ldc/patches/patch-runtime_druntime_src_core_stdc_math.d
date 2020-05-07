$NetBSD$

--- runtime/druntime/src/core/stdc/math.d.orig	2018-08-23 23:29:55.000000000 +0000
+++ runtime/druntime/src/core/stdc/math.d
@@ -52,6 +52,13 @@ else version (DragonFlyBSD)
     ///
     enum int FP_ILOGBNAN      = int.max;
 }
+version ( NetBSD )
+{
+    ///
+    enum int FP_ILOGB0        = -int.max;
+    ///
+    enum int FP_ILOGBNAN      = int.max;
+}
 else version (CRuntime_Bionic)
 {
     ///
@@ -1521,7 +1528,7 @@ else version( FreeBSD )
   }
   else
   {
-      ///
+    ///
     real    acosl(real x);
     ///
     real    asinl(real x);
