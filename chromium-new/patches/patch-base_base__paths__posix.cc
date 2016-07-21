$NetBSD$

--- base/base_paths_posix.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/base_paths_posix.cc
@@ -24,9 +24,10 @@
 #include "base/process/process_metrics.h"
 #include "build/build_config.h"
 
-#if defined(OS_FREEBSD)
+#if defined(OS_FREEBSD) || defined(OS_NETBSD)
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#include <unistd.h>
 #elif defined(OS_SOLARIS)
 #include <stdlib.h>
 #endif
@@ -59,6 +60,30 @@ bool PathProviderPosix(int key, FilePath
       }
       *result = FilePath(FilePath::StringType(bin_dir, length - 1));
       return true;
+#elif defined(OS_NETBSD)
+      char pathname[MAXPATHLEN];
+      int mib[4];
+      int ret;
+      size_t size;
+
+      mib[0] = CTL_KERN;
+      mib[1] = KERN_PROC_ARGS;
+      mib[2] = getpid();
+      mib[3] = KERN_PROC_PATHNAME;
+
+      size = sizeof(pathname);
+      ret = sysctl(mib, 4, NULL, &size, NULL, 0);
+      if (ret == -1) {
+        return false;
+      }
+
+      ret = sysctl(mib, 4, pathname, &size, NULL, 0);
+      if (ret == -1 || strlen(pathname) == 0) {
+        return false;
+      }
+
+      *result = FilePath(FilePath::StringType(pathname, size - 1));
+      return true;
 #elif defined(OS_SOLARIS)
       char bin_dir[PATH_MAX + 1];
       if (realpath(getexecname(), bin_dir) == NULL) {
