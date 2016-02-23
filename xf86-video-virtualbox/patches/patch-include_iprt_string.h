$NetBSD$

--- include/iprt/string.h.orig	2016-01-19 16:39:50.000000000 +0000
+++ include/iprt/string.h
@@ -113,11 +113,13 @@ char *strpbrk(const char *pszStr, const 
 RT_C_DECLS_END
 #endif
 
+#if 0
 #if !defined(RT_OS_LINUX) || !defined(_GNU_SOURCE)
 RT_C_DECLS_BEGIN
 void *memrchr(const char *pv, int ch, size_t cb);
 RT_C_DECLS_END
 #endif
+#endif
 
 
 /** @def RT_USE_RTC_3629
