$NetBSD$

--- src/extra/tre/tre-internal.h.orig	2022-03-25 08:02:02.000000000 +0900
+++ src/extra/tre/tre-internal.h	2024-01-01 18:30:52.973421432 +0900
@@ -18,6 +18,7 @@
 #endif /* !HAVE_WCTYPE_H */
 
 #include <ctype.h>
+#include <stdint.h>
 #include "tre.h"
 
 #ifdef TRE_DEBUG
