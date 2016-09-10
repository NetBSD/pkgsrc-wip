$NetBSD$

--- tools/lldb-mi/MIUtilParse.h.orig	2016-09-10 17:36:23.000000000 +0000
+++ tools/lldb-mi/MIUtilParse.h
@@ -10,7 +10,7 @@
 #pragma once
 
 // Third party headers:
-#include "../lib/Support/regex_impl.h"
+#include "lldb/Utility/regex_impl.h"
 
 // In-house headers:
 #include "MIUtilString.h"
