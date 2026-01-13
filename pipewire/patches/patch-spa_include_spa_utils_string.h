$NetBSD$

* NetBSD has no uselocale()

--- spa/include/spa/utils/string.h.orig	2026-01-13 13:54:22.877334597 +0000
+++ spa/include/spa/utils/string.h
@@ -13,7 +13,11 @@ extern "C" {
 #include <stdbool.h>
 #include <errno.h>
 #include <stdlib.h>
+#if defined(__NetBSD__)
+#define __LOCALE_C_ONLY 1
+#else
 #include <locale.h>
+#endif
 
 #include <spa/utils/defs.h>
 
