$NetBSD$

--- src/VBox/VMM/VMMR3/PGMPhys.cpp.orig	2016-03-04 19:30:12.000000000 +0000
+++ src/VBox/VMM/VMMR3/PGMPhys.cpp
@@ -926,7 +926,7 @@ static int pgmR3PhysFreePageRange(PVM pV
     return rc;
 }
 
-#if HC_ARCH_BITS == 64 && (defined(RT_OS_WINDOWS) || defined(RT_OS_SOLARIS) || defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD))
+#if HC_ARCH_BITS == 64 && (defined(RT_OS_WINDOWS) || defined(RT_OS_SOLARIS) || defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD))
 
 /**
  * Rendezvous callback used by PGMR3ChangeMemBalloon that changes the memory balloon size
@@ -1071,7 +1071,7 @@ static DECLCALLBACK(void) pgmR3PhysChang
     RTMemFree(paPhysPage);
 }
 
-#endif /* 64-bit host && (Windows || Solaris || Linux || FreeBSD) */
+#endif /* 64-bit host && (Windows || Solaris || Linux || FreeBSD || NetBSD) */
 
 /**
  * Inflate or deflate a memory balloon
@@ -1085,7 +1085,7 @@ static DECLCALLBACK(void) pgmR3PhysChang
 VMMR3DECL(int) PGMR3PhysChangeMemBalloon(PVM pVM, bool fInflate, unsigned cPages, RTGCPHYS *paPhysPage)
 {
     /* This must match GMMR0Init; currently we only support memory ballooning on all 64-bit hosts except Mac OS X */
-#if HC_ARCH_BITS == 64 && (defined(RT_OS_WINDOWS) || defined(RT_OS_SOLARIS) || defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD))
+#if HC_ARCH_BITS == 64 && (defined(RT_OS_WINDOWS) || defined(RT_OS_SOLARIS) || defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD))
     int rc;
 
     /* Older additions (ancient non-functioning balloon code) pass wrong physical addresses. */
@@ -4652,4 +4652,3 @@ VMMR3DECL(int) PGMR3PhysTlbGCPhys2Ptr(PV
     pgmUnlock(pVM);
     return rc;
 }
-
