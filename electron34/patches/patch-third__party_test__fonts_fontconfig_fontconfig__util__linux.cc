$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/test_fonts/fontconfig/fontconfig_util_linux.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/test_fonts/fontconfig/fontconfig_util_linux.cc
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include "build/build_config.h"
+
 #include "third_party/test_fonts/fontconfig/fontconfig_util_linux.h"
 
 #include <fontconfig/fontconfig.h>
@@ -16,11 +18,15 @@
 namespace test_fonts {
 
 std::string GetSysrootDir() {
+#if BUILDFLAG(IS_BSD)
+  return std::string(".");
+#else
   char buf[PATH_MAX + 1];
   auto count = readlink("/proc/self/exe", buf, PATH_MAX);
   assert(count > 0);
   buf[count] = '\0';
   return dirname(buf);
+#endif
 }
 
 void SetUpFontconfig() {
