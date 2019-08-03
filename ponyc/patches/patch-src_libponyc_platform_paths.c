$NetBSD$

Add NetBSD way of finding current executable path

--- src/libponyc/platform/paths.c.orig	2019-07-27 10:37:45.000000000 +0000
+++ src/libponyc/platform/paths.c
@@ -265,6 +265,14 @@ bool get_compiler_exe_path(char* output_
     }
     free(tofree);
   }
+#elif defined PLATFORM_IS_NETBSD
+  const int mib[] = {
+    CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME,
+  };
+
+  size_t len = MAXPATHLEN;
+  int r = sysctl(mib, 4, output_path, &len, NULL, 0);
+  success = (r == 0);
 #elif defined PLATFORM_IS_BSD
   int mib[4];
   mib[0] = CTL_KERN;
