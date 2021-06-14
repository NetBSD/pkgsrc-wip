$NetBSD: patch-src_hotspot_os_bsd_os__perf__bsd.cpp,v 1.2 2019/11/03 00:37:28 tnn Exp $

KERN_PROC_PATHNAME is available from NetBSD>=7.99.23

--- src/hotspot/os/bsd/os_perf_bsd.cpp.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/hotspot/os/bsd/os_perf_bsd.cpp	2021-06-10 13:29:48.393031130 -0400
@@ -33,6 +33,12 @@
   #import <libproc.h>
   #include <mach/mach.h>
   #include <mach/task_info.h>
+#elif defined(__NetBSD__)
+  #include <sched.h>
+  #include <sys/resource.h>
+  #include <uvm/uvm_extern.h>
+  #define NET_RT_IFLIST2 NET_RT_IFLIST
+  #define RTM_IFINFO2    RTM_IFINFO
 #else
   #include <sys/user.h>
   #include <sys/sched.h>
@@ -40,9 +46,6 @@
   #define NET_RT_IFLIST2 NET_RT_IFLIST
   #define RTM_IFINFO2    RTM_IFINFO
 #endif
-#ifdef __NetBSD__
-  #include <uvm/uvm_extern.h>
-#endif
 #include <sys/time.h>
 #include <sys/sysctl.h>
 #include <sys/socket.h>
@@ -856,6 +859,9 @@
 
   for (int i = 0; i < pid_count; i++) {
     // Executable path
+#if !defined(KERN_PROC_PATHNAME)
+#define KERN_PROC_PATHNAME 5
+#endif
     int pmib[] = { CTL_KERN, KERN_PROC_ARGS, lproc[i].p_pid, KERN_PROC_PATHNAME };
     const u_int pmiblen = sizeof(pmib) / sizeof(pmib[0]);
     char pbuf[PATH_MAX];
