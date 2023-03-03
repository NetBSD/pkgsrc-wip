$NetBSD$

Proper method of determining the CPU count.
--- src/libs/tgf/linuxspec.cpp.orig	2022-07-28 17:54:11.723581581 -0700
+++ src/libs/tgf/linuxspec.cpp	2022-07-28 18:07:31.952939532 -0700
@@ -635,23 +635,19 @@
 		// MacOS X, FreeBSD, OpenBSD, NetBSD, etc ...
 #if (defined(__APPLE__) && !defined(USE_MACPORTS)) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 		
-		nt mib[4];
+		int mib[4];
 		size_t len; 
 		
 		// Set the mib for hw.ncpu
 		
 		// Get the number of CPUs from the system
-		// 1) Try HW_AVAILCPU first.
 		mib[0] = CTL_HW;
-		mib[1] = HW_AVAILCPU;  // alternatively, try HW_NCPU;
-		sysctl(mib, 2, &nCPUs, &len, NULL, 0);
-		
-		if (nCPUs < 1) 
-		{
-			// 2) Try alternatively HW_NCPU.
+#if defined(__NetBSD__)
 			mib[1] = HW_NCPU;
+#else
+		mib[1] = HW_AVAILCPU;
+#endif
 			sysctl(mib, 2, &nCPUs, &len, NULL, 0);
-		}
 		
 		// Linux, Solaris, AIX
 #elif defined(linux) || defined(__linux__) || defined(USE_MACPORTS)
@@ -693,7 +689,7 @@
 * Remarks
 *    
 */
-#if !defined(USE_MACPORTS) && !defined(__HAIKU__)
+#if !defined(USE_MACPORTS) && !defined(__HAIKU__) && !defined(__NetBSD__)
 std::string cpuSet2String(const cpu_set_t* pCPUSet)
 {
 	std::ostringstream ossCPUSet;
