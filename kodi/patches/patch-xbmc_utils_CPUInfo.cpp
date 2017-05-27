$NetBSD: patch-xbmc_utils_CPUInfo.cpp,v 1.4 2015/11/18 23:27:23 jmcneill Exp $

--- xbmc/utils/CPUInfo.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/utils/CPUInfo.cpp
@@ -37,7 +37,7 @@
 #include "linux/LinuxResourceCounter.h"
 #endif
 
-#if defined(TARGET_FREEBSD)
+#if defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #include <sys/resource.h>
@@ -237,7 +237,7 @@ CCPUInfo::CCPUInfo(void)
   }
   else
     m_cpuQueryLoad = nullptr;
-#elif defined(TARGET_FREEBSD)
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
   size_t len;
   int i;
   char cpumodel[512];
@@ -564,6 +564,12 @@ float CCPUInfo::getCPUFrequency()
   if (sysctlbyname("dev.cpu.0.freq", &hz, &len, NULL, 0) != 0)
     hz = 0;
   return (float)hz;
+#elif defined(TARGET_NETBSD)
+  int hz = 0;
+  size_t len = sizeof(hz);
+  if (sysctlbyname("machdep.cpu.frequency.current", &hz, &len, NULL, 0) != 0)
+    hz = 0;
+  return (float)hz;
 #else
   int value = 0;
   if (m_fCPUFreq && !m_cpuInfoForFreq)
@@ -725,7 +731,8 @@ bool CCPUInfo::readProcStat(unsigned lon
   else
     for (std::map<int, CoreInfo>::iterator it = m_cores.begin(); it != m_cores.end(); ++it)
       it->second.m_fPct = double(m_lastUsedPercentage); // use CPU average as fallback
-#elif defined(TARGET_FREEBSD)
+#elif defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
+#if defined(TARGET_FREEBSD)
   long *cptimes;
   size_t len;
   int i;
@@ -741,6 +748,19 @@ bool CCPUInfo::readProcStat(unsigned lon
     free(cptimes);
     return false;
   }
+#elif defined(TARGET_NETBSD)
+  uint64_t *cptimes;
+  size_t len;
+  int i;
+
+  len = sizeof(*cptimes) * m_cpuCount * CPUSTATES;
+  cptimes = (uint64_t*)malloc(len);
+  if (sysctlbyname("kern.cp_time", cptimes, &len, NULL, 0) != 0)
+  {
+    free(cptimes);
+    return false;
+  }
+#endif
   user = 0;
   nice = 0;
   system = 0;
@@ -748,7 +768,11 @@ bool CCPUInfo::readProcStat(unsigned lon
   io = 0;
   for (i = 0; i < m_cpuCount; i++)
   {
+#if defined(TARGET_NETBSD)
+    int64_t coreUser, coreNice, coreSystem, coreIdle, coreIO;
+#else
     long coreUser, coreNice, coreSystem, coreIdle, coreIO;
+#endif
     double total;
 
     coreUser   = cptimes[i * CPUSTATES + CP_USER];
@@ -767,7 +791,9 @@ bool CCPUInfo::readProcStat(unsigned lon
       coreIO -= iter->second.m_io;
 
       total = (double)(coreUser + coreNice + coreSystem + coreIdle + coreIO);
-      if(total != 0.0f)
+      if(total == 0.0f)
+        iter->second.m_fPct = 0.0f;
+      else
         iter->second.m_fPct = ((double)(coreUser + coreNice + coreSystem) * 100.0) / total;
 
       iter->second.m_user += coreUser;
@@ -957,6 +983,18 @@ bool CCPUInfo::HasNeon()
 #elif defined(TARGET_DARWIN_IOS)
   has_neon = 1;
 
+#elif defined(TARGET_NETBSD) && defined(__ARM_NEON__)
+  if (has_neon == -1)
+  {
+    has_neon = 0;
+    int flag;
+    size_t len = sizeof(flag);
+    if (sysctlbyname("machdep.neon_present", &flag, &len, NULL, 0) == 0)
+    {
+      has_neon = 1;
+    }
+  }
+
 #elif defined(TARGET_LINUX) && defined(__ARM_NEON__)
   if (has_neon == -1)
   {
