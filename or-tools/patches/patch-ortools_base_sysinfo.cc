$NetBSD$

https://github.com/google/or-tools/issues/4359

--- ortools/base/sysinfo.cc.orig	2024-08-27 13:35:44.000000000 +0000
+++ ortools/base/sysinfo.cc
@@ -17,7 +17,7 @@
 #if defined(__APPLE__) && defined(__GNUC__)  // MacOS
 #include <mach/mach_init.h>
 #include <mach/task.h>
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__))  // FreeBSD or OpenBSD
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__)) || defined(__NetBSD__)  // FreeBSD or OpenBSD or NetBSD
 #include <sys/resource.h>
 #include <sys/time.h>
 // Windows
@@ -48,7 +48,7 @@ int64_t GetProcessMemoryUsage() {
   int64_t resident_memory = t_info.resident_size;
   return resident_memory;
 }
-#elif defined(__GNUC__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && \
+#elif defined(__GNUC__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && \
     !defined(__EMSCRIPTEN__) && !defined(_WIN32)      // Linux
 int64_t GetProcessMemoryUsage() {
   unsigned size = 0;
@@ -61,7 +61,7 @@ int64_t GetProcessMemoryUsage() {
   fclose(pf);
   return int64_t{1024} * size;
 }
-#elif (defined(__FreeBSD__) || defined(__OpenBSD__))  // FreeBSD or OpenBSD
+#elif (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__))  // FreeBSD or OpenBSD or NetBSD
 int64_t GetProcessMemoryUsage() {
   int who = RUSAGE_SELF;
   struct rusage rusage;
