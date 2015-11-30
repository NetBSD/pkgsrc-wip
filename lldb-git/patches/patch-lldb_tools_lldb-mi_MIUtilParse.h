$NetBSD$

--- lldb/tools/lldb-mi/MIUtilParse.h.orig	2015-11-18 04:51:19.000000000 +0000
+++ lldb/tools/lldb-mi/MIUtilParse.h
@@ -9,8 +9,7 @@
  
 #pragma once
  
-// Third party headers:
-#include "../lib/Support/regex_impl.h"
+#include "lldb/Utility/regex_impl.h"
 
 // In-house headers:
 #include "MIUtilString.h"
