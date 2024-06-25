$NetBSD$

# Xcode 5.3 build failure

--- libcc1/libcp1plugin.cc.orig	2023-05-08 12:14:41.793192278 +0000
+++ libcc1/libcp1plugin.cc
@@ -33,6 +33,9 @@
 #undef PACKAGE_VERSION
 
 #define INCLUDE_MEMORY
+#ifdef __APPLE__	// Xcode 5.3 build failure
+#define INCLUDE_VECTOR
+#endif
 #include "gcc-plugin.h"
 #include "system.h"
 #include "coretypes.h"
@@ -71,7 +74,9 @@
 #include "rpc.hh"
 #include "context.hh"
 
+#ifndef __APPLE__	// Xcode 5.3 build failure
 #include <vector>
+#endif
 
 using namespace cc1_plugin;
 
