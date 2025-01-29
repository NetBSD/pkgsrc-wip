$NetBSD$

pkgsrc cxxopts include path adjusted

--- kernel/driver.cc.orig	2025-01-29 17:09:04.808014166 +0000
+++ kernel/driver.cc
@@ -20,7 +20,7 @@
 #include "kernel/yosys.h"
 #include "kernel/hashlib.h"
 #include "libs/sha1/sha1.h"
-#include "libs/cxxopts/include/cxxopts.hpp"
+#include "cxxopts.hpp"
 #include <iostream>
 
 #ifdef YOSYS_ENABLE_READLINE
