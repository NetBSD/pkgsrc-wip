$NetBSD: patch-dolfin_fem_LinearVariationalProblem.h,v 1.1.1.1 2012/03/27 17:06:53 outpaddling Exp $

--- dolfin/fem/LinearVariationalProblem.h.orig	2011-12-07 21:21:22.000000000 +0000
+++ dolfin/fem/LinearVariationalProblem.h
@@ -98,6 +98,8 @@ namespace dolfin
     // The bilinear form
     boost::shared_ptr<const Form> _a;
 
+#undef _L
+
     // The linear form
     boost::shared_ptr<const Form> _L;
 
