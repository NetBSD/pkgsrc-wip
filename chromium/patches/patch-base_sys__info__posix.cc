$NetBSD: patch-base_sys__info__posix.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/sys_info_posix.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/sys_info_posix.cc
@@ -23,7 +23,7 @@
 
 namespace base {
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 int SysInfo::NumberOfProcessors() {
   // It seems that sysconf returns the number of "logical" processors on both
   // Mac and Linux.  So we get the number of "online logical" processors.
