$NetBSD$

--- base/process/process_info_linux.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/process/process_info_linux.cc
@@ -11,10 +11,61 @@
 #include "base/process/process_handle.h"
 #include "base/time/time.h"
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif
+
 namespace base {
 
 // static
 const Time CurrentProcessInfo::CreationTime() {
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, getpid() };
+  struct kinfo_proc proc;
+  size_t len = sizeof(struct kinfo_proc);
+  if (sysctl(mib, arraysize(mib), &proc, &len, NULL, 0) < 0)
+    return Time();
+#if defined(__DragonFly__)
+  return Time::FromTimeVal(proc.kp_start);
+#else
+  return Time::FromTimeVal(proc.ki_start);
+#endif
+#elif defined(__NetBSD__)
+  struct kinfo_proc2 kproc;
+  size_t esize = sizeof(kinfo_proc2);
+  size_t size;
+  int st;
+  int mib[6];
+  struct timeval tv;
+
+  tv.tv_sec = 0;
+  tv.tv_usec = 0;
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC2;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = getpid();
+  mib[4] = esize;
+  mib[5] = 0;
+
+  st = sysctl(mib, 6, NULL, &size, NULL, (size_t)0);
+  if (st == -1) {
+      return Time::FromTimeVal(tv);
+  }
+
+  mib[5] = (int)(size / esize);
+  st = sysctl(mib, 6, &kproc, &size, NULL, (size_t)0);
+  if (st == -1) {
+      return Time::FromTimeVal(tv);
+  }
+
+  tv.tv_sec = kproc.p_ustart_sec;
+  tv.tv_usec = kproc.p_ustart_usec;
+
+  return Time::FromTimeVal(tv);
+#else
   ProcessHandle pid = GetCurrentProcessHandle();
   int64_t start_ticks =
       internal::ReadProcStatsAndGetFieldAsInt64(pid, internal::VM_STARTTIME);
@@ -23,6 +74,7 @@ const Time CurrentProcessInfo::CreationT
   Time boot_time = internal::GetBootTime();
   DCHECK(!boot_time.is_null());
   return Time(boot_time + start_offset);
+#endif
 }
 
 }  // namespace base
