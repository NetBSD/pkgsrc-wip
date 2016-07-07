$NetBSD$

--- src/VBox/Main/src-server/MachineImpl.cpp.orig	2016-03-04 19:29:40.000000000 +0000
+++ src/VBox/Main/src-server/MachineImpl.cpp
@@ -2021,7 +2021,7 @@ HRESULT Machine::getMemoryBalloonSize(UL
 HRESULT Machine::setMemoryBalloonSize(ULONG aMemoryBalloonSize)
 {
     /* This must match GMMR0Init; currently we only support memory ballooning on all 64-bit hosts except Mac OS X */
-#if HC_ARCH_BITS == 64 && (defined(RT_OS_WINDOWS) || defined(RT_OS_SOLARIS) || defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD))
+#if HC_ARCH_BITS == 64 && (defined(RT_OS_WINDOWS) || defined(RT_OS_SOLARIS) || defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD))
     /* check limits */
     if (aMemoryBalloonSize >= VMMDEV_MAX_MEMORY_BALLOON(mHWData->mMemorySize))
         return setError(E_INVALIDARG,
