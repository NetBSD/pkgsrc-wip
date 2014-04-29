$NetBSD: patch-gcc_fortran_f95-lang.c,v 1.1 2014/04/29 14:14:34 keckhardt Exp $

--- gcc/fortran/f95-lang.c.orig	2013-11-12 20:26:43.000000000 +0000
+++ gcc/fortran/f95-lang.c
@@ -713,12 +713,21 @@ gfc_init_builtin_functions (void)
   gfc_define_builtin ("__builtin_truncf", mfunc_float[0],
 		      BUILT_IN_TRUNCF, "truncf", ATTR_CONST_NOTHROW_LEAF_LIST);
 
+#if defined(__NetBSD__)
+  gfc_define_builtin ("__builtin_cabsl", func_clongdouble_longdouble, 
+		      BUILT_IN_CABSL, "__c99_cabsl", ATTR_CONST_NOTHROW_LEAF_LIST);
+  gfc_define_builtin ("__builtin_cabs", func_cdouble_double, 
+		      BUILT_IN_CABS, "__c99_cabs", ATTR_CONST_NOTHROW_LEAF_LIST);
+  gfc_define_builtin ("__builtin_cabsf", func_cfloat_float, 
+		      BUILT_IN_CABSF, "__c99_cabsf", ATTR_CONST_NOTHROW_LEAF_LIST);
+#else
   gfc_define_builtin ("__builtin_cabsl", func_clongdouble_longdouble, 
 		      BUILT_IN_CABSL, "cabsl", ATTR_CONST_NOTHROW_LEAF_LIST);
   gfc_define_builtin ("__builtin_cabs", func_cdouble_double, 
 		      BUILT_IN_CABS, "cabs", ATTR_CONST_NOTHROW_LEAF_LIST);
   gfc_define_builtin ("__builtin_cabsf", func_cfloat_float, 
 		      BUILT_IN_CABSF, "cabsf", ATTR_CONST_NOTHROW_LEAF_LIST);
+#endif
  
   gfc_define_builtin ("__builtin_copysignl", mfunc_longdouble[1], 
 		      BUILT_IN_COPYSIGNL, "copysignl",
