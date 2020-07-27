$NetBSD$

--- content/common/common_sandbox_support_linux.cc.orig	2020-07-15 18:55:57.000000000 +0000
+++ content/common/common_sandbox_support_linux.cc
@@ -5,6 +5,7 @@
 #include "content/public/common/common_sandbox_support_linux.h"
 
 #include <sys/stat.h>
+#include <unistd.h>
 
 #include <limits>
 #include <memory>
