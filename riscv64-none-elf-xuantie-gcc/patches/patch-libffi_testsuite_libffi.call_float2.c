$NetBSD$

--- libffi/testsuite/libffi.call/float2.c.orig	2024-10-28 05:14:44.230561111 +0000
+++ libffi/testsuite/libffi.call/float2.c
@@ -45,7 +45,7 @@ int main (void)
   /* This is ifdef'd out for now. long double support under SunOS/gcc
      is pretty much non-existent.  You'll get the odd bus error in library
      routines like printf().  */
-  printf ("%Lf, %Lf, %Lf, %Lf\n", ld, ldblit(f), ld - ldblit(f), LDBL_EPSILON);
+  printf ("%Lf, %Lf, %Lf, %Lf\n", (long double)ld, (long double)ldblit(f), (long double)(ld - ldblit(f)), (long double)LDBL_EPSILON);
 #endif
 
   /* These are not always the same!! Check for a reasonable delta */
