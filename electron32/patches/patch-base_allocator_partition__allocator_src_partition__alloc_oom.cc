$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- base/allocator/partition_allocator/src/partition_alloc/oom.cc.orig	2024-10-18 12:33:59.714303700 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/oom.cc
@@ -28,21 +28,47 @@ namespace internal {
 // partition_alloc::internal::base::internal::OnNoMemoryInternal
 PA_NOINLINE void OnNoMemoryInternal(size_t size) {
   g_oom_size = size;
+  size_t tmp_size = size;
+  internal::base::debug::Alias(&tmp_size);
+
 #if PA_BUILDFLAG(IS_WIN)
+  // Create an exception vector with:
+  // [0] the size of the allocation, in bytes
+  // [1] "current committed memory limit for the system or the current process,
+  //     whichever is smaller, in bytes"
+  // [2] "maximum amount of memory the current process can commit, in bytes"
+  //
+  // Citations from
+  // https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/ns-sysinfoapi-memorystatusex
+  //
+  // System commit constraints (which may be different from the process commit
+  // constraints) are in the stability_report.SystemMemoryState.WindowsMemory
+  // proto attached to crash reports.
+  //
+  // Note: Both the process commit constraints in the exception vector and the
+  // system commit constraints in the proto are collected *after* the OOM and
+  // may therefore not reflect the state at the time of the OOM (e.g. another
+  // process may have exited or the page file may have been resized).
+  constexpr size_t kInvalid = std::numeric_limits<ULONG_PTR>::max();
+  ULONG_PTR exception_args[] = {size, kInvalid, kInvalid};
+
+  MEMORYSTATUSEX memory_status = {};
+  memory_status.dwLength = sizeof(memory_status);
+  if (::GlobalMemoryStatusEx(&memory_status) != 0) {
+    exception_args[1] = memory_status.ullTotalPageFile;
+    exception_args[2] = memory_status.ullAvailPageFile;
+  }
+  internal::base::debug::Alias(&memory_status);
+
   // Kill the process. This is important for security since most of code
   // does not check the result of memory allocation.
-  // https://msdn.microsoft.com/en-us/library/het71c37.aspx
-  // Pass the size of the failed request in an exception argument.
-  ULONG_PTR exception_args[] = {size};
+  // Documentation: https://msdn.microsoft.com/en-us/library/het71c37.aspx
   ::RaiseException(win::kOomExceptionCode, EXCEPTION_NONCONTINUABLE,
                    std::size(exception_args), exception_args);
 
   // Safety check, make sure process exits here.
   _exit(win::kOomExceptionCode);
 #else
-  size_t tmp_size = size;
-  internal::base::debug::Alias(&tmp_size);
-
   // Note: Don't add anything that may allocate here. Depending on the
   // allocator, this may be called from within the allocator (e.g. with
   // PartitionAlloc), and would deadlock as our locks are not recursive.
