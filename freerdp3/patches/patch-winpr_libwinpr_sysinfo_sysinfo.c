$NetBSD: patch-winpr_libwinpr_sysinfo_sysinfo.c,v 1.2 2021/05/02 08:26:49 jdolecek Exp $

Use _SC_NPROCESSORS_ONLN if available, remove OS-specific ifdef for it,
and also for HW_NCPU. Technically NetBSD would need to be added to the HW_NCPU
#idef, but no longer needed since it has _SC_NPROCESSORS_ONLN.

--- winpr/libwinpr/sysinfo/sysinfo.c.orig	2025-12-05 08:17:55.000000000 +0000
+++ winpr/libwinpr/sysinfo/sysinfo.c
@@ -37,7 +37,7 @@
 #if !defined(_WIN32)
 #if defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 199309L)
 #include <time.h>
-#elif !defined(__APPLE__)
+#elif !defined(__APPLE__) && !defined(__NetBSD__)
 #include <sys/time.h>
 #include <sys/sysinfo.h>
 #endif
@@ -167,7 +167,7 @@ static DWORD GetNumberOfProcessors(void)
 #if defined(ANDROID)
 	return android_getCpuCount();
 	/* TODO: iOS */
-#elif defined(__linux__) || defined(__sun) || defined(_AIX)
+#elif defined(_SC_NPROCESSORS_ONLN)
 	numCPUs = (DWORD)sysconf(_SC_NPROCESSORS_ONLN);
 #elif defined(__MACOSX__) || defined(__FreeBSD__) || defined(__NetBSD__) || \
     defined(__OpenBSD__) || defined(__DragonFly__)
@@ -175,7 +175,7 @@ static DWORD GetNumberOfProcessors(void)
 		int mib[4];
 		size_t length = sizeof(numCPUs);
 		mib[0] = CTL_HW;
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(HW_NCPU)
 		mib[1] = HW_NCPU;
 #else
 		mib[1] = HW_AVAILCPU;
