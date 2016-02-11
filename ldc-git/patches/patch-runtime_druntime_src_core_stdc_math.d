$NetBSD$

--- runtime/druntime/src/core/stdc/math.d.orig	2016-01-21 15:39:03.000000000 +0000
+++ runtime/druntime/src/core/stdc/math.d
@@ -45,6 +45,11 @@ version (FreeBSD)
     ///
     enum int FP_ILOGBNAN      = int.max;
 }
+else version (NetBSD)
+{
+    enum FP_ILOGB0     = int.min;
+    enum FP_ILOGBNAN   = int.max;
+}
 else version (CRuntime_Bionic)
 {
     ///
@@ -813,6 +818,89 @@ else version( FreeBSD )
     int signbit(real x)         { return __signbit(x); }
   }
 }
+else version( NetBSD )
+{
+    enum
+    {
+        FP_INFINITE	= 0x00,
+	FP_NAN		= 0x01,
+	FP_NORMAL	= 0x02,
+	FP_SUBNORMAL	= 0x03,
+	FP_ZERO		= 0x04,
+ /* NetBSD extensions */
+	_FP_LOMD	= 0x80,		/* range for machine-specific classes */
+	_FP_HIMD	= 0xff,
+    }
+ /*
+  * Library implementation
+  */
+    int	__fpclassifyf(float);
+    int	__fpclassifyd(double);
+    int	__isfinitef(float);
+    int	__isfinited(double);
+    int	__isinff(float);
+    int	__isinfd(double);
+    int	__isnanf(float);
+    int	__isnand(double);
+    int	__signbitf(float);
+    int	__signbitd(double);
+
+    int	__fpclassifyl(real);
+    int	__isfinitel(real);
+    int	__isinfl(real);
+    int	__isnanl(real);
+    int	__signbitl(real);
+  extern (D)
+  {
+    //int fpclassify(real-floating x);
+      ///
+    int fpclassify(float x)     { return __fpclassifyf(x); }
+    ///
+    int fpclassify(double x)    { return __fpclassifyd(x); }
+    ///
+    int fpclassify(real x)      { return __fpclassifyl(x); }
+
+    //int isfinite(real-floating x);
+    ///
+    int isfinite(float x)       { return __isfinitef(x); }
+    ///
+    int isfinite(double x)      { return __isfinited(x); }
+    ///
+    int isfinite(real x)        { return __isfinitel(x); }
+
+    //int isinf(real-floating x);
+    ///
+    int isinf(float x)          { return __isinff(x); }
+    ///
+    int isinf(double x)         { return __isinfd(x); }
+    ///
+    int isinf(real x)           { return __isinfl(x); }
+
+    //int isnan(real-floating x);
+    ///
+    int isnan(float x)          { return __isnanf(x); }
+    ///
+    int isnan(double x)         { return __isnand(x); }
+    ///
+    int isnan(real x)           { return __isnanl(x); }
+
+    //int isnormal(real-floating x);
+    ///
+    int isnormal(float x)       { return __fpclassifyf(x) == FP_NORMAL; }
+    ///
+    int isnormal(double x)      { return __fpclassifyd(x) == FP_NORMAL; }
+    ///
+    int isnormal(real x)        { return __fpclassifyl(x) == FP_NORMAL; }
+
+    //int signbit(real-floating x);
+    ///
+    int signbit(float x)        { return __signbitf(x); }
+    ///
+    int signbit(double x)       { return __signbitd(x); }
+    ///
+    int signbit(real x)         { return __signbitl(x); }
+  }
+}
 else version( Solaris )
 {
     int __isnanf(float x);
