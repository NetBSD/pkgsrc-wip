$NetBSD$

Correctly detect total RAM for NetBSD, OpenBSD too.

--- krita/image/kis_image_config.cpp.orig	2015-11-02 13:52:01.000000000 +0000
+++ krita/image/kis_image_config.cpp
@@ -224,7 +224,7 @@ void KisImageConfig::setSwapDir(const QS
 
 #if defined Q_OS_LINUX
 #include <sys/sysinfo.h>
-#elif defined Q_OS_FREEBSD
+#elif defined Q_OS_FREEBSD || defined Q_OS_NETBSD || defined Q_OS_OPENBSD
 #include <sys/sysctl.h>
 #elif defined Q_OS_WIN
 #include <windows.h>
@@ -248,9 +248,13 @@ int KisImageConfig::totalRAM()
     if(!error) {
         totalMemory = info.totalram * info.mem_unit / (1UL << 20);
     }
-#elif defined Q_OS_FREEBSD
+#elif defined Q_OS_FREEBSD || defined Q_OS_NETBSD || defined Q_OS_OPENBSD
     u_long physmem;
+#   if defined HW_PHYSMEM64
+    int mib[] = {CTL_HW, HW_PHYSMEM64};
+#   else
     int mib[] = {CTL_HW, HW_PHYSMEM};
+#   endif
     size_t len = sizeof(physmem);
 
     error = sysctl(mib, 2, &physmem, &len, NULL, 0);
