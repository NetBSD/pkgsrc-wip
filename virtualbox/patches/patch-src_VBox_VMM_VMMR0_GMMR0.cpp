$NetBSD$

--- src/VBox/VMM/VMMR0/GMMR0.cpp.orig	2016-03-04 19:30:11.000000000 +0000
+++ src/VBox/VMM/VMMR0/GMMR0.cpp
@@ -809,7 +809,7 @@ GMMR0DECL(int) GMMR0Init(void)
             else
                 SUPR0Printf("GMMR0Init: RTR0MemObjAllocPhysNC(,64K,Any) -> %d!\n", rc);
 #else
-# if defined(RT_OS_WINDOWS) || (defined(RT_OS_SOLARIS) && ARCH_BITS == 64) || defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
+# if defined(RT_OS_WINDOWS) || (defined(RT_OS_SOLARIS) && ARCH_BITS == 64) || defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
             pGMM->fLegacyAllocationMode = false;
 #  if ARCH_BITS == 32
             /* Don't reuse possibly partial chunks because of the virtual
@@ -5472,4 +5472,3 @@ GMMR0DECL(int) GMMR0ResetStatisticsReq(P
 
     return GMMR0ResetStatistics(&pReq->Stats, pReq->pSession, pVM);
 }
-
