$NetBSD$

* Set the expected arch on NetBSD

--- src/util/sys_info.cc.orig	2026-11-10 09:12:19.540943504 +0000
+++ src/util/sys_info.cc
@@ -12,6 +12,10 @@
 #include <unistd.h>
 #endif
 
+#if defined(OS_NETBSD)
+#include <sys/sysctl.h>
+#endif
+
 #if defined(OS_MACOSX)
 #include <sys/sysctl.h>
 #include <sys/types.h>
@@ -71,6 +75,23 @@ std::string OperatingSystemArchitecture(
   }
   std::string arch(info.machine);
   std::string os(info.sysname);
+#if defined(OS_NETBSD)
+  char machine_arch[SYS_NMLN];
+  int mib[2] = { CTL_HW, HW_MACHINE_ARCH };
+  size_t len = sizeof(machine_arch);
+  if (sysctl(mib, sizeof(mib) / sizeof(mib[0]), machine_arch, &len, NULL, 0) == 0) {
+    arch = machine_arch;
+  }
+  if (arch.compare(0, 4, "earm") == 0) {
+    arch = "arm";
+  } else if (arch == "aarch64eb") {
+    arch = "aarch64";
+  } else if (arch.compare(0, 6, "mips64") == 0) {
+    arch = "mips64";
+  } else if (arch.compare(0, 5, "mipse") == 0) {
+    arch = "mips";
+  }
+#endif
   if (arch == "i386" || arch == "i486" || arch == "i586" || arch == "i686") {
     arch = "x86";
   } else if (arch == "i86pc") {
