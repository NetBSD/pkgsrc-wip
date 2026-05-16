$NetBSD$

--- mpc/src/get_x.c.orig	2022-12-12 09:22:59.000000000 +0000
+++ mpc/src/get_x.c
@@ -32,6 +32,13 @@ along with this program. If not, see http://www.gnu.or
 #include "mpc-impl.h"
 
 #ifdef HAVE_COMPLEX_H
+
+#if defined(__sun) && defined(__GNUC__) && defined(_Imaginary_I)
+#undef I
+#define I	(__extension__ 1.0iF)
+
+#endif
+
 double _Complex
 mpc_get_dc (mpc_srcptr op, mpc_rnd_t rnd) {
    return I * mpfr_get_d (mpc_imagref (op), MPC_RND_IM (rnd))
