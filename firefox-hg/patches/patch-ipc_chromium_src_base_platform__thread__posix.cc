$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.4 2015/01/29 11:43:22 thomasklausner Exp $

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2015-01-29 11:02:17.000000000 +0000
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -9,8 +9,12 @@
 
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
+#include <dlfcn.h>
+#include <string>
 #elif defined(OS_NETBSD)
+_Pragma("GCC visibility push(default)")
 #include <lwp.h>
+_Pragma("GCC visibility pop")
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <sys/prctl.h>
