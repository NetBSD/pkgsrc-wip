$NetBSD$

--- base/sys_info_posix.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/sys_info_posix.cc
@@ -77,7 +77,7 @@ base::LazyInstance<
 
 namespace base {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_OPENBSD) && !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 int SysInfo::NumberOfProcessors() {
   return g_lazy_number_of_processors.Get().value();
 }
