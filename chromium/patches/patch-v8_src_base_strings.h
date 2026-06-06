$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/strings.h.orig	2026-05-28 23:24:11.000000000 +0000
+++ v8/src/base/strings.h
@@ -9,6 +9,8 @@
 #include "src/base/macros.h"
 #include "src/base/vector.h"
 
+#include <cstdarg>
+
 namespace v8 {
 namespace base {
 
