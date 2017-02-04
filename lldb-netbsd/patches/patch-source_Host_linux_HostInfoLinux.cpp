$NetBSD$

--- source/Host/linux/HostInfoLinux.cpp.orig	2016-12-17 10:30:35.000000000 +0000
+++ source/Host/linux/HostInfoLinux.cpp
@@ -10,6 +10,8 @@
 #include "lldb/Host/linux/HostInfoLinux.h"
 #include "lldb/Core/Log.h"
 
+#include "llvm/Support/Threading.h"
+
 #include <limits.h>
 #include <stdio.h>
 #include <string.h>
