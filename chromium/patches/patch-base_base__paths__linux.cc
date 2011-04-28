$NetBSD: patch-base_base__paths__linux.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/base_paths_linux.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/base_paths_linux.cc
@@ -5,7 +5,7 @@
 #include "base/base_paths.h"
 
 #include <unistd.h>
-#if defined(OS_FREEBSD)
+#if defined(OS_BSD)
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #endif
@@ -21,7 +21,7 @@
 
 namespace base {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_NETBSD)
 const char kSelfExe[] = "/proc/self/exe";
 #elif defined(OS_SOLARIS)
 const char kSelfExe[] = getexecname();
@@ -36,7 +36,7 @@ bool PathProviderPosix(int key, FilePath
   switch (key) {
     case base::FILE_EXE:
     case base::FILE_MODULE: {  // TODO(evanm): is this correct?
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_NETBSD)
       FilePath bin_dir;
       if (!file_util::ReadSymbolicLink(FilePath(kSelfExe), &bin_dir)) {
         NOTREACHED() << "Unable to resolve " << kSelfExe << ".";
@@ -44,7 +44,7 @@ bool PathProviderPosix(int key, FilePath
       }
       *result = bin_dir;
       return true;
-#elif defined(OS_FREEBSD)
+#elif defined(OS_FREEBSD) || defined(OS_DRAGONFLY)
       int name[] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
       char bin_dir[PATH_MAX + 1];
       size_t length = sizeof(bin_dir);
@@ -56,6 +56,9 @@ bool PathProviderPosix(int key, FilePath
       bin_dir[strlen(bin_dir)] = 0;
       *result = FilePath(bin_dir);
       return true;
+#elif defined(OS_OPENBSD)
+      *result = FilePath("/usr/local/share/chromium/chrome");
+      return true;
 #endif
     }
     case base::DIR_SOURCE_ROOT: {
