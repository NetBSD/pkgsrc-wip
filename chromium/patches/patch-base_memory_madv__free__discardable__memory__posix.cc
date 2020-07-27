$NetBSD$

--- base/memory/madv_free_discardable_memory_posix.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ base/memory/madv_free_discardable_memory_posix.cc
@@ -292,7 +292,7 @@ void MadvFreeDiscardableMemoryPosix::Set
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
-#ifdef OS_MACOSX
+#if defined(OS_MACOSX) || defined(OS_BSD)
   std::vector<char> vec(allocated_pages_);
 #else
   std::vector<unsigned char> vec(allocated_pages_);
