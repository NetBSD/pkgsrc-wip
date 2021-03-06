$NetBSD$

get Memory for NetBSD

--- Modules/about-distro/src/Module.cpp.orig	2020-05-05 14:39:33.000000000 +0000
+++ Modules/about-distro/src/Module.cpp
@@ -41,7 +41,7 @@
 
 #ifdef Q_OS_LINUX
 #include <sys/sysinfo.h>
-#elif defined(Q_OS_FREEBSD)
+#elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -66,6 +66,15 @@ static qlonglong calculateTotalRam()
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
