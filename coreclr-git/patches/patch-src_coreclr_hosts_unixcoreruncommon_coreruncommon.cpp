$NetBSD$

--- src/coreclr/hosts/unixcoreruncommon/coreruncommon.cpp.orig	2016-04-08 23:29:23.000000000 +0000
+++ src/coreclr/hosts/unixcoreruncommon/coreruncommon.cpp
@@ -16,6 +16,7 @@
 #include <string>
 #include <string.h>
 #include <sys/stat.h>
+#include <sys/sysctl.h>
 #include "coreruncommon.h"
 #include "coreclrhost.h"
 #include <unistd.h>
@@ -45,7 +46,7 @@ bool GetEntrypointExecutableAbsolutePath
 
     // Get path to the executable for the current process using
     // platform specific means.
-#if defined(__linux__)
+#if defined(__linux__) || (defined(__NetBSD__) && !defined(KERN_PROC_PATHNAME))
     // On Linux, fetch the entry point EXE absolute path, inclusive of filename.
     char exe[PATH_MAX];
     ssize_t res = readlink(symlinkEntrypointExecutable, exe, PATH_MAX - 1);
@@ -75,6 +76,20 @@ bool GetEntrypointExecutableAbsolutePath
             result = true;
         }
     }
+#elif defined(__NetBSD__) && defined(KERN_PROC_PATHNAME)
+    static const int name[] = {
+        CTL_KERN, KERN_PROC_ARGS, -1, KERN_PROC_PATHNAME,
+    };
+    char path[MAXPATHLEN];
+    size_t len;
+
+    len = sizeof(path);
+    if (sysctl(name, __arraycount(name), path, &len, NULL, 0) != -1) {
+        entrypointExecutable.assign(path);
+        result = true;
+    } else {
+        result = false;
+    }
 #else
     // On non-Mac OS, return the symlink that will be resolved by GetAbsolutePath
     // to fetch the entrypoint EXE absolute path, inclusive of filename.
