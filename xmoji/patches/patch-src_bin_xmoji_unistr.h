$NetBSD$

--- src/bin/xmoji/unistr.h.orig	2024-08-02 06:42:32.000000000 +0000
+++ src/bin/xmoji/unistr.h
@@ -4,7 +4,11 @@
 #include "macros.h"
 
 #include <poser/decl.h>
-#include <uchar.h>
+#include <stddef.h>
+#include <stdint.h>
+#ifndef char32_t
+#define char32_t uint32_t
+#endif
 
 C_CLASS_DECL(PSC_List);
 
