$NetBSD$

--- include/vlc_fixups.h.orig	2018-02-22 06:29:54.000000000 +0000
+++ include/vlc_fixups.h
@@ -316,24 +316,51 @@ void *aligned_alloc(size_t, size_t);
 
 #if defined(__native_client__) && defined(__cplusplus)
 # define HAVE_USELOCALE
+# define HAVE_FREELOCALE
+# define HAVE_NEWLOCALE
 #endif
 
 /* locale.h */
-#ifndef HAVE_USELOCALE
+#ifdef HAVE_LOCALE_H
+#include <locale.h>
+#endif
+
+#ifndef LC_ALL_MASK
 #define LC_ALL_MASK      0
+#endif
+
+#ifndef LC_NUMERIC_MASK
 #define LC_NUMERIC_MASK  0
+#endif
+
+#ifndef LC_MESSAGES_MASK
 #define LC_MESSAGES_MASK 0
-#define LC_GLOBAL_LOCALE ((locale_t)(uintptr_t)1)
+#endif
+
+#ifndef HAVE_LOCALE_T
 typedef void *locale_t;
+#endif
+
+#ifndef LC_GLOBAL_LOCALE
+#define LC_GLOBAL_LOCALE ((locale_t)(uintptr_t)1)
+#endif
+
+#ifndef HAVE_USELOCALE
 static inline locale_t uselocale(locale_t loc)
 {
     (void)loc;
     return NULL;
 }
+#endif
+
+#ifndef HAVE_FREELOCALE
 static inline void freelocale(locale_t loc)
 {
     (void)loc;
 }
+#endif
+
+#ifndef HAVE_NEWLOCALE
 static inline locale_t newlocale(int mask, const char * locale, locale_t base)
 {
     (void)mask; (void)locale; (void)base;
