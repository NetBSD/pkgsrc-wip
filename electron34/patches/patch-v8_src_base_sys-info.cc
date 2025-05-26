$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/src/base/sys-info.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ v8/src/base/sys-info.cc
@@ -35,8 +35,12 @@ namespace base {
 
 // static
 int SysInfo::NumberOfProcessors() {
+#if V8_OS_OPENBSD || V8_OS_NETBSD
 #if V8_OS_OPENBSD
+  int mib[2] = {CTL_HW, HW_NCPUONLINE};
+#else
   int mib[2] = {CTL_HW, HW_NCPU};
+#endif
   int ncpu = 0;
   size_t len = sizeof(ncpu);
   if (sysctl(mib, arraysize(mib), &ncpu, &len, nullptr, 0) != 0) {
