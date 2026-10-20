$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- third_party/electron_node/src/compile_cache.cc.orig	2026-10-13 14:09:48.000000000 +0000
+++ third_party/electron_node/src/compile_cache.cc
@@ -1,5 +1,6 @@
 #include "compile_cache.h"
 #include <string>
+#include <unistd.h>
 #include "debug_utils-inl.h"
 #include "env-inl.h"
 #include "node_file.h"
