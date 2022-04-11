$NetBSD$

sysinfo() is used only on FreeBSD and Linux.

--- Source/bmalloc/bmalloc/AvailableMemory.cpp.orig	2022-02-23 08:59:06.000000000 +0000
+++ Source/bmalloc/bmalloc/AvailableMemory.cpp
@@ -44,15 +44,16 @@
 #import <mach/mach_error.h>
 #import <math.h>
 #elif BOS(UNIX)
-#include <sys/sysinfo.h>
 #if BOS(LINUX)
 #include <algorithm>
 #include <fcntl.h>
+#include <sys/sysinfo.h>
 #elif BOS(FREEBSD)
 #include "VMAllocate.h"
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #include <sys/user.h>
+#include <sys/sysinfo.h>
 #endif
 #include <unistd.h>
 #endif
