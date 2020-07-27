$NetBSD$

* Use pci.h from pkgsrc pciutils.

--- third_party/angle/src/gpu_info_util/SystemInfo_libpci.cpp.orig	2020-07-15 19:01:32.000000000 +0000
+++ third_party/angle/src/gpu_info_util/SystemInfo_libpci.cpp
@@ -9,7 +9,7 @@
 #include "gpu_info_util/SystemInfo_internal.h"
 
 #include <dlfcn.h>
-#include <pci/pci.h>
+#include <pciutils/pci.h>
 #include <unistd.h>
 
 #include "common/angleutils.h"
