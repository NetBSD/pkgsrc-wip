$NetBSD$

# Silence warnings

--- src/matvec.cpp.orig	2022-11-12 14:21:36 UTC
+++ src/matvec.cpp
@@ -405,9 +405,12 @@ void getavgw(double *avg, double *sig, double ia[], do
 {
   int i; double a, b, wt=0., rdum;
   a=b=0;
+  cerr << "N = " << N << endl;
   for (i=0;i<N;i++) { 
     wt+=weight[i];  rdum=ia[i];
     a+=rdum*weight[i]; b+=rdum*rdum*weight[i];
+    cerr << "rdum = " << rdum << " weight[i] = " << weight[i];
+    cerr << " a = " << a << " b = " << b << " wt = " << wt << endl;
   }
   a/=wt; b/=wt;
   b=b-a*a; if (fabs(b)<TOL) b=0.; // take care of roundoff
