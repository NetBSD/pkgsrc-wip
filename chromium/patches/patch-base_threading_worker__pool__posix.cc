$NetBSD: patch-base_threading_worker__pool__posix.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/threading/worker_pool_posix.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/threading/worker_pool_posix.cc
@@ -19,7 +19,7 @@ namespace {
 const int kIdleSecondsBeforeExit = 10 * 60;
 // A stack size of 64 KB is too small for the CERT_PKIXVerifyCert
 // function of NSS because of NSS bug 439169.
-const int kWorkerThreadStackSize = 128 * 1024;
+const int kWorkerThreadStackSize = 256 * 1024;
 
 class WorkerPoolImpl {
  public:
