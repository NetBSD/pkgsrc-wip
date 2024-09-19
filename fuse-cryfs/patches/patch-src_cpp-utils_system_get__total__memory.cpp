$NetBSD$

Find total memory via sysctl for FreeBSD too. Add NetBSD case.
clean up a bit.

Linux case seems wrong.

--- src/cpp-utils/system/get_total_memory.cpp.orig	2017-02-11 12:34:50.000000000 +0000
+++ src/cpp-utils/system/get_total_memory.cpp
@@ -4,17 +4,25 @@
 #include <unistd.h>
 #include <stdexcept>
 
+#ifdef __APPLE__
+#define SYSCTL_MEMSIZE "hw.memsize"
+#elif __FreeBSD__
+#define SYSCTL_MEMSIZE "hw.physmem"
+#elif __NetBSD__
+#define SYSCTL_MEMSIZE "hw.physmem64"
+#endif
+
 namespace cpputils{
     namespace system {
         uint64_t get_total_memory() {
             uint64_t mem;
-#ifdef __APPLE__
+#ifdef SYSCTL_MEMSIZE
             size_t size = sizeof(mem);
-  int result = sysctlbyname("hw.memsize", &mem, &size, nullptr, 0);
+  int result = sysctlbyname(SYSCTL_MEMSIZE, &mem, &size, nullptr, 0);
   if (0 != result) {
     throw std::runtime_error("sysctlbyname syscall failed");
   }
-#elif __linux__ || __FreeBSD__
+#elif __linux__
             long numRAMPages = sysconf(_SC_PHYS_PAGES);
             long pageSize = sysconf(_SC_PAGESIZE);
             mem = numRAMPages * pageSize;
