$NetBSD: patch-dolfin_adaptivity_ErrorControl.h,v 1.1.1.1 2012/03/27 17:06:53 outpaddling Exp $

--- dolfin/adaptivity/ErrorControl.h.orig	2011-12-07 21:21:22.000000000 +0000
+++ dolfin/adaptivity/ErrorControl.h
@@ -223,6 +223,9 @@ namespace dolfin
 
     bool _is_linear;
 
+#undef _B
+#undef _C
+
     // Function spaces for extrapolation, cell bubble and cell cone:
     boost::shared_ptr<const FunctionSpace> _E;
     boost::shared_ptr<const FunctionSpace> _B;
