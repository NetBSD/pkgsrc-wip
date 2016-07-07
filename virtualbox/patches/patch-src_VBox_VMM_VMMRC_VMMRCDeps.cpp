$NetBSD$

--- src/VBox/VMM/VMMRC/VMMRCDeps.cpp.orig	2016-03-04 19:30:13.000000000 +0000
+++ src/VBox/VMM/VMMRC/VMMRCDeps.cpp
@@ -18,12 +18,12 @@
 #include <iprt/crc.h>
 #include <iprt/string.h>
 
-#if defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 RT_C_DECLS_BEGIN
 extern uint64_t __udivdi3(uint64_t, uint64_t);
 extern uint64_t __umoddi3(uint64_t, uint64_t);
 RT_C_DECLS_END
-#endif // RT_OS_SOLARIS || RT_OS_FREEBSD
+#endif // RT_OS_SOLARIS || RT_OS_FREEBSD || RT_OS_NETBSD
 
 PFNRT g_VMMRCDeps[] =
 {
@@ -32,10 +32,9 @@ PFNRT g_VMMRCDeps[] =
     (PFNRT)memchr,
     (PFNRT)memcmp,
     (PFNRT)RTCrc32,
-#if defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     (PFNRT)__udivdi3,
     (PFNRT)__umoddi3,
-#endif // RT_OS_SOLARIS || RT_OS_FREEBSD
+#endif // RT_OS_SOLARIS || RT_OS_FREEBSD || RT_OS_NETBSD
     NULL
 };
-
