$NetBSD$

--- include/vlc_fixups.h.orig	2018-01-08 12:11:47.000000000 +0000
+++ include/vlc_fixups.h
@@ -320,16 +320,28 @@ void *aligned_alloc(size_t, size_t);
 
 /* locale.h */
 #ifndef HAVE_USELOCALE
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if __NetBSD_Version__ >= 699002300
+/* NetBSD-current has locale_t but no uselocale */
+#define NetBSD_LOCALE_HACK
+#endif
+#endif
+#ifdef NetBSD_LOCALE_HACK
+#include <locale.h>
+#else
 #define LC_ALL_MASK      0
 #define LC_NUMERIC_MASK  0
 #define LC_MESSAGES_MASK 0
 #define LC_GLOBAL_LOCALE ((locale_t)(uintptr_t)1)
 typedef void *locale_t;
+#endif
 static inline locale_t uselocale(locale_t loc)
 {
     (void)loc;
     return NULL;
 }
+#ifndef NetBSD_LOCALE_HACK
 static inline void freelocale(locale_t loc)
 {
     (void)loc;
@@ -340,8 +352,9 @@ static inline locale_t newlocale(int mas
     return NULL;
 }
 #endif
+#endif
 
-#if !defined (HAVE_STATIC_ASSERT) && !defined(__cpp_static_assert)
+#if !defined (HAVE_STATIC_ASSERT) && !defined(__cpp_static_assert) && !defined(static_assert)
 # define STATIC_ASSERT_CONCAT_(a, b) a##b
 # define STATIC_ASSERT_CONCAT(a, b) STATIC_ASSERT_CONCAT_(a, b)
 # define _Static_assert(x, s) extern char STATIC_ASSERT_CONCAT(static_assert_, __LINE__)[sizeof(struct { unsigned:-!(x); })]
