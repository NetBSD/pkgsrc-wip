$NetBSD$

https://gn-review.googlesource.com/c/gn/+/9700

--- tools/gn/src/util/exe_path.cc.orig	2020-06-25 09:40:29.000000000 +0000
+++ tools/gn/src/util/exe_path.cc
@@ -15,7 +15,7 @@
 #include <windows.h>
 
 #include "base/win/win_util.h"
-#elif defined(OS_FREEBSD)
+#elif defined(OS_FREEBSD) || defined(OS_NETBSD)
 #include <limits.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
@@ -67,6 +67,18 @@ base::FilePath GetExePath() {
   return base::FilePath(buf);
 }
 
+#elif defined(OS_NETBSD)
+
+base::FilePath GetExePath() {
+  int mib[] = {CTL_KERN, KERN_PROC_ARGS, getpid(), KERN_PROC_PATHNAME};
+  char buf[PATH_MAX];
+  size_t buf_size = PATH_MAX;
+  if (sysctl(mib, 4, buf, &buf_size, nullptr, 0) == -1) {
+    return base::FilePath();
+  }
+  return base::FilePath(buf);
+}
+
 #elif defined(OS_HAIKU)
 
 base::FilePath GetExePath() {
