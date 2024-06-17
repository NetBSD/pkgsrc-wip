$NetBSD$

--- libcc1/libcp1plugin.cc.orig	2024-05-14 07:05:14.590094938 +0000
+++ libcc1/libcp1plugin.cc
@@ -33,6 +33,7 @@
 #undef PACKAGE_VERSION
 
 #define INCLUDE_MEMORY
+#define INCLUDE_VECTOR
 #include "gcc-plugin.h"
 #include "system.h"
 #include "coretypes.h"
@@ -71,8 +72,6 @@
 #include "rpc.hh"
 #include "context.hh"
 
-#include <vector>
-
 using namespace cc1_plugin;
 
 
