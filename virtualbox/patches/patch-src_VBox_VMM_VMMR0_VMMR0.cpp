$NetBSD$

--- src/VBox/VMM/VMMR0/VMMR0.cpp.orig	2016-03-04 19:30:11.000000000 +0000
+++ src/VBox/VMM/VMMR0/VMMR0.cpp
@@ -122,7 +122,7 @@
 *   Internal Functions                                                                                                           *
 *********************************************************************************************************************************/
 RT_C_DECLS_BEGIN
-#if defined(RT_ARCH_X86) && (defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD))
+#if defined(RT_ARCH_X86) && (defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD))
 extern uint64_t __udivdi3(uint64_t, uint64_t);
 extern uint64_t __umoddi3(uint64_t, uint64_t);
 #endif
@@ -138,7 +138,7 @@ PFNRT g_VMMR0Deps[] =
 {
     (PFNRT)RTCrc32,
     (PFNRT)RTOnce,
-#if defined(RT_ARCH_X86) && (defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD))
+#if defined(RT_ARCH_X86) && (defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD))
     (PFNRT)__udivdi3,
     (PFNRT)__umoddi3,
 #endif
@@ -2284,4 +2284,3 @@ DECLEXPORT(void) RTCALL RTAssertMsg2Weak
      */
     RTAssertMsg2V(pszFormat, va);
 }
-
