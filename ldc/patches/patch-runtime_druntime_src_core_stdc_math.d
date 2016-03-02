$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/stdc/math.d.orig	2016-02-13 20:02:16.000000000 +0000
+++ runtime/druntime/src/core/stdc/math.d
@@ -45,6 +45,13 @@ version (FreeBSD)
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
@@ -813,6 +820,97 @@ else version( FreeBSD )
     int signbit(real x)         { return __signbit(x); }
   }
 }
+else version( NetBSD )
+{
+    enum
+    {
+        ///
+        FP_INFINITE    = 0,
+        ///
+        FP_NAN         = 1,
+        ///
+        FP_NORMAL      = 2,
+        ///
+        FP_SUBNORMAL   = 3,
+        ///
+        FP_ZERO        = 4,
+    }
+
+    enum
+    {
+        ///
+        FP_FAST_FMA  = 0,
+        ///
+        FP_FAST_FMAF = 0,
+        ///
+        FP_FAST_FMAL = 0,
+    }
+
+    uint __fpclassifyf(float x);
+    uint __fpclassifyd(double x);
+    uint __fpclassifyl(real x);
+
+  extern (D)
+  {
+    //int fpclassify(real-floating x);
+    ///
+    int fpclassify(float x)     { return __fpclassifyf(x); }
+    ///
+    int fpclassify(double x)    { return __fpclassifyd(x); }
+    ///
+    int fpclassify(real x)
+    {
+        return (real.sizeof == double.sizeof)
+            ? __fpclassifyd(x)
+            : __fpclassifyl(x);
+    }
+
+    //int isfinite(real-floating x);
+    ///
+    int isfinite(float x)       { return fpclassify(x) >= FP_NORMAL; }
+    ///
+    int isfinite(double x)      { return fpclassify(x) >= FP_NORMAL; }
+    ///
+    int isfinite(real x)        { return fpclassify(x) >= FP_NORMAL; }
+
+    //int isinf(real-floating x);
+    ///
+    int isinf(float x)          { return fpclassify(x) == FP_INFINITE; }
+    ///
+    int isinf(double x)         { return fpclassify(x) == FP_INFINITE; }
+    ///
+    int isinf(real x)           { return fpclassify(x) == FP_INFINITE; }
+
+    //int isnan(real-floating x);
+    ///
+    int isnan(float x)          { return fpclassify(x) == FP_NAN;   }
+    ///
+    int isnan(double x)         { return fpclassify(x) == FP_NAN;   }
+    ///
+    int isnan(real x)           { return fpclassify(x) == FP_NAN;   }
+
+    //int isnormal(real-floating x);
+    ///
+    int isnormal(float x)       { return fpclassify(x) == FP_NORMAL; }
+    ///
+    int isnormal(double x)      { return fpclassify(x) == FP_NORMAL; }
+    ///
+    int isnormal(real x)        { return fpclassify(x) == FP_NORMAL; }
+
+    //int signbit(real-floating x);
+    ///
+    int signbit(float x)     { return (cast(short*)&(x))[1] & 0x8000; }
+    ///
+    int signbit(double x)    { return (cast(short*)&(x))[3] & 0x8000; }
+    ///
+    int signbit(real x)
+    {
+        return (real.sizeof == double.sizeof)
+            ? (cast(short*)&(x))[3] & 0x8000
+            : (cast(short*)&(x))[4] & 0x8000;
+    }
+  }
+}
 else version( Solaris )
 {
     int __isnanf(float x);
@@ -1450,7 +1548,7 @@ else version( FreeBSD )
   }
   else
   {
-      ///
+    ///
     real    acosl(real x);
     ///
     real    asinl(real x);
@@ -1850,6 +1948,452 @@ else version( FreeBSD )
     ///
     float   fmaf(float x, float y, float z);
 }
+else version( NetBSD )
+{
+
+    ///
+    real    acosl(real x) ;
+    ///
+    real    asinl(real x) ;
+    ///
+    real    atanl(real x) ;
+    ///
+    real    atan2l(real y, real x) ;
+    ///
+    real    cosl(real x) ;
+    ///
+    real    sinl(real x) ;
+    ///
+    real    tanl(real x) ;
+    ///
+    real    exp2l(real x) ;
+    ///
+    real    frexpl(real value, int* exp) ;
+    ///
+    int     ilogbl(real x) ;
+    ///
+    real    ldexpl(real x, int exp) ;
+    ///
+    real    logbl(real x) ;
+    ///
+    real    modfl(real value, real *iptr) ;
+    ///
+    real    scalbnl(real x, int n) ;
+    ///
+    real    scalblnl(real x, c_long n) ;
+    ///
+    real    fabsl(real x) ;
+    ///
+    real    hypotl(real x, real y) ;
+    ///
+    real    sqrtl(real x) ;
+    ///
+    real    ceill(real x) ;
+    ///
+    real    floorl(real x) ;
+    ///
+    real    nearbyintl(real x) ;
+    ///
+    real    rintl(real x) ;
+    ///
+    c_long  lrintl(real x) { return cast(c_long)rintl(x); }
+    ///
+    real    roundl(real x) ;
+    ///
+    c_long  lroundl(real x) { return cast(c_long)roundl(x);}
+    ///
+    long    llroundl(real x) { return cast(long)roundl(x);}
+    ///
+    real    truncl(real x) ;
+    ///
+    real    fmodl(real x, real y) ;
+    ///
+    real    remainderl(real x, real y)  { return remainder(x,y); }
+    ///
+    real    remquol(real x, real y, int* quo){ return remquo(x,y,quo); }
+    ///
+    real    copysignl(real x, real y)  ;
+    ///
+    double  nan(char* tagp);
+    ///
+    float   nanf(char* tagp);
+    ///
+    real    nanl(char* tagp);
+    ///
+    real    nextafterl(real x, real y) ;
+    ///
+    real    nexttowardl(real x, real y) { return nexttoward(cast(double) x, cast(double) y); }
+    ///
+    real    fdiml(real x, real y) ;
+    ///
+    real    fmaxl(real x, real y) ;
+    ///
+    real    fminl(real x, real y) ;
+    ///
+    real    fmal(real x, real y, real z) ;
+
+    ///
+    double  acos(double x);
+    ///
+    float   acosf(float x);
+
+    ///
+    double  asin(double x);
+    ///
+    float   asinf(float x);
+
+    ///
+    double  atan(double x);
+    ///
+    float   atanf(float x);
+
+    ///
+    double  atan2(double y, double x);
+    ///
+    float   atan2f(float y, float x);
+
+    ///
+    double  cos(double x);
+    ///
+    float   cosf(float x);
+
+    ///
+    double  sin(double x);
+    ///
+    float   sinf(float x);
+
+    ///
+    double  tan(double x);
+    ///
+    float   tanf(float x);
+
+    ///
+    double  acosh(double x);
+    ///
+    float   acoshf(float x);
+    ///
+    real    acoshl(real x) ;
+
+    ///
+    double  asinh(double x);
+    ///
+    float   asinhf(float x);
+    ///
+    real    asinhl(real x) ;
+
+    ///
+    double  atanh(double x);
+    ///
+    float   atanhf(float x);
+    ///
+    real    atanhl(real x) ;
+
+    ///
+    double  cosh(double x);
+    ///
+    float   coshf(float x);
+    ///
+    real    coshl(real x) ;
+
+    ///
+    double  sinh(double x);
+    ///
+    float   sinhf(float x);
+    ///
+    real    sinhl(real x);
+
+    ///
+    double  tanh(double x);
+    ///
+    float   tanhf(float x);
+    ///
+    real    tanhl(real x) ;
+
+    ///
+    double  exp(double x);
+    ///
+    float   expf(float x);
+    ///
+    real    expl(real x) ;
+
+    ///
+    double  exp2(double x);
+    ///
+    float   exp2f(float x);
+
+    ///
+    double  expm1(double x);
+    ///
+    float   expm1f(float x);
+    ///
+    real    expm1l(real x)  { return expm1(cast(double) x); }
+
+    ///
+    double  frexp(double value, int* exp);
+    ///
+    float   frexpf(float value, int* exp);
+
+    ///
+    int     ilogb(double x);
+    ///
+    int     ilogbf(float x);
+
+    ///
+    double  ldexp(double x, int exp);
+    ///
+    float   ldexpf(float x, int exp);
+
+    ///
+    double  log(double x);
+    ///
+    float   logf(float x);
+    /// NetBSD has no logl. It is just alias log(double)
+    real    logl(real x)
+    {
+        if(x<0) return real.nan;
+        if(x==0) return -real.infinity;
+        if(isnan(x) || isinf(x)) return x;
+        real rs = 0;
+        if(x>double.max)
+        {
+            immutable MAX = log(double.max);
+            for(; x>double.max; x /= double.max)
+                rs += MAX;
+        }
+        else if(x<double.min_normal)
+        {
+            immutable MIN = log(double.min_normal);
+            for(; x<double.min_normal; x /= double.min_normal)
+                rs += MIN;
+        }
+        rs += log(x);
+        return rs;
+    }
+
+    ///
+    double  log10(double x);
+    ///
+    float   log10f(float x);
+    ///NetBSD has no log10l. It is just alias log(double)
+    real    log10l(real x)
+    {
+        if(x<0) return real.nan;
+        if(x==0) return -real.infinity;
+        if(isnan(x) || isinf(x)) return x;
+
+        real rs = 0;
+        if(x>double.max)
+        {
+            immutable MAX = log10(double.max);
+            for(; x>double.max; x /= double.max)
+                rs += MAX;
+        }
+        else if(x<double.min_normal)
+        {
+            immutable MIN = log10(double.min_normal);
+            for(; x<double.min_normal; x /= double.min_normal)
+                rs += MIN;
+        }
+        rs += log10(x);
+
+        return rs;
+    }
+
+
+    ///
+    double  log1p(double x);
+    ///
+    float   log1pf(float x);
+    ///
+    real    log1pl(real x) { return log1p(cast(double) x); }
+
+    private enum real ONE_LN2 = 1 / 0x1.62e42fefa39ef358p-1L;
+    ///
+    double  log2(double x) { return log(x) * ONE_LN2; }
+    ///
+    float   log2f(float x) { return logf(x) * ONE_LN2; }
+    ///
+    real    log2l(real x)  { return logl(x) * ONE_LN2; }
+
+    ///
+    double  logb(double x);
+    ///
+    float   logbf(float x);
+
+    ///
+    double  modf(double value, double* iptr);
+    ///
+    float   modff(float value, float* iptr);
+
+    ///
+    double  scalbn(double x, int n);
+    ///
+    float   scalbnf(float x, int n);
+
+    ///
+    double  scalbln(double x, c_long n);
+    ///
+    float   scalblnf(float x, c_long n);
+
+    ///
+    double  cbrt(double x);
+    ///
+    float   cbrtf(float x);
+    ///
+    real    cbrtl(real x);
+
+    ///
+    double  fabs(double x);
+    ///
+    float   fabsf(float x);
+
+    ///
+    double  hypot(double x, double y);
+    ///
+    float   hypotf(float x, float y);
+
+    ///
+    double  pow(double x, double y);
+    ///
+    float   powf(float x, float y);
+    ///
+    real    powl(real x, real y);
+
+    ///
+    double  sqrt(double x);
+    ///
+    float   sqrtf(float x);
+
+    ///
+    double  erf(double x);
+    ///
+    float   erff(float x);
+    ///
+    real    erfl(real x) { return erf(cast(double) x); }
+
+    ///
+    double  erfc(double x);
+    ///
+    float   erfcf(float x);
+    ///
+    real    erfcl(real x)  { return erfc(cast(double) x); }
+
+    ///
+    double  lgamma(double x);
+    ///
+    float   lgammaf(float x);
+    ///
+    real    lgammal(real x){ return lgamma(x); }
+
+    ///
+    double  tgamma(double x);
+    ///
+    float   tgammaf(float x);
+    ///
+    real    tgammal(real x){ return tgamma(cast(double) x); }
+
+    ///
+    double  ceil(double x);
+    ///
+    float   ceilf(float x);
+
+    ///
+    double  floor(double x);
+    ///
+    float   floorf(float x);
+
+    ///
+    double  nearbyint(double x);
+    ///
+    float   nearbyintf(float x);
+
+    ///
+    double  rint(double x);
+    ///
+    float   rintf(float x);
+
+    ///
+    c_long  lrint(double x);
+    ///
+    c_long  lrintf(float x);
+
+    ///
+    long    llrint(double x);
+    ///
+    long    llrintf(float x);
+    ///
+    long    llrintl(real x) { return cast(long)rintl(x); }
+
+    ///
+    double  round(double x);
+    ///
+    float   roundf(float x);
+
+    ///
+    c_long  lround(double x);
+    ///
+    c_long  lroundf(float x);
+
+    ///
+    long    llround(double x);
+    ///
+    long    llroundf(float x);
+
+    ///
+    double  trunc(double x);
+    ///
+    float   truncf(float x);
+
+    ///
+    double  fmod(double x, double y);
+    ///
+    float   fmodf(float x, float y);
+
+    ///
+    double  remainder(double x, double y);
+    ///
+    float   remainderf(float x, float y);
+
+    ///
+    double  remquo(double x, double y, int* quo);
+    ///
+    float   remquof(float x, float y, int* quo);
+
+    ///
+    double  copysign(double x, double y);
+    ///
+    float   copysignf(float x, float y);
+
+    ///
+    double  nextafter(double x, double y);
+    ///
+    float   nextafterf(float x, float y);
+
+    ///
+    double  nexttoward(double x, real y);
+    ///
+    float   nexttowardf(float x, real y);
+
+    ///
+    double  fdim(double x, double y);
+    ///
+    float   fdimf(float x, float y);
+
+    ///
+    double  fmax(double x, double y);
+    ///
+    float   fmaxf(float x, float y);
+
+    ///
+    double  fmin(double x, double y);
+    ///
+    float   fminf(float x, float y);
+
+    ///
+    double  fma(double x, double y, double z);
+    ///
+    float   fmaf(float x, float y, float z);
+}
 else version(CRuntime_Bionic)
 {
     // Bionic defines long double as 64 bits, same as double, so several long
