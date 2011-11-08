$NetBSD: patch-cpp_src_fuse_fuse__adapter.cpp,v 1.1 2011/11/08 03:11:32 tnn2 Exp $

--- cpp/src/fuse/fuse_adapter.cpp.orig	2011-11-03 10:51:07.000000000 +0000
+++ cpp/src/fuse/fuse_adapter.cpp
@@ -376,7 +376,7 @@ void FuseAdapter::ConvertXtreemFSStatToF
   fuse_stat->st_mtim.tv_nsec = xtreemfs_stat.mtime_ns() % 1000000000;
   fuse_stat->st_ctim.tv_sec  = xtreemfs_stat.ctime_ns() / 1000000000;
   fuse_stat->st_ctim.tv_nsec = xtreemfs_stat.ctime_ns() % 1000000000;
-#elif __APPLE__
+#elif defined(__APPLE__) || defined(__NetBSD__)
   fuse_stat->st_atimespec.tv_sec  = xtreemfs_stat.atime_ns() / 1000000000;
   fuse_stat->st_atimespec.tv_nsec = xtreemfs_stat.atime_ns() % 1000000000;
   fuse_stat->st_mtimespec.tv_sec  = xtreemfs_stat.mtime_ns() / 1000000000;
@@ -403,7 +403,7 @@ xtreemfs::pbrpc::SYSTEM_V_FCNTL FuseAdap
   CHECK(result, flags, O_CREAT    , SYSTEM_V_FCNTL_H_O_CREAT);
   CHECK(result, flags, O_TRUNC    , SYSTEM_V_FCNTL_H_O_TRUNC);
   CHECK(result, flags, O_EXCL     , SYSTEM_V_FCNTL_H_O_EXCL);
-#ifdef __linux
+#if defined(__linux) || defined(__NetBSD__)
   CHECK(result, flags, O_DSYNC    , SYSTEM_V_FCNTL_H_O_SYNC);
 #endif
 
