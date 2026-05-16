$NetBSD$

--- gmp/acinclude.m4.orig	2023-07-29 13:42:16.000000000 +0000
+++ gmp/acinclude.m4
@@ -3191,7 +3191,15 @@ AC_DEFUN([GMP_C_ATTRIBUTE_MODE],
 AC_DEFUN([GMP_C_ATTRIBUTE_MODE],
 [AC_CACHE_CHECK([whether gcc __attribute__ ((mode (XX))) works],
                 gmp_cv_c_attribute_mode,
-[AC_TRY_COMPILE([typedef int SItype __attribute__ ((mode (SI)));], ,
+[AC_TRY_COMPILE([
+  typedef int SItype __attribute__ ((mode (SI)));
+  typedef int QItype __attribute__ ((mode (QI)));
+], [
+  switch (1) {
+  case sizeof(SItype):
+  case sizeof(QItype): ;
+  }
+],
   gmp_cv_c_attribute_mode=yes, gmp_cv_c_attribute_mode=no)
 ])
 if test $gmp_cv_c_attribute_mode = yes; then
