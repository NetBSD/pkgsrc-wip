$NetBSD$

--- include/iprt/string.h.orig	2016-03-04 19:23:01.000000000 +0000
+++ include/iprt/string.h
@@ -113,7 +113,7 @@ char *strpbrk(const char *pszStr, const 
 RT_C_DECLS_END
 #endif
 
-#if !defined(RT_OS_LINUX) || !defined(_GNU_SOURCE)
+#if (!defined(RT_OS_LINUX) || !defined(_GNU_SOURCE)) && !defined(RT_OS_NETBSD)
 RT_C_DECLS_BEGIN
 void *memrchr(const char *pv, int ch, size_t cb);
 RT_C_DECLS_END
@@ -3018,4 +3018,3 @@ RTDECL(uint32_t)    RTStrHash1ExNV(size_
 RT_C_DECLS_END
 
 #endif
-
