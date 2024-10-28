$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/posix/file_descriptor_shuffle.h.orig	2024-10-26 06:59:45.366711600 +0000
+++ base/posix/file_descriptor_shuffle.h
@@ -26,6 +26,8 @@
 #include "base/base_export.h"
 #include "base/compiler_specific.h"
 
+#undef close
+
 namespace base {
 
 // A Delegate which performs the actions required to perform an injective
