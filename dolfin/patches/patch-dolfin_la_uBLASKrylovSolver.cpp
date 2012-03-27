$NetBSD: patch-dolfin_la_uBLASKrylovSolver.cpp,v 1.1.1.1 2012/03/27 17:06:53 outpaddling Exp $

--- dolfin/la/uBLASKrylovSolver.cpp.orig	2011-12-07 21:21:22.000000000 +0000
+++ dolfin/la/uBLASKrylovSolver.cpp
@@ -97,6 +97,7 @@ dolfin::uint uBLASKrylovSolver::solve(Ge
   dolfin_assert(_A);
 
   dolfin_assert(P);
+#undef _P
   boost::shared_ptr<const uBLASMatrix<ublas_sparse_matrix> > _P
         = GenericTensor::down_cast<const uBLASMatrix<ublas_sparse_matrix> >(P);
   dolfin_assert(_P);
