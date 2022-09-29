$NetBSD$

get Memory for NetBSD

--- Modules/about-distro/src/MemoryEntry.cpp.orig	2022-09-20 21:37:31.837549485 +0000
+++ Modules/about-distro/src/MemoryEntry.cpp
@@ -9,7 +9,7 @@
 
 #ifdef Q_OS_LINUX
 #include <sys/sysinfo.h>
-#elif defined(Q_OS_FREEBSD)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 // clang-format off
 #include <sys/types.h>
 #include <sys/sysctl.h>
@@ -38,6 +38,15 @@ qlonglong MemoryEntry::calculateTotalRam
     sysctlbyname("hw.physmem", &memory, &len, NULL, 0);
 
     ret = memory;
+#elif defined(Q_OS_NETBSD)
+    /* Stuff for sysctl */
+    size_t len;
+
+    unsigned long memory;
+    len = sizeof(memory);
+    sysctlbyname("hw.physmem64", &memory, &len, NULL, 0);
+
+    ret = memory;
 #endif
     return ret;
 }
