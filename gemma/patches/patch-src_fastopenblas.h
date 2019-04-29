$NetBSD$

# gcc7 error

--- src/fastopenblas.h.orig	2019-04-29 21:48:45.740065714 +0000
+++ src/fastopenblas.h
@@ -29,9 +29,9 @@ extern "C"
 }
 #include "gsl/gsl_matrix.h"
 
-void fast_cblas_dgemm(const enum CBLAS_ORDER Order,
-                      const enum CBLAS_TRANSPOSE TransA,
-                      const enum CBLAS_TRANSPOSE TransB,
+void fast_cblas_dgemm(const CBLAS_ORDER Order,
+                      const CBLAS_TRANSPOSE TransA,
+                      const CBLAS_TRANSPOSE TransB,
                       const size_t M,
                       const size_t N,
                       const size_t K,
