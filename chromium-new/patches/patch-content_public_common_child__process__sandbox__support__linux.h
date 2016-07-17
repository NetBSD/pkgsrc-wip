$NetBSD$

--- content/public/common/child_process_sandbox_support_linux.h.orig	2016-06-24 01:02:21.000000000 +0000
+++ content/public/common/child_process_sandbox_support_linux.h
@@ -8,6 +8,7 @@
 #include <stddef.h>
 #include <stdint.h>
 #include <string>
+#include <sys/types.h>
 
 #include "content/common/content_export.h"
 #include "ppapi/c/trusted/ppb_browser_font_trusted.h"
