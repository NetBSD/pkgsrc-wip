$NetBSD$

starting gettext-0.22, some symbols are hidden, and make them visible

--- src/include/Defn.h.orig	2023-05-02 07:15:02.000000000 +0900
+++ src/include/Defn.h	2023-07-17 20:40:16.631815063 +0900
@@ -2355,6 +2355,10 @@ extern void *alloca(size_t);
 // for reproducibility for now: use exp10 or pown later if accurate enough.
 #define Rexp10(x) pow(10.0, x)
 
+/* starting gettext-0.22, some symbols are hidden, and make them visible */
+#define _INTL_REDIRECT_MACROS
+#include "gettext/libintl.h"
+
 #endif /* DEFN_H_ */
 /*
  *- Local Variables:
