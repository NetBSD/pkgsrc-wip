$NetBSD$

# gcc7 error

--- src/fastblas.cpp.orig	2019-04-29 21:49:43.950495513 +0000
+++ src/fastblas.cpp
@@ -66,9 +66,9 @@ gsl_matrix *fast_copy(gsl_matrix *m, con
 /*
     Helper function fast_cblas_dgemm runs the local dgemm
 */
-void fast_cblas_dgemm(const enum CBLAS_ORDER Order,
-                      const enum CBLAS_TRANSPOSE TransA,
-                      const enum CBLAS_TRANSPOSE TransB,
+void fast_cblas_dgemm(const CBLAS_ORDER Order,
+                      const CBLAS_TRANSPOSE TransA,
+                      const CBLAS_TRANSPOSE TransB,
                       const size_t M,
                       const size_t N,
                       const size_t K,
