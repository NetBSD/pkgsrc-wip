$NetBSD$

pkgsrc cxxopts include path adjusted

--- kernel/driver.cc.orig	2024-11-19 15:16:25.907765578 +0000
+++ kernel/driver.cc
@@ -19,7 +19,7 @@
 
 #include "kernel/yosys.h"
 #include "libs/sha1/sha1.h"
-#include "libs/cxxopts/include/cxxopts.hpp"
+#include "cxxopts.hpp"
 #include <iostream>
 
 #ifdef YOSYS_ENABLE_READLINE
