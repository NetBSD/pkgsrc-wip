$NetBSD$

API change on gettext-lib 0.22

--- src/nmath/nmath.h.orig	2023-05-02 07:15:02.000000000 +0900
+++ src/nmath/nmath.h	2023-07-19 23:52:26.912202724 +0900
@@ -233,4 +233,9 @@ void attribute_hidden bratio(double a, d
 	    		     double *w, double *w1, int *ierr, int log_p);
 
 
+#ifndef _LIBINTL_H
+#  define _INTL_REDIRECT_MACROS
+#  include "gettext/libintl.h"
+#endif
+
 #endif /* MATHLIB_PRIVATE_H */
