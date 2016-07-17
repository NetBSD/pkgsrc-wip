$NetBSD$

--- base/process/memory.h.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/process/memory.h
@@ -6,6 +6,7 @@
 #define BASE_PROCESS_MEMORY_H_
 
 #include <stddef.h>
+#include <stdlib.h>
 
 #include "base/base_export.h"
 #include "base/process/process_handle.h"
