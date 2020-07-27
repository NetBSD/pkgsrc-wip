$NetBSD$

--- base/system/sys_info.cc.orig	2020-07-08 21:40:31.000000000 +0000
+++ base/system/sys_info.cc
@@ -102,7 +102,7 @@ void SysInfo::GetHardwareInfo(base::Once
 #elif defined(OS_ANDROID) || defined(OS_MACOSX)
   base::ThreadPool::PostTaskAndReplyWithResult(
       FROM_HERE, {}, base::BindOnce(&GetHardwareInfoSync), std::move(callback));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   base::ThreadPool::PostTaskAndReplyWithResult(
       FROM_HERE, {base::MayBlock()}, base::BindOnce(&GetHardwareInfoSync),
       std::move(callback));
