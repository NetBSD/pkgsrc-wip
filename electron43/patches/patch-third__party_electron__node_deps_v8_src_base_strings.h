$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/deps/v8/src/base/strings.h.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/deps/v8/src/base/strings.h
@@ -8,6 +8,7 @@
 #include "src/base/base-export.h"
 #include "src/base/macros.h"
 #include "src/base/vector.h"
+#include <stdarg.h>
 
 namespace v8 {
 namespace base {
