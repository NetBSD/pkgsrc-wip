$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/renderer/bindings/argument_spec.cc.orig	2024-10-26 07:00:17.559269200 +0000
+++ extensions/renderer/bindings/argument_spec.cc
@@ -18,6 +18,8 @@
 #include "gin/data_object_builder.h"
 #include "gin/dictionary.h"
 
+#include <cmath>
+
 namespace extensions {
 
 namespace {
