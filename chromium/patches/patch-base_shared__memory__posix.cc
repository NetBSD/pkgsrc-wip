$NetBSD: patch-base_shared__memory__posix.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/shared_memory_posix.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/shared_memory_posix.cc
@@ -149,7 +149,7 @@ bool SharedMemory::CreateNamed(const std
     created_size_ = size;
   }
   if (fp == NULL) {
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     PLOG(ERROR) << "Creating shared memory in " << path.value() << " failed";
     FilePath dir = path.DirName();
     if (access(dir.value().c_str(), W_OK | X_OK) < 0) {
