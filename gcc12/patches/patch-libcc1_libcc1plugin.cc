$NetBSD$

--- libcc1/libcc1plugin.cc.orig	2024-05-14 07:06:13.359508199 +0000
+++ libcc1/libcc1plugin.cc
@@ -32,6 +32,7 @@
 #undef PACKAGE_VERSION
 
 #define INCLUDE_MEMORY
+#define INCLUDE_VECTOR
 #include "gcc-plugin.h"
 #include "system.h"
 #include "coretypes.h"
@@ -69,8 +70,6 @@
 #include "gcc-c-interface.h"
 #include "context.hh"
 
-#include <vector>
-
 using namespace cc1_plugin;
 
 
