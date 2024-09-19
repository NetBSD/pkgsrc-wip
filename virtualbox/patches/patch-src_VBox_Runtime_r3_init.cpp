$NetBSD$

--- src/VBox/Runtime/r3/init.cpp.orig	2016-03-04 19:30:02.000000000 +0000
+++ src/VBox/Runtime/r3/init.cpp
@@ -143,7 +143,7 @@ RTDATADECL(bool) g_fRTAlignmentChecks = 
 
 
 #if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_HAIKU) \
- || defined(RT_OS_LINUX)  || defined(RT_OS_OS2)     || defined(RT_OS_SOLARIS) /** @todo add host init hooks everywhere. */
+ || defined(RT_OS_LINUX)  || defined(RT_OS_OS2)     || defined(RT_OS_SOLARIS) || defined(RT_OS_NETBSD) /** @todo add host init hooks everywhere. */
 /* Stubs */
 DECLHIDDEN(int)  rtR3InitNativeFirst(uint32_t fFlags) { return VINF_SUCCESS; }
 DECLHIDDEN(int)  rtR3InitNativeFinal(uint32_t fFlags) { return VINF_SUCCESS; }
@@ -663,4 +663,3 @@ RTR3DECL(void) RTR3Term(void)
 {
 }
 #endif
-
