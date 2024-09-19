$NetBSD$

--- env/env_test.cc.orig	2018-01-03 02:56:50.000000000 +0000
+++ env/env_test.cc
@@ -1137,7 +1137,7 @@ TEST_P(EnvPosixTestWithParam, Preallocat
     unique_ptr<WritableFile> srcfile;
     EnvOptions soptions;
     soptions.use_direct_reads = soptions.use_direct_writes = direct_io_;
-#if !defined(OS_MACOSX) && !defined(OS_WIN) && !defined(OS_SOLARIS) && !defined(OS_AIX) && !defined(OS_OPENBSD)
+#if !defined(OS_MACOSX) && !defined(OS_WIN) && !defined(OS_SOLARIS) && !defined(OS_AIX) && !defined(OS_OPENBSD) && !defined(OS_NETBSD)
     if (soptions.use_direct_writes) {
       rocksdb::SyncPoint::GetInstance()->SetCallBack(
           "NewWritableFile:O_DIRECT", [&](void* arg) {
@@ -1199,7 +1199,7 @@ TEST_P(EnvPosixTestWithParam, Consistent
       oss << test::TmpDir(env_) << "/testfile_" << i;
       const std::string path = oss.str();
       unique_ptr<WritableFile> file;
-#if !defined(OS_MACOSX) && !defined(OS_WIN) && !defined(OS_SOLARIS) && !defined(OS_AIX) && !defined(OS_OPENBSD)
+#if !defined(OS_MACOSX) && !defined(OS_WIN) && !defined(OS_SOLARIS) && !defined(OS_AIX) && !defined(OS_OPENBSD) && !defined(OS_NETBSD)
       if (soptions.use_direct_writes) {
         rocksdb::SyncPoint::GetInstance()->SetCallBack(
             "NewWritableFile:O_DIRECT", [&](void* arg) {
