--- syn68k_public.h.orig	2009-12-05 18:36:04.000000000 -0600
+++ syn68k_public.h	2012-02-21 08:52:13.000000000 -0600
@@ -1,7 +1,12 @@
 #if !defined (_syn68k_public_h_)
 #define _syn68k_public_h_
 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
+#ifdef HAVE_INTTYPES_H
+#include <inttypes.h>
+#endif
 #include <setjmp.h>
 
 /* Decide whether we are big or little endian here.  Add more machines as
