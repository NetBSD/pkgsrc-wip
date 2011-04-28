$NetBSD: patch-base_sys__info__linux.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/sys_info_linux.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/sys_info_linux.cc
@@ -10,7 +10,11 @@
 namespace base {
 
 int64 SysInfo::AmountOfPhysicalMemory() {
+#ifdef _SC_PHYS_PAGES
   long pages = sysconf(_SC_PHYS_PAGES);
+#else
+  long pages = -1;
+#endif
   long page_size = sysconf(_SC_PAGE_SIZE);
   if (pages == -1 || page_size == -1) {
     NOTREACHED();
