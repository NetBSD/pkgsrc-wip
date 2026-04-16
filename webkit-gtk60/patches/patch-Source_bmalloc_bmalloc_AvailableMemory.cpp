$NetBSD$

--- Source/bmalloc/bmalloc/AvailableMemory.cpp.orig	2024-08-19 06:28:40.235246200 +0000
+++ Source/bmalloc/bmalloc/AvailableMemory.cpp
@@ -44,18 +44,25 @@
 #import <mach/mach_error.h>
 #import <math.h>
 #elif BOS(UNIX)
-#if BOS(FREEBSD) || BOS(LINUX)
+#if BOS(NETBSD)
+#include <kvm.h>
+#elif BOS(FREEBSD) || BOS(LINUX)
 #include <sys/sysinfo.h>
 #endif
 #if BOS(LINUX)
 #include <algorithm>
 #include <fcntl.h>
-#elif BOS(FREEBSD)
+#elif BOS(FREEBSD) || BOS(NETBSD)
 #include "VMAllocate.h"
 #include <sys/sysctl.h>
 #include <sys/types.h>
+#if BOS(FREEBSD)
 #include <sys/user.h>
 #endif
+#if BOS(NETBSD)
+#include <uvm/uvm_extern.h>
+#endif
+#endif
 #include <unistd.h>
 #endif
 
@@ -166,6 +173,24 @@ static size_t computeAvailableMemory()
     if (!sysinfo(&info))
         return info.totalram * info.mem_unit;
     return availableMemoryGuess;
+#elif BOS(NETBSD)
+    struct uvmexp uvmexp;
+    size_t length;
+    static int uvmexp_mib  [] = { CTL_VM, VM_UVMEXP };
+    long pages;
+    long pageSize = sysconf(_SC_PAGE_SIZE);
+    if (pageSize == -1)
+        return availableMemoryGuess;
+    length = sizeof (uvmexp);
+    if (sysctl(uvmexp_mib, std::size(uvmexp_mib), &uvmexp, &length, NULL, 0) == 0)
+        return uvmexp.npages * pageSize;
+    else {
+        bzero(&uvmexp, sizeof(length));
+        pages = sysconf(_SC_PHYS_PAGES);
+        if (pages == -1)
+            return availableMemoryGuess;
+        return pages * pageSize;
+    }
 #elif BOS(UNIX)
     long pages = sysconf(_SC_PHYS_PAGES);
     long pageSize = sysconf(_SC_PAGE_SIZE);
@@ -180,14 +205,19 @@ static size_t computeAvailableMemory()
 size_t availableMemory()
 {
     static size_t availableMemory;
+#if BOS(NETBSD)
+    // We always calculate the available memory because we take care...
+    availableMemory = computeAvailableMemory();
+#else
     static std::once_flag onceFlag;
     std::call_once(onceFlag, [] {
         availableMemory = computeAvailableMemory();
     });
+#endif
     return availableMemory;
 }
 
-#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD)
+#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD) || BOS(NETBSD)
 MemoryStatus memoryStatus()
 {
 #if BPLATFORM(IOS_FAMILY)
@@ -213,6 +243,22 @@ MemoryStatus memoryStatus()
     size_t memoryFootprint = 0;
     if (!sysctl(mib, 4, &info, &infolen, nullptr, 0))
         memoryFootprint = static_cast<size_t>(info.ki_rssize) * vmPageSize();
+#elif BOS(NETBSD)
+    size_t memoryFootprint = 0, length;
+    struct kinfo_proc2 *info;
+    int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid(), sizeof(struct kinfo_proc2), 0 };
+
+    if (sysctl(mib, std::size(mib), NULL, &length, NULL, 0) == 0) {
+        info = (struct kinfo_proc2 *)malloc(length);
+        mib[5] = (length / sizeof(struct kinfo_proc2));
+        if (sysctl(mib, std::size(mib), info, &length, NULL, 0) == 0) {
+            memoryFootprint = static_cast<size_t>(
+                               info->p_vm_tsize +
+                               info->p_vm_dsize +
+                               info->p_vm_ssize) * vmPageSize();
+        }
+        free(info);
+    }
 #endif
 
     double percentInUse = static_cast<double>(memoryFootprint) / static_cast<double>(availableMemory());
