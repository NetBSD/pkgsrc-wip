$NetBSD$

--- src/VBox/Devices/EFI/Firmware/StdLib/Include/locale.h.orig	2016-03-04 19:27:22.000000000 +0000
+++ src/VBox/Devices/EFI/Firmware/StdLib/Include/locale.h
@@ -185,7 +185,7 @@ __BEGIN_DECLS
   char    *setlocale(int category, const char *locale);
   char    *__setlocale(int category, const char *locale);
 #else /* !__SETLOCALE_SOURCE__ */
-  char    *setlocale(int category, const char *locale) __RENAME(__setlocale_mb_len_max_32);
+  char    *setlocale(int category, const char *locale) ;//__RENAME(__setlocale_mb_len_max_32);
 #endif /* !__SETLOCALE_SOURCE__ */
 struct lconv  *localeconv(void);
   char    *__setlocale_mb_len_max_32(int category, const char *locale);
