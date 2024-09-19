--- gcc/config/netbsd-protos.h.orig	2020-01-01 12:51:42.000000000 +0100
+++ gcc/config/netbsd-protos.h	2020-01-12 17:50:32.027540861 +0100
@@ -17,4 +17,15 @@
 along with GCC; see the file COPYING3.  If not see
 <http://www.gnu.org/licenses/>.  */
 
+#ifndef _NETBSD_PROTOS_H_
+#define _NETBSD_PROTOS_H_
+
+double __c99_cabs (double complex);
+float __c99_cabsf (float complex);
+long double __c99_cabsl (long double complex);
+
+void netbsd_patch_builtins (void);
+
+#endif /* _NETBSD_PROTOS_H_ */
+
 extern void netbsd_patch_builtins (void);
