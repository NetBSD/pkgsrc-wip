$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/test_fonts/fontconfig/fontconfig_util_linux.cc.orig	2024-07-24 02:45:07.771797200 +0000
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
