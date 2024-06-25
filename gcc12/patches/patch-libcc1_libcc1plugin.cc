$NetBSD$

# Xcode 5.3 build failure

--- libcc1/libcc1plugin.cc.orig	2023-05-08 12:14:41.793192278 +0000
+++ libcc1/libcc1plugin.cc
@@ -32,6 +32,9 @@
 #undef PACKAGE_VERSION
 
 #define INCLUDE_MEMORY
+#ifdef __APPLE__	// Xcode 5.3 build failure
+#define INCLUDE_VECTOR
+#endif
 #include "gcc-plugin.h"
 #include "system.h"
 #include "coretypes.h"
@@ -69,7 +72,9 @@
 #include "gcc-c-interface.h"
 #include "context.hh"
 
+#ifndef __APPLE__	// Xcode 5.3 build failure
 #include <vector>
+#endif
 
 using namespace cc1_plugin;
 
