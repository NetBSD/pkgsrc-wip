$NetBSD$

--- src/sysinfo.cc.orig	2017-11-03 17:00:29.000000000 +0000
+++ src/sysinfo.cc
@@ -25,7 +25,7 @@
 #include <sys/time.h>
 #include <sys/types.h>  // this header must be included before 'sys/sysctl.h' to avoid compilation error on FreeBSD
 #include <unistd.h>
-#if defined BENCHMARK_OS_FREEBSD || defined BENCHMARK_OS_MACOSX
+#if defined BENCHMARK_OS_FREEBSD || defined BENCHMARK_OS_MACOSX || defined BENCHMARK_OS_NETBSD
 #include <sys/sysctl.h>
 #endif
 #endif
@@ -230,7 +230,9 @@ void InitializeSystemInfo() {
     cpuinfo_num_cpus = num_cpus;
   }
 
-#elif defined BENCHMARK_OS_FREEBSD
+#elif defined BENCHMARK_OS_FREEBSD || defined BENCHMARK_OS_NETBSD
+// FreeBSD notes
+// =============
 // For this sysctl to work, the machine must be configured without
 // SMP, APIC, or APM support.  hz should be 64-bit in freebsd 7.0
 // and later.  Before that, it's a 32-bit quantity (and gives the
@@ -242,7 +244,7 @@ void InitializeSystemInfo() {
 // To FreeBSD 6.3 (it's the same in 6-STABLE):
 //  http://fxr.watson.org/fxr/source/i386/i386/tsc.c?v=RELENG6#L131
 //  139         error = sysctl_handle_int(oidp, &freq, sizeof(freq), req);
-#if __FreeBSD__ >= 7
+#if (__FreeBSD__ >= 7) || defined(__NetBSD__)
   uint64_t hz = 0;
 #else
   unsigned int hz = 0;
@@ -256,8 +258,16 @@ void InitializeSystemInfo() {
   } else {
     cpuinfo_cycles_per_second = hz;
   }
-// TODO: also figure out cpuinfo_num_cpus
 
+  int32_t num_cpus = 0;
+  size_t size = sizeof(num_cpus);
+  if (::sysctlbyname("hw.ncpu", &num_cpus, &size, nullptr, 0) == 0 &&
+      (size == sizeof(num_cpus))) {
+    cpuinfo_num_cpus = num_cpus;
+  } else {
+    fprintf(stderr, "%s\n", strerror(errno));
+    std::exit(EXIT_FAILURE);
+  }
 #elif defined BENCHMARK_OS_WINDOWS
   // In NT, read MHz from the registry. If we fail to do so or we're in win9x
   // then make a crude estimate.
