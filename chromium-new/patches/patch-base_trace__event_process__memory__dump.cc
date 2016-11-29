$NetBSD$

--- base/trace_event/process_memory_dump.cc.orig	2016-11-10 20:02:09.000000000 +0000
+++ base/trace_event/process_memory_dump.cc
@@ -89,7 +89,7 @@ size_t ProcessMemoryDump::CountResidentB
   const size_t kMaxChunkSize = 8 * 1024 * 1024;
   size_t max_vec_size =
       GetSystemPageCount(std::min(mapped_size, kMaxChunkSize), page_size);
-#if defined(OS_MACOSX) || defined(OS_IOS)
+#if defined(OS_MACOSX) || defined(OS_IOS) || defined(OS_BSD)
   std::unique_ptr<char[]> vec(new char[max_vec_size]);
 #elif defined(OS_WIN)
   std::unique_ptr<PSAPI_WORKING_SET_EX_INFORMATION[]> vec(
